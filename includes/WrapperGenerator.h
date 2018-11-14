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

    static void generate_virtual(CNIEnv* env, Method* meth) {

        std::string name = "libwrapper_" + meth->module_name +  "_" + meth->class_name + "_" +  meth->getName() + meth->get_rtype();
        std::string filename = name + ".cpp";
        char* homepath = getenv("HOME");

        std::ofstream outputFile( std::string(homepath) + "/colibri-VM/native/" + meth->module_name +"/" + meth->class_name + filename);


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

        outputFile << std::string("extern \"C\" void   ") + std::string("wrapper_") + meth->module_name + "_" + meth->class_name + "_" + meth->getName() + meth->get_rtype() + "(CNIEnv* env, vs_stack<symbol> *stk){\n";


        std::string type;
        type = "Object";

        outputFile << "\t" + type +"* par" + std::to_string(0) + " = " + "("+ type +"*) " + "stk->pop();\n";

        for (int i = 1; i < meth->num_params; i++) {



            outputFile << "\t" + type  +"* par" + std::to_string(i) + " = " + "("+ type +"*) " + "stk->pop();\n";

        }

        outputFile << "\n";
        outputFile << "\t//Handle\n";




        for (int i = 0; i < meth->num_params; i++) {


            if (meth->args[i] == "R")
                type = "c_object";
            else if (meth->args[i] == "I")
                type = "c_int";
            else if (meth->args[i] == "D")
                type = "c_double";
            else if (meth->args[i] == "S")
                type = "c_string";
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
        else if (type == "S")
            type = "c_string";
        else if (type == "D")
            type = "c_double";
        else if (type == "F")
            type = "c_float";
        else if (type == "B")
            type = "c_bool";
        else if (type == "V")
            type = "c_void";


        if(type != "void")
             outputFile << "\t" + type + " ret = ";

        outputFile << "\t" + meth->module_name + "_" + meth->getName() + "(env ";

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

        const std::string ex_command = "g++ -fPIC -I  ~/colibri-VM/includes -o ~/colibri-VM/native/" + meth->module_name + "/" + meth->class_name + "/" + "libwrapper_" + meth->module_name + "_" + meth->class_name + "_" + meth->getName() + meth->get_rtype() + ".o" + " -c " + "~/colibri-VM/native/" + meth->module_name + "/" + meth->class_name + "/" + "libwrapper_" + meth->module_name + "_" + meth->class_name + "_" + meth->getName() + meth->get_rtype() + ".cpp";
        //std::cout << ex_command.c_str() << endl;
        system(ex_command.c_str());
        system(("g++ -shared ~/colibri-VM/src/share/coral/lang/Field.cpp "\
                "~/colibri-VM/src/share/coral/lang/Class.cpp "\
                "~/colibri-VM/src/share/coral/lang/Literal.cpp "\
                "~/colibri-VM/src/share/vm/cni.cpp "\
                "~/colibri-VM/src/share/coral/lang/Integer.cpp "
                "~/colibri-VM/src/share/coral/lang/Data_Type.cpp "\
                "~/colibri-VM/src/share/coral/lang/Numeric.cpp "
                "~/colibri-VM/src/share/coral/lang/Primitive.cpp "
                "~/colibri-VM/src/share/coral/lang/symbol.cpp "\
                "~/colibri-VM/src/share/coral/lang/Object.cpp "\
                "~/colibri-VM/src/share/coral/lang/Int.cpp "
                "~/colibri-VM/src/share/vm/CNIHandlerBlock.cpp "\
                " -I  ~/colibri-VM/includes -fPIC -o ~/colibri-VM/native/" + meth->module_name + "/" + meth->class_name + "/" + "libwrapper_" + meth->module_name + "_" + meth->class_name + "_" + meth->getName() + meth->get_rtype() + ".so " + "~/colibri-VM/native/" + meth->module_name + "/" + meth->class_name + "/" + "libwrapper_" + meth->module_name + "_" +meth->class_name + "_" + meth->getName() + meth->get_rtype() + ".cpp").c_str());
        wrappers.push_back(name);


    }


    static void generate_static(CNIEnv* env, Method* meth) {

        std::string name = "libwrapper_" + meth->module_name + "_" + meth->getName() + meth->get_rtype();
        std::string filename = name + ".cpp";
        char* homepath = getenv("HOME");
        std::ofstream outputFile(std::string(homepath) + "/colibri-VM/native/" + meth->module_name + "/" + filename);


        outputFile << "#include \"cni.h\"\n";
        outputFile << "#include \"vs_stack.h\"\n";
        outputFile << "#include \"CNIHandlerBlock.h\"\n";
        outputFile << "#include \"" + meth->module_name + "_" + meth->getName() + meth->get_rtype() + ".h\"\n";
        outputFile << "\n";
        outputFile << "/*\n";
        outputFile << "Module name: " + meth->module_name + "\n";
        outputFile << "Function name: " + meth->getName() + "\n";
        outputFile << "Return type: " + meth->get_rtype() + "\n";
        outputFile << "\n*/\n";

        outputFile << std::string("extern \"C\" void   ") + std::string("wrapper_") + meth->module_name + "_" + meth->getName() + meth->get_rtype() + "(CNIEnv* env, vs_stack<symbol> *stk){\n";


        for (int i = 0; i < meth->num_params; i++) {

            outputFile << "\t Object* par" + std::to_string(i) + " = " + "(Object*) " + "stk->pop();\n";
        }

        outputFile << "\n";
        outputFile << "\t//Handle\n";


        std::string type;

        for (int i = 0; i < meth->num_params; i++) {


            if (meth->args[i] == "R")
                type = "c_object";
            else if (meth->args[i] == "I")
                type = "c_int";
            else if (meth->args[i] == "S")
                type = "c_string";
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
        else if (type == "S")
            type = "c_string";
        else if (type == "F")
            type = "c_float";
        else if (type == "B")
            type = "c_bool";
        else if (type == "V")
            type = "c_void";


        if(type != "void")
             outputFile << "\t" + type + " ret = ";

        outputFile <<  meth->module_name + "_" + meth->getName() + "(env ";

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

        const std::string ex_command = "g++ -fPIC -I  ~/colibri-VM/includes -o ~/colibri-VM/native/" + meth->module_name + "/" + "libwrapper_" + meth->module_name + "_" + meth->getName() + meth->get_rtype() + ".o" + " -c " + "~/colibri-VM/native/" + meth->module_name + "/" + "libwrapper_" + meth->module_name + "_" + meth->getName() + meth->get_rtype() + ".cpp";
        //std::cout << ex_command.c_str() << endl;
        system(ex_command.c_str());
        system(("g++ -shared ~/colibri-VM/src/share/coral/lang/Field.cpp "\
                "~/colibri-VM/src/share/coral/lang/Class.cpp "\
                "~/colibri-VM/src/share/coral/lang/Literal.cpp "\
                "~/colibri-VM/src/share/vm/cni.cpp "\
                "~/colibri-VM/src/share/coral/lang/Integer.cpp "
                "~/colibri-VM/src/share/coral/lang/Data_Type.cpp "\
                "~/colibri-VM/src/share/coral/lang/Numeric.cpp "
                "~/colibri-VM/src/share/coral/lang/Primitive.cpp "
                "~/colibri-VM/src/share/coral/lang/symbol.cpp "\
                "~/colibri-VM/src/share/coral/lang/Object.cpp "\
                "~/colibri-VM/src/share/coral/lang/Int.cpp "
                "~/colibri-VM/src/share/vm/CNIHandlerBlock.cpp "\
                "~/colibri-VM/src/share/coral/lang/System.cpp "\
                "~/colibri-VM/src/share/vm/hash_table.cpp "\
                "~/colibri-VM/src/share/coral/lang/Library.cpp "\
                "~/colibri-VM/src/share/vm/CallableNativeFunction.cpp "
                " -I  ~/colibri-VM/includes -fPIC -o ~/colibri-VM/native/" + meth->module_name + "/" + "libwrapper_" + meth->module_name + "_" + meth->getName() + meth->get_rtype() + ".so " + "~/colibri-VM/native/" + meth->module_name + "/" + "libwrapper_" + (meth->module_name) + "_" + meth->getName() + meth->get_rtype() + ".cpp").c_str());
        wrappers.push_back(name);


    }

    static void clean(std::string spec_path){

        int size = wrappers.size();
        std::string name;

        for(int i=0; i < size ; i++){

            name = wrappers[i];

            system(("rm " + std::string(getenv("HOME")) + "/colibri-VM/native/" + spec_path + "/" + name + ".cpp" + " &>/dev/null").c_str());
            system(("rm " + std::string(getenv("HOME")) + "/colibri-VM/native/" + spec_path + "/" + name + ".o" + " &>/dev/null").c_str());
            //system(("rm " + name + ".so").c_str());
        }

    }
private:
    WrapperGenerator();
    WrapperGenerator(const WrapperGenerator& orig);

};
std::vector<std::string> WrapperGenerator::wrappers;

#endif /* WRAPPERGENERATOR_H */
