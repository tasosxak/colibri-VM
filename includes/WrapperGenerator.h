/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WrapperGenerator.h
 * Author: tasosxak
 *
 * Created on February 15, 2018, 1:00 PM
 */


#ifndef WRAPPERGENERATOR_H
#define WRAPPERGENERATOR_H

#include <string>
#include <iostream>
#include "cni.h"
#include "Method.h"
#include "symbol.h"
#include "vs_stack.h"
using namespace std;

class WrapperGenerator {
public:

    static std::vector<std::string> wrappers;
    
    virtual ~WrapperGenerator();

    static void generate(CNIEnv* env, Method* meth, vs_stack<symbol>* st) {

        std::string name = "libwrapper_" + (meth->getClass())->getName() + "_" + meth->getName() + meth->get_rtype();
        std::string filename = name + ".cpp";

        std::ofstream outputFile(filename);


        outputFile << "#include \"cni.h\"\n";
        outputFile << "#include \"vs_stack.h\"\n";
        outputFile << "#include \"CNIHandlerBlock.h\"\n";
        outputFile << "#include \"" + (meth->getClass())->getName() + ".h\"\n";
        outputFile << "\n";
        outputFile << "/*\n";
        outputFile << "Class name: " + (meth->getClass())->getName() + "\n";
        outputFile << "Method name: " + meth->getName() + "\n";
        outputFile << "Return type: " + meth->get_rtype() + "\n";
        outputFile << "\n*/\n";

        outputFile << std::string("extern \"C\" void   ") + std::string("wrapper_") + meth->getClass()->getName() + "_" + meth->getName() + meth->get_rtype() + "(CNIEnv* env, vs_stack<symbol> *stk){\n";


        for (int i = 0; i < meth->num_params; i++) {

            outputFile << "\t" + meth->getClass()->getName() +"* par" + std::to_string(i) + " = " + "("+ meth->getClass()->getName() +"*) " + "stk->pop();\n";
        }

        outputFile << "\n";
        outputFile << "\t//Handle\n";


        std::string type;

        for (int i = 0; i < meth->num_params; i++) {


            if (meth->args[i] == "R")
                type = "c_object";
            else if (meth->args[i] == "I")
                type = "c_int";
            else if (meth->args[i] == "D")
                type = "c_double";
            else if (meth->args[i] == "F")
                type = "c_float";
            else if (meth->args[i] == "B")
                type = "c_bool";

            outputFile << "\t" + type + " cpar" + std::to_string(i) + " = new _" + type + "();" + "\n";
            outputFile << "\tCNIHandlerBlock::addoop(cpar" + std::to_string(i) + " ,par" + std::to_string(i) + ");\n";
        }

        outputFile << "\n";
        outputFile << "\t//Return\n";

        type = meth->get_rtype();

        if (type == "R")
            type = "c_object";
        else if (type == "I")
            type = "c_int";
        else if (type == "D")
            type = "c_double";
        else if (type == "F")
            type = "c_float";
        else if (type == "B")
            type = "c_bool";
        else
            type = "void";


        if(type != "void")
             outputFile << "\t" + type + " ret = ";
                
        outputFile << "par0->" + meth->getName() + "(env ";

        for (int i = 0; i < meth->num_params; i++) {

            outputFile << ",cpar" + std::to_string(i) + " ";

        }

        outputFile << ");\n";
        if (type != "void") {
            //Push
            outputFile << "\tstk->push(CNIHandlerBlock::resolve(ret));\n";


        }
        outputFile << "\n}";

        outputFile.close();

        const std::string ex_command = "g++ -fPIC -I includes " + filename + " -c " + "libwrapper_" + (meth->getClass())->getName() + "_" + meth->getName() + meth->get_rtype() + ".cpp";
        std::cout << ex_command.c_str() << endl;
        system(ex_command.c_str());
        system(("g++ -shared src/share/coral/lang/Field.cpp "\
                " src/share/coral/lang/Class.cpp "\
                "src/share/coral/lang/Literal.cpp "\
                "src/share/vm/cni.cpp "\
                "src/share/coral/lang/Integer.cpp "
                "src/share/coral/lang/Data_Type.cpp "\
                "src/share/coral/lang/Numeric.cpp "
                "src/share/coral/lang/Primitive.cpp "
                "src/share/coral/lang/symbol.cpp "\
                "src/share/coral/lang/Object.cpp "\
                "src/share/coral/lang/Int.cpp "
                "src/share/vm/CNIHandlerBlock.cpp "\
                " -I includes -fPIC -o libwrapper_" + (meth->getClass())->getName() + "_" + meth->getName() + meth->get_rtype() + ".so " + "libwrapper_" + (meth->getClass())->getName() + "_" + meth->getName() + meth->get_rtype() + ".cpp").c_str());
        wrappers.push_back(name);
        

    }
    
    static void clean(){
       /*
        int size = wrappers.size();
        std::string name;
        
        for(int i=0; i < size ; i++){
            
            name = wrappers[i];
            
            system(("rm " + name + ".cpp").c_str());
            system(("rm " + name + ".o").c_str());
            system(("rm " + name + ".so").c_str());
        }
        */
    }
private:
    WrapperGenerator();
    WrapperGenerator(const WrapperGenerator& orig);

};
std::vector<std::string> WrapperGenerator::wrappers;

#endif /* WRAPPERGENERATOR_H */

