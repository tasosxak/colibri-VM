/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CVM.cpp
 * Author: tasosxak
 * 
 * Created on February 11, 2018, 6:37 PM
 */

#include "CVM.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <regex>
#include <dlfcn.h>
#include <unistd.h>

/* Built-in classes */

#include "symbol.h"
#include "Integer.h"
#include "Method.h"
#include "Object.h"
#include "Field.h"
#include "Int.h"
#include "Double.h"
#include "Float.h"
#include "Literal.h"
#include "vs_stack.h"
#include "Code.h"
#include "symbol.h"
#include "hash_table.h"
#include "Class.h"
#include "Reference.h"
#include "Array.h"
#include "IntArray.h"
#include "ArrayReference.h"
#include "cni.h"
#include "CNIHandlerBlock.h"
#include "Native_Method_Signature.h"
#include "WrapperGenerator.h"
#include "System.h"
#include "Error.h"
#include "Exception.h"
#include "Block.h"
#include "Package.h"
#include "Frame.h"

/*Debug options*/

#define COMPILATION 0
#define EXECUTION 0
#define LOAD 0

CVM::CVM(std::string bytecodefile) {

    this->bytecodefile = bytecodefile;
}

int CVM::start() {

    this->execute();

    return 0;
}

void accessor_resolver(Acc_type& acc, std::string accname) {

    if (accname == "public")
        acc = PUBLIC_ACC;
    else if (accname == "protected")
        acc = PROTECTED_ACC;
    else if (accname == "private")
        acc = PRIVATE_ACC;

    return;
}

void modifier_resolver(Mod_type& mod, std::string modname) {

    if (modname == "default")
        mod = DEFAULT_MOD;
    else if (modname == "abstract")
        mod = ABSTRACT_MOD;
    else if (modname == "final")
        mod = FINAL_MOD;

    return;
}

void CVM::method_arg_analyzer(Method* meth, const std::string& args) {

    int num_params = 0;
    
    
    stringstream stream(args);
    std::string arg;
   
    
    while (getline(stream, arg, ',')) {
        
        std::vector<std::string> tokens;
      
        ++num_params;
        
        
        if (arg.length()== 0)
            break;
        
        split(arg, tokens);
        
        (meth->args).push_back(std::string(tokens[0]));
        (meth->args_names).push_back(std::string(tokens[1]));
        
    }
    
    meth->num_params = num_params;
    

}

template <class Container>
void CVM::split(const std::string& str, Container& cont) {
    std::istringstream iss(str);
    std::copy(std::istream_iterator<std::string>(iss),
            std::istream_iterator<std::string>(),
            std::back_inserter(cont));
}

std::string trim(const std::string &s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && isspace(*it))
        it++;

    std::string::const_reverse_iterator rit = s.rbegin();
    while (rit.base() != it && isspace(*rit))
        rit++;

    return std::string(it, rit.base());
}

std::vector<std::string> dot_splitter(std::string path) {

    istringstream iss(path);
    std::vector<std::string> tokens;
    std::string token;

    while (std::getline(iss, token, '.')) {
        if (!token.empty())
            tokens.push_back(token);
    }

    return tokens;
}

/*
Loader loads the program, push the code into the stack
 */
Package* CVM::load(string filename) {


    ifstream bytecode(filename);
    std::smatch tokens;
    string line;
    Package* pack = new Package(filename.substr(0, filename.size() - 4));

#if LOAD
    cout << "Loading " + pack->getName() + "..." << endl;
#endif

    while (getline(bytecode, line)) {

        line = trim(line);
#if LOAD
        cout << "CODE: " << line << endl;
#endif

        /*if (std::regex_search(line, tokens, std::regex("use NAME=(.*)"))) {

            // eoc++;
            Loader(std::string(tokens[1]) + ".cex");

            continue;

        }*/

        pack->cn.__add__(new Code(line));
        ++eoc;

    }

#if LOAD
    cout << "EOC : " << eoc << endl;
#endif

    return pack;
}

/*

Compiler compiles the program

 */
Package* CVM::compile(Package* package) {


    //int main_location;
    string linecode;
    Code* clinecode;
    std::smatch tokens;
    vs_stack<symbol> PKG_STACK;

    hash_table* cur_sb;
    Class* cur_class;
    Method* cur_func;
    Package* cur_pkg;
    int cp = 0;
    bool in_class = false;
    bool in_func = false;

    PKG_STACK.push(package);

    while (PKG_STACK.esp() != -1) {

        cur_pkg = (Package*) PKG_STACK.see(PKG_STACK.esp()); //current package
        cur_sb = cur_pkg->mht; //current symbol table
        
        
        while (cur_pkg->cn.__has_next__()) {

            clinecode = ((Code *) cur_pkg->cn.__next__()); //get code object
            linecode = clinecode->getCode(); //get code object as string

#if COMPILATION
            cout << "COMPILING: " << linecode << endl;
#endif

            /*
             * The line of main function call
             */
            /*if (std::regex_search(linecode, tokens, std::regex("invoke_static (.*)[.](main)"))) {

                main_location = ic;

            }*/
            /*
             * Comments 
             * Example: //this is a comment
             */
            if (std::regex_search(linecode, tokens, std::regex("#.*"))) {
                //++ic; 
                continue;
            }
                /*
                 * Class Definition
                 * kinds: public, abstract, final
                 */
            else if (std::regex_search(linecode, tokens, std::regex("(public|private|protected) (default|abstract|final) class (.*) extends (.*):"))) // ==== Class Definition
            {

                Acc_type accessor;
                Mod_type modifier;

                in_class = true;

                // symbol* _class = new symbol(tokens[1]);
                // _class->setLine(ic);
                // cur_hs->add(_class);

                //---- CLASS INITIALIZATION ---- //
                Class* superclass = NULL;

                if (tokens[4] != "NULL") {

                    superclass = (Class*) cur_sb->lookfor(tokens[4]);

                    if (superclass == NULL) {

                        cout << "Undefined class";
                        exit(1);

                    }

                    if (superclass->get_mod() == FINAL_MOD) {

                        cout << "final class";
                        exit(1);

                    }
                }

                accessor_resolver(accessor, tokens[1]);

                modifier_resolver(modifier, tokens[2]);



                cur_class = new Class(tokens[3], accessor, modifier, superclass);
                //cur_class->setLine(cur_pkg->index);
                cur_class->module_name = cur_pkg->getName();
                cur_class->package = cur_pkg;
                cur_class->mht = new hash_table();

                //---- ADD CLASS IN CURRENT SYMBOL TABLE AND CLASS POOL----//
                //cur_hs->add(cur_class);
                //class_defs.add(cur_class);

                //---- CHANGE CURRENT SYMBOL TABLE ----//
                //cur_hs = cur_class->mht;

                //PKG_STACK.push(cur_class);
                cur_sb->add(cur_class);
                cur_sb = cur_class->mht;


            }
                /*
                 * End of current class definition
                 */
            else if (std::regex_match(linecode, std::regex("end_class"))) {
                in_class = false;
                cur_sb = PKG_STACK.see(PKG_STACK.esp())->mht;
                cur_class = NULL;



            }
            else if (std::regex_match(linecode, std::regex("end_func"))) {
                in_func = false;
                cur_func = NULL;
                cp = -1;

            }                /*
             * Method Definition
             * accesors: private, public
             * implementions: native,virtual
             * return types: I(nteger),B(oolean),D(ouble),F(loat),R(eference)

             */
            else if (std::regex_search(linecode, tokens, std::regex("(public|private|protected) (native|virtual) (default|abstract|final) (.*) (.*)[(](.*)[)];"))) {

                Acc_type accessor;
                Mod_type modifier;

                in_func = true;

                accessor_resolver(accessor, tokens[1]);

                modifier_resolver(modifier, tokens[3]);



                //---- METHOD INITIALIZATION ---- //
                Method* method = new Method(tokens[5], accessor, modifier, tokens[4]);

                //method->setLine(cur_pkg->index);
                method->setClass(cur_class);
                method->module_name = cur_class->module_name;
                method->package = cur_pkg;
                method->class_name = cur_class->getName();

                method_arg_analyzer(method, tokens[6]);


                //cur_hs->add(method);

                cur_sb->add(method);
                cur_func = method;

                if (tokens[2] == "native") {

                    method->native = true;
                    struct CNIEnv* env;
                    if (access((std::string(getenv("HOME")) + "/colibri/native/" + method->module_name + "/" + method->class_name + "/" + "libwrapper_" + method->module_name + "_" + method->class_name + "_" + method->getName() + method->get_rtype() + ".so").c_str(), F_OK) == -1) {
                        WrapperGenerator::generate_virtual(env, method);
                        WrapperGenerator::clean(method->module_name + "/" + method->class_name);
                    }


                }

            }
                /*
                 * Function Definition
                 * implementions: native,virtual
                 * return types: I(nteger),B(oolean),D(ouble),F(loat),R(eference)

                 */
            else if (std::regex_search(linecode, tokens, std::regex("(native|virtual) (.*) (.*)[(](.*)[)];"))) {

                in_func = true;

                //---- FUNCTION INITIALIZATION ---//
                Method* func = new Method(tokens[3], PUBLIC_ACC, DEFAULT_MOD, tokens[2]);
                //func->setLine(ic);
                func->module_name = cur_pkg->getName();
                func->package = cur_pkg;
                method_arg_analyzer(func, tokens[4]);

                //cur_hs->add(func);
                cur_sb->add(func);
                cur_func = func;

                if (tokens[1] == "native") {

                    func->native = true;
                    struct CNIEnv* env;

                    if (access((std::string(getenv("HOME")) + "/colibri/native/" + func->module_name + "/" + "libwrapper_" + func->module_name + "_" + func->getName() + func->get_rtype() + ".so").c_str(), F_OK) == -1) {
                        WrapperGenerator::generate_static(env, func);
                        WrapperGenerator::clean(func->module_name);
                    }

                }

            }
                /**
                 * Label Definition
                 */
                else if (std::regex_search(linecode, tokens, std::regex("label NAME=(.*):")))
                {
                // cout<<"LABEL :"<<tokens[1]<< " " << ic <<endl;

                //---- LABEL INITIALIZATION FOR LOOPS,IFS ---//
                symbol* label = new symbol(tokens[1]);
                
                label->setLine(cp++);
                cur_func->mht->add(label);
                cur_func->cn.__add__(clinecode);
                
                }
                /*
                 * Try Definition
                 */
                //else if (std::regex_search(linecode, tokens, std::regex("(try .*) :")))
                //{
                // cout<<"LABEL :"<<tokens[1]<< " " << ic <<endl;

                //---- TRY INITIALIZATION ---//
                //symbol* label = new symbol(tokens[1]);
                //label->setLine(ic);
                //cur_hs->add(label);
                //}
                /*
                 * Except Definition
                 */
                //else if (std::regex_search(linecode, tokens, std::regex("(except .*) :")))
                //{
                // cout<<"LABEL :"<<tokens[1]<< " " << ic <<endl;

                //---- Except INITIALIZATION ---//
                //symbol* label = new symbol(tokens[1]);
                //label->setLine(ic);
                //cur_hs->add(label);
                // }
                /*
                 * Field Definition
                 * accessors: public,private
                 * types: I(nteger),B(oolean),D(ouble),F(loat),R(eference)

                 */
            else if (std::regex_search(linecode, tokens, std::regex("(public|protected|private) (.*) (.*);"))) {
                Acc_type accessor;

                accessor_resolver(accessor, tokens[1]);

                if (tokens[2] == "I") //=== Integer Field of a class
                {
                    cur_sb->add(new Field(tokens[3], accessor, new Int(0)));

                } else if (tokens[2] == "D") //=== Double Field of a class
                {
                    cur_sb->add(new Field(tokens[3], accessor, new Double(0.0)));

                } else if (tokens[2] == "S") //=== String Field of a class
                {
                    cur_sb->add(new Field(tokens[3], accessor, new Literal("")));
                } else if (tokens[2] == "I[") //=== Array of integers Field of a class
                {
                    cur_sb->add(new Field(tokens[3], accessor, NULL));

                } else //=== Reference Field of a class
                {
                    Class* y;
                    Object* x;

                    y = (Class *) cur_pkg->mht->lookfor(tokens[2]); //Looking for type of reference in current symbol table

                    if (y != NULL) {
                        x = NULL;

                    } else {

                        // Exception(ClassNotFound);
                    }


                    cur_sb->add(new Field(tokens[3], accessor, new Reference(tokens[3], y, x)));

                }

            }
                /*
                 * Variable Definition
                 * types: I(nteger),B(oolean),D(ouble),F(loat),R(eference)

                 */
            else if (std::regex_search(linecode, tokens, std::regex("(.*) (.*) = (.*);"))) //== Variable definition
            {

                if (tokens[1] == "I") {

                    cur_sb->add(new Field(tokens[2], PUBLIC_ACC, new Int(stoi(tokens[3]))));

                } else if (tokens[1] == "D") {

                    cur_sb->add(new Field(tokens[2], PUBLIC_ACC, new Double(stod(tokens[3]))));

                } else if (tokens[1] == "S") {

                    cur_sb->add(new Field(tokens[2], PUBLIC_ACC, new Literal(tokens[3])));

                } else if (tokens[1] == "I[") //=== Array of integers Field of a class
                {
                    cur_sb->add(new Field(tokens[2], PUBLIC_ACC, new IntArray(stoi(tokens[3]),1)));

                } else {

                    Class* y;
                    Object* x;

                    y = (Class *) cur_pkg->mht->lookfor(tokens[1]);

                    if (y != NULL) {

                        if (tokens[3] != "NULL") {
                            x = y->createInstance();
                        } else {
                            x = NULL;
                        }
                    } else {

                        // Exception(ClassNotFound);
                    }


                    cur_sb->add(new Field(tokens[2], PUBLIC_ACC, new Reference(tokens[2], y, x)));

                }
            } else if (std::regex_search(linecode, tokens, std::regex("use NAME=(.*);")) && (!in_func)) {



                Package* new_pkg = compile(load(tokens[1]));
                
                if (new_pkg != NULL) {

                    cur_sb->add(new_pkg);
                   
                }else {
                    
                    std::cout<<"Error: Package "<<tokens[1]<<" not found."<<std::endl;
                }

                //std::cout<<"Loaded:"<<new_pkg->getName()<<std::endl;
                
                
            } else {

                if (cur_func != NULL){
                    
                    cur_func->cn.__add__(clinecode);
                    cp++;
                }
            }

        }

        PKG_STACK.pop();

        //ic++;

    }


    //cout<<"MAIN_CALL: "<<main_location<<endl;
    //ebp = eoc;
    //ic = main_location;

    // cout<<"End compiling..."<<endl;
    return cur_pkg;

}

Frame* CVM::__call__(Method* meth, Reference* params[], Call_type ct) {

    Frame* new_frame = new Frame(meth, params, ct);
    new_frame->push_block();

    CALL_STACK.push(new_frame);

    return CALL_STACK.see(CALL_STACK.esp());

}

Object* CVM::__pkg_id_load__(std::string id) {

    hash_table* cur_sb;
    symbol* symb;
    std::vector<std::string> path;
    bool first_time = true;

    path = dot_splitter(id);
    cur_sb = ((symbol*) this->PKG_STACK.see(this->PKG_STACK.esp()))->mht;

    for (int i = 0; i < path.size(); i++) {
  
        symb = (cur_sb)->lookfor(path[i]);

        if (symb == NULL) {
           
            if ((((Frame*) (CALL_STACK.see(CALL_STACK.esp())))->ct == METHOD) && first_time) {

                cur_sb = ((symbol*) this->PKG_STACK.see(this->PKG_STACK.esp() - 1))->mht;
                first_time = false;
            } else {

                return NULL;
            }

        } else {
           
            cur_sb = symb->mht;
        }

    }

    /*for(int i = this->PKG_STACK->esp(); i>=0;){
        
        ca = (symbol*) this->PKG_STACK->see(this->PKG_STACK->esp());
        sb = (symbol*) cs->mht->lookfor(id);
        if(sb != NULL){
            return (Object*) sb;
        }
        int k = 1;
        while( k<=i && this->PKG_STACK->see(this->PKG_STACK->esp()) == this->PKG_STACK->see(this->PKG_STACK->esp() - k)){
            k++;
        }
        
        i-= k;
        
    }*/

    return (Object*) symb;
}

int CVM::execute() {

    CNIHandlerBlock::init(); // Initialization 
    System::init();
    struct CNIEnv env;
    //Object::RegisterNative(&env);
    //Object * x = new Object();
    //Native_Method_Signature* ll = (Native_Method_Signature*) System::call_native_method("Object","toString");

    // c_string (*string_func)(c_object, ...);
    // c_object (*object_func)(c_object, ...);
    //  c_int (*int_func)(c_object, ...);

    //c_object cobj = new _c_object();
    // CNIHandlerBlock::addoop(cobj,x);
    //bb = (c_string(*)(c_object,...))(ll->get_native_function());

    //cout<<((Literal *)(CNIHandlerBlock::resolve((*bb)(cobj))))->getValue();


    symbol* s, s1, s2, s3;
    string linecode;
    string init_linecode;
    string p, p1, p2, p3, p4;

    //bool method_running = false;
    //bool func_running = false;

    Package* executing_pkg;

    Frame* cf; // call frame


    executing_pkg = compile(load(this->bytecodefile));
    PKG_STACK.push((symbol*) executing_pkg);

#if EXECUTION
    cout << "Start executing..." << endl;
#endif

    // Initial Call
    Method* main_function = (Method*) executing_pkg->mht->lookfor("main");

    Reference * params[0];
    __call__(main_function, params, FUNCTION);



    while (CALL_STACK.esp() != -1) {


        cf = (Frame*) CALL_STACK.see(CALL_STACK.esp());


        while (cf->method->cn.__has_next__()) {

            std::vector<std::string> tokens;
#if EXECUTION
            cout << "IC : " << ic << endl;
#endif

            linecode = ((Code *) cf->method->cn.__next__())->getCode();
            init_linecode = linecode;

#if EXECUTION
            cout << "EXECUTE:" << linecode << endl;
#endif
            split(linecode, tokens);

            p = tokens[0];


            if (p == "istore") {
                
                // Integer
                // istore ivar

                int value;

                p1 = tokens[1];
                s = __pkg_id_load__(p1);

                value = ((Int*) cf->DATA_STACK->pop())->getValue();

                if (s != NULL) {

                    ((Int*) (((Field*) s)->get_data()))->setValue(value);

                } else {

                    cout << "Undefined Variable";
                    exit(0);

                }


            } else if (p == "dstore") {
                
                // Double
                // dstore dvar

                double value;

                p1 = tokens[1];
                s = __pkg_id_load__(p1);

                value = ((Double*) cf->DATA_STACK->pop())->getValue();

                if (s != NULL) {

                    ((Double*) (((Field*) s)->get_data()))->setValue(value);

                } else {

                    cout << "Undefined Variable";
                    exit(0);

                }

            } else if (p == "fstore") {
                
                // Float
                // fstore dvar

                float value;

                p1 = tokens[1];
                s = __pkg_id_load__(p1);

                value = ((Float*) cf->DATA_STACK->pop())->getValue();

                if (s != NULL) {

                    ((Float*) (((Field*) s)->get_data()))->setValue(value);

                } else {

                    cout << "Undefined Variable";
                    exit(0);

                }

            } else if (p == "rstore") {
                
                // Object
                // rstore objref

                p1 = tokens[1];
                s = __pkg_id_load__(p1);


                if (s != NULL) {

                    ( ((Reference*)((Field*) s)->get_data()))->setPointer((Object*) cf->DATA_STACK->pop());

                } else {

                    cout << "Undefined Variable";
                    exit(0);

                }


            } else if (p == "iastore") {
                
                
                //index
                //value
                //iastore arref
                
                p1 = tokens[1];
                
                s = __pkg_id_load__(p1);
                
                
                if (s != NULL) {
                    
                    Int* value = (Int*) (cf->DATA_STACK)->pop();
                    int index = ((Int*) (cf->DATA_STACK)->pop())->getValue();

                    (((IntArray*)(((Field*) s)->get_data())))->set_element(index,value);

                } else {

                    cout << "Undefined Variable";
                    exit(0);

                }
                
                

            } else if (p == "istore_") {
                // istore_ id

                p1 = tokens[1];
                ((Reference*) (cf->__load__(p1)))->setPointer(

                        ((Int*) (cf->DATA_STACK)->pop())
                        );




            } else if (p == "dstore_") {

                // dstore_ id

                p1 = tokens[1];

                ((Reference*) (cf->__load__(p1)))->setPointer(

                        ((Double*) (cf->DATA_STACK)->pop())
                        );



            } else if (p == "sstore_") {

                // sstore_ id

                p1 = tokens[1];

                ((Reference*) (cf->__load__(p1)))->setPointer(

                        ((Literal*) (cf->DATA_STACK)->pop())
                        );



            } else if (p == "fstore_") {
                // fstore_ id

                p1 = tokens[1];

                ((Reference*) (cf->__load__(p1)))->setPointer(

                        ((Float*) (cf->DATA_STACK)->pop())
                        );



            }
            else if (p == "rstore_") {
                // rstore_ index

                p1 = tokens[1];
                Object* obj = (Object*) (cf->DATA_STACK)->pop();

                ((Reference*) (cf->__load__(p1)))->setPointer(obj);
                ((Reference*) (cf->__load__(p1)))->setStaticDef((Class*) obj->getClass());
                
                /*if (stoi(p1) > 0) {

                    ((Reference*) (st.see(ebp - stoi(p1) - 1)))->setPointer(obj);
                    ((Reference*) (st.see(ebp - stoi(p1) - 1)))->setStaticDef((Class*) obj->getClass());

                } else if (stoi(p1) < 0) {

                    Block* b = (Block*) scope_stack.see(scope_stack.esp());
                    ((Reference*) (b->get(stoi(p1))))->setPointer(obj);
                    ((Reference*) (b->get(stoi(p1))))->setStaticDef();

                }
                 */


            } else if (p == "iload_") {

                // iload_ id

                p1 = tokens[1];

                (cf->DATA_STACK)->push(

                        new Int(

                        ((Int*) (((Reference*) (cf->__load__(p1)))->getPointer()))->getValue()

                        )

                        );


            } else if (p == "dload_") {

                // dload_ id

                p1 = tokens[1];

                (cf->DATA_STACK)->push(

                        new Double(

                        ((Double*) (((Reference*) (cf->__load__(p1)))->getPointer()))->getValue()

                        )

                        );


            } else if (p == "sload_") {

                // sload_ id

                p1 = tokens[1];

                (cf->DATA_STACK)->push(

                        new Literal(

                        ((Literal*) (((Reference*) (cf->__load__(p1)))->getPointer()))->getValue()

                        )

                        );


            }
            else if (p == "fload_") {

                // dload_ id

                p1 = tokens[1];

                (cf->DATA_STACK)->push(

                        new Float(

                        ((Float*) (((Reference*) (cf->__load__(p1)))->getPointer()))->getValue()

                        )

                        );


            } else if (p == "rload_") {
                // rload_ 5

                p1 = tokens[1];
                Object* obj;

                (cf->DATA_STACK)->push((Object*) (((Reference*) (cf->__load__(p1)))->getPointer()));

                /*if (stoi(p1) > 0) {

                    obj = (Object*) st.see(ebp - stoi(p1) - 1);
                    st.push(obj);


                } else if (stoi(p1) < 0) {

                    Block* b = (Block*) scope_stack.see(scope_stack.esp());

                    obj = (Object*) b->get(stoi(p1));
                    st.push((Object*)(((Reference*) obj )->getPointer()));



                }*/

/*PEN*/         } else if (p == "iload") {
                // iload ivar

                p1 = tokens[1];

                if (s = __pkg_id_load__(p1)) {

                    (cf->DATA_STACK)->push(new Int(((Int*) (((Field*) s)->get_data()))->getValue()));
                }

/*PEN*/         } else if (p == "dload") {
                // dload dvar

                p1 = tokens[1];

                if (s = __pkg_id_load__(p1)) {

                    (cf->DATA_STACK)->push(new Double(((Double*) (((Field*) s)->get_data()))->getValue()));
                }

/*PEN*/         } else if (p == "fload") {
                // fload fvar

                p1 = tokens[1];

                if (s = __pkg_id_load__(p1)) {

                    (cf->DATA_STACK)->push(new Float(((Float*) (((Field*) s)->get_data()))->getValue()));
                }

/*PEN*/         } else if (p == "rload") {
                // rload objref

                p1 = tokens[1];

                if (s = __pkg_id_load__(p1)) {
                    (cf->DATA_STACK)->push(((Object*) (((Reference*) (((Field*) s)->get_data()))->getPointer())));
                }

/*PEN*/         } else if (p == "iaload") {
                
                //index
                // iaload arref

                Array* arrayref;
                int index;

                p1 = tokens[1];

                if (s = __pkg_id_load__(p1)) {
                    
                    index = ((Int*) (cf->DATA_STACK)->pop())->getValue();
                    
                    (cf->DATA_STACK)->push(new Int(  ( (Int*)(((IntArray*) (((Field*) s)->get_data()))->get_element(index) ))->getValue()  ));
                }
                
            }

            else if (p == "ivar") {
                // ivar id 5

                p1 = tokens[1];
                p2 = tokens[2];
                Int* integer = new Int(stoi(p2));
                Reference* iref = new Reference();
                iref->setName(p1);
                iref->setPointer(integer);

                cf->__def_var__(iref);


            } else if (p == "dvar") {
                // dvar id 5.6

                p1 = tokens[1];
                p2 = tokens[2];
                Double* doub = new Double(stod(p2));
                Reference* dref = new Reference();
                dref->setName(p1);
                dref->setPointer(doub);

                cf->__def_var__(dref);

            } else if (p == "fvar") {
                // fvar id 5.6

                p1 = tokens[1];
                p2 = tokens[2];
                Float* fl = new Float(stof(p2));
                Reference* fref = new Reference();
                fref->setName(p1);
                fref->setPointer(fl);
                
                cf->__def_var__(fref);

            } else if (p == "rvar") {
                // rvar id NULL

                p1 = tokens[1];
                p2 = tokens[2];

                if (p2 == "NULL") {

                    Reference* nvar = new Reference();
                    nvar->setName(p1);

                    cf->__def_var__(nvar);
                }

            } else if (p == "svar") {

                std::smatch tokens;

                if (std::regex_search(init_linecode, tokens, std::regex("v_sconst (.*) \"(.*)\""))) {

                    Literal* str = new Literal(tokens[2]);
                    Reference* sref = new Reference();
                    sref->setName(tokens[1]);
                    sref->setPointer(str);
                
                    cf->__def_var__(sref);
                }

            }
            else if (p == "iconst") {
                // iconst 5
                p1 = tokens[1];

                (cf->DATA_STACK)->push(new Int(stoi(p1)));

            } else if (p == "dconst") {
                // dconst 5.6
                p1 = tokens[1];

                (cf->DATA_STACK)->push(new Double(stod(p1)));

            } else if (p == "fconst") {
                // fconst 5.6
                p1 = tokens[1];

                (cf->DATA_STACK)->push(new Float(stof(p1)));

            } else if (p == "rconst_null") {
                // rconst_null
                p1 = tokens[1];
                
                (cf->DATA_STACK)->push(new Object()); //must be new Null();


            } else if (p == "sconst") {

                std::smatch tokens;

                if (std::regex_search(init_linecode, tokens, std::regex("sconst \"(.*)\""))) {
                    (cf->DATA_STACK)->push(new Literal(tokens[1]));
                }

            } else if (p == "pop") {

                (cf->DATA_STACK)->pop();

            } else if (p == "iadd") {
                int left, right;

                left = ((Int*) (cf->DATA_STACK)->pop())->getValue();
                right = ((Int*) (cf->DATA_STACK)->pop())->getValue();

                (cf->DATA_STACK)->push(new Int(left + right));

            } else if (p == "dadd") {
                double left, right;

                left = ((Double*) (cf->DATA_STACK)->pop())->getValue();
                right = ((Double*) (cf->DATA_STACK)->pop())->getValue();

                (cf->DATA_STACK)->push(new Double(left + right));

            } else if (p == "fadd") {
                float left, right;

                right = ((Float*) (cf->DATA_STACK)->pop())->getValue();
                left = ((Float*) (cf->DATA_STACK)->pop())->getValue();

                st.push(new Float(left + right));

            } else if (p == "sadd") {

                string left;
                string right;

                right = ((Literal*) (cf->DATA_STACK)->pop())->getValue();
                left = ((Literal*) (cf->DATA_STACK)->pop())->getValue();

                st.push(new Literal(left + right));


            } else if (p == "isub") {
                int left, right;

                right = ((Int*) (cf->DATA_STACK)->pop())->getValue();
                left = ((Int*) (cf->DATA_STACK)->pop())->getValue();


                (cf->DATA_STACK)->push(new Int(left - right));

            } else if (p == "dec") {
                Int* val;

                val = (Int*) (cf->DATA_STACK)->pop();
                val->setValue(val->getValue() - 1);

                (cf->DATA_STACK)->push(val);

            } else if (p == "inc") {
                Int* val;

                val = (Int*) (cf->DATA_STACK)->pop();
                val->setValue(val->getValue() + 1);

                (cf->DATA_STACK)->push(val);

            } else if (p == "dsub") {
                double left, right;

                right = ((Double*) (cf->DATA_STACK)->pop())->getValue();
                left = ((Double*) (cf->DATA_STACK)->pop())->getValue();


                (cf->DATA_STACK)->push(new Double(left - right));

            } else if (p == "fsub") {
                float left, right;

                right = ((Float*) (cf->DATA_STACK)->pop())->getValue();
                left = ((Float*) (cf->DATA_STACK)->pop())->getValue();


                (cf->DATA_STACK)->push(new Float(left - right));

            } else if (p == "ssub") {



            } else if (p == "imul") {

                int left, right;

                right = ((Int*) (cf->DATA_STACK)->pop())->getValue();
                left = ((Int*) (cf->DATA_STACK)->pop())->getValue();


                (cf->DATA_STACK)->push(new Int(left * right));

            } else if (p == "dmul") {
                double left, right;


                right = ((Double*) (cf->DATA_STACK)->pop())->getValue();
                left = ((Double*) (cf->DATA_STACK)->pop())->getValue();


                (cf->DATA_STACK)->push(new Double(left * right));

            } else if (p == "fmul") {
                float left, right;


                right = ((Float*) (cf->DATA_STACK)->pop())->getValue();
                left = ((Float*) (cf->DATA_STACK)->pop())->getValue();


                (cf->DATA_STACK)->push(new Float(left * right));

            } else if (p == "smul") {

                int times;
                string buf = "";
                string str;

                str = ((Literal*) (cf->DATA_STACK)->pop())->getValue();
                times = ((Int*) (cf->DATA_STACK)->pop())->getValue();

                for (int i = 0; i < times; i++)
                    buf += str;

                (cf->DATA_STACK)->push(new Literal(buf));

            } else if (p == "idiv") {
                int left, right;


                right = ((Int*) (cf->DATA_STACK)->pop())->getValue();
                left = ((Int*) (cf->DATA_STACK)->pop())->getValue();


                if (right != 0) {
                    (cf->DATA_STACK)->push(new Int(left / right));
                } else {

                    cout << "Exception: DivisionByZero";
                    exit(0);
                }


            } else if (p == "ddiv") {
                double left, right;


                right = ((Double*) (cf->DATA_STACK)->pop())->getValue();
                left = ((Double*) (cf->DATA_STACK)->pop())->getValue();


                if (right != 0) {
                    (cf->DATA_STACK)->push(new Double(left / right));
                } else {

                    cout << "Exception: DivisionByZero";
                    exit(0);
                }

            } else if (p == "fdiv") {
                float left, right;


                right = ((Float*) (cf->DATA_STACK)->pop())->getValue();
                left = ((Float*) (cf->DATA_STACK)->pop())->getValue();


                if (right != 0) {
                    (cf->DATA_STACK)->push(new Float(left / right));
                } else {

                    cout << "Exception: DivisionByZero";
                    exit(0);
                }

            } else if (p == "sdiv") {


            } else if (p == "i2s") {

                Int* x = (Int*) (cf->DATA_STACK)->pop();
                (cf->DATA_STACK)->push(new Literal(std::to_string(x->getValue())));

            } else if (p == "i2d") {

                Int* x = (Int*) (cf->DATA_STACK)->pop();
                (cf->DATA_STACK)->push(new Double((double) x->getValue()));
            } else if (p == "i2f") {

                Int* x = (Int*) (cf->DATA_STACK)->pop();
                (cf->DATA_STACK)->push(new Float((float) x->getValue()));
            } else if (p == "d2i") {

                Double* x = (Double*) (cf->DATA_STACK)->pop();
                (cf->DATA_STACK)->push(new Int((int) x->getValue()));
            } else if (p == "d2f") {

                Double* x = (Double*) (cf->DATA_STACK)->pop();
                (cf->DATA_STACK)->push(new Float((float) x->getValue()));
            } else if (p == "d2s") {

                Double* x = (Double*) (cf->DATA_STACK)->pop();
                (cf->DATA_STACK)->push(new Literal(std::to_string(x->getValue())));

            }
            else if (p == "f2d") {

                Float* x = (Float*) (cf->DATA_STACK)->pop();
                (cf->DATA_STACK)->push(new Double((double) x->getValue()));
            } else if (p == "s2i") {

                Literal* x = (Literal*) (cf->DATA_STACK)->pop();
                (cf->DATA_STACK)->push(new Int(stoi(x->getValue())));

            } else if (p == "s2d") {

                Literal* x = (Literal*) (cf->DATA_STACK)->pop();
                (cf->DATA_STACK)->push(new Double(stod(x->getValue())));

            } else if (p == "s2f") {

                Literal* x = (Literal*) (cf->DATA_STACK)->pop();
                (cf->DATA_STACK)->push(new Float(stof(x->getValue())));

            } else if (p == "ret") {

                //int val;

                // par1
                // par2
                // ret val
                // ebp
                // local variables
                // Returned object
                // val

                //Get the operand of ret (is the number of parameters)
                //val = ((Int*) st.pop())->getValue();

                //Get the returned object
                s = (symbol *) (cf->DATA_STACK)->pop();

                // mov esp ebp
                //st.setesp(ebp);

                // pop ebp
                //ebp = ((Int*) st.pop())->getValue();

                //Get the next instruction line
                //ic = ((Int*) st.pop())->getValue();


                //Free the memory of parameters
                //st.setesp(st.esp() - val);


                //cur_hs = (hash_table*) hts.pop();


                //Push the returned object
                //st.push(s);
                //scope_stack.pop();

                Frame* f = (Frame*) CALL_STACK.pop();

                if (CALL_STACK.esp() != -1) {

                    ((Frame*) CALL_STACK.see(CALL_STACK.esp()))->DATA_STACK->push((Object*) s);
                }

                PKG_STACK.pop();

                if (f->ct == METHOD) {

                    PKG_STACK.pop();
                } else if (f->ct == FUNCTION) {

                    //Nothing
                }

                break;

            } else if (p == "new") {

                Class* y;
                Object* x;

                p1 = tokens[1];
                y = (Class *) (cf->__load__(p1));
                
                if (y == NULL)
                    y = (Class *) __pkg_id_load__(p1);
                
                if (y != NULL) {
                    if (y->get_mod() == ABSTRACT_MOD) {

                        cout << "Abstract class";
                        exit(1);
                    }

                    x = y->createInstance();
                    //x->setClass(y);


                }
                else {
                    
                    cout << "Undefined class";
                    exit(1);
                }

                (cf->DATA_STACK)->push(x);

            } else if (p == "invoke_virtual") {

                // invoke_virtual package.class.method
                // par1 <--- this object
                // par2
                // ret val
                // ebp
                // local variables
                // Returned object
                // val

                Method* y;
                Class* cclass;


                y = (Method*) cf->__load__(tokens[1]);

                if (y == NULL)
                    y = (Method *) __pkg_id_load__(tokens[1]);

                if (y == NULL) {

                    cout << "Dynamic binding error";
                    exit(1);
                } else {
                    cclass = (Class*) y->getClass(); //sec


                }


                //Check accessibility

                if (PKG_STACK.see(PKG_STACK.esp())->mht != cclass->mht) {

                    if (y->get_acc() != PUBLIC_ACC) {


                        if (y->get_acc() == PRIVATE_ACC) {

                            cout << "Access to private method\n";
                            exit(1);
                        } else if (y->get_acc() == PROTECTED_ACC) {

                            cout << "Access to protected method\n";

                        }
                    }


                }

                if (y->native != true) {

                    //hts.push(cur_hs);
                    //hts.push(new hash_table("*"));

                    //cur_hs = cclass->mht;

                    PKG_STACK.push((symbol*) cclass->package);
                    PKG_STACK.push((symbol*) cclass);

                    Reference * params[y->num_params];
                    
                    
                    for (int i = y->num_params; i > 0; i--) {
                        
                        Reference* rpar = new Reference();
                        
                        rpar->setPointer((Object*) cf->DATA_STACK->pop());
                        rpar->setName(y->args_names[i - 1]);
                        params[i - 1] = rpar;
                    }

                    //Push line of next instruction after call
                    //cout<<ic;
                    //st.push(new Int(ic + 1));

                    // push ebp & ebp = esp
                    //st.push(new Int(ebp));
                    //ebp = st.esp();


                    //ic = y->getLine();

                    //scope_stack.push(new Block());
                    __call__(y, params, METHOD);

                    break;

                } else {

                    // Native_Method_Signature* nms = (Native_Method_Signature*) System::call_native_method(cclass->getName(),tokens[2]);


                    //CNIHandlerBlock::addoop(new _c_object() ,st.see(st.esp() - y->num_params + 1));

                    //c_string (*string_func)(c_object, ...);
                    // string_func = (c_string(*)(c_object,...))(nms->get_native_function());
                    // cout<<((Literal *)(CNIHandlerBlock::resolve((*string_func)(cobj))))->getValue()

                    int prev_top = CNIHandlerBlock::top;
                    struct CNIEnv env;
                    void* handle = dlopen((std::string(getenv("HOME")) + "/colibri/native/" + y->module_name + "/" + y->class_name + "/" + "libwrapper_" + y->module_name + "_" + y->class_name + "_" + y->getName() + y->get_rtype() + ".so").c_str(), RTLD_LAZY);

                    if (!handle) {


                        cout << dlerror() << std::endl;
                        exit(EXIT_FAILURE);
                    }

                    dlerror();

                    void (*wrapper)(CNIEnv*, vs_stack<Object> *);

                    wrapper = (void (*) (CNIEnv*, vs_stack<Object> *)) dlsym(handle, ("wrapper_" + y->module_name + "_" + y->class_name + "_" + y->getName() + y->get_rtype()).c_str());

                    if ((dlerror()) != NULL) {

                        cout << "RunTimeError: Wrapper didn't found!\n" << endl;
                        exit(EXIT_FAILURE);

                    }

                    (wrapper) (&env, (cf->DATA_STACK));


                    //  ((Object*)st.see(st.esp()))->wrapper_Object_toStringR(&env,&st);
                }


            } /*else if (p == "invoke_special") {

                // invoke_special Class method
                // par1 <--- this object
                // par2
                // ret val
                // ebp
                // local variables
                // Returned object
                // val

                Class* superclass = (Class*) ((Class*) ((Object*) cf->DATA_STACK->see(cf->DATA_STACK->esp()))->getClass())->getSuperClass();

                do {

                    if (superclass->getName() != tokens[1]) {

                        superclass = superclass->getSuperClass();
                        if (superclass == NULL) {

                            cout << "Inheretance error";
                            exit(1);
                        }
                    } else {

                        break;
                    }


                } while (true);


                Method* y = (Method*) (superclass->mht->lookfor(tokens[2]));

                if (y == NULL) {
                    cout << "Undefined method\n";
                    break;
                }

                //Check accessibility

                if (PKG_STACK.see(PKG_STACK.esp())->mht != superclass->mht) {

                    if (y->get_acc() != PUBLIC_ACC) {


                        if (y->get_acc() == PRIVATE_ACC) {

                            cout << "Access to private method\n";
                            exit(1);
                        } else if (y->get_acc() == PROTECTED_ACC) {

                            cout << "Access to protected method\n";

                        }
                    }

                }


                //hts.push(cur_hs);
                //hts.push(new hash_table("*"));

                //cur_hs = superclass->mht;

                //Push line of next instruction after call
                //cout<<ic;
                //st.push(new Int(ic + 1));

                // push ebp & ebp = esp
                //st.push(new Int(ebp));
                //ebp = st.esp();


                //ic = y->getLine();

                //scope_stack.push(new Block());

                PKG_STACK.push((symbol*) superclass);

                Object * params[y->num_params];

                for (int i = y->num_params; i > 0; i--) {

                    params[i - 1] = (Object*) cf->DATA_STACK->pop();
                }

                __call__(y, params, METHOD);

                break;


            } */else if (p == "invoke_static") {
                //invoke_static functionname

                Method* x;

                x = (Method*) cf->__load__(tokens[1]);

                if (x == NULL)
                    x = (Method *) __pkg_id_load__(tokens[1]);

                if (x == NULL) {

                    cout << "Undeclared function\n";
                    exit(1);
                }


                if (x->native != true) {

                    PKG_STACK.push((symbol*) x->package);
                    //std::cout<<"Num of params: "<< x->num_params << endl;
                     Reference * params[x->num_params];

                    for (int i = x->num_params; i > 0; i--) {
                        
                        Reference* rpar = new Reference();
                        
                        rpar->setPointer((Object*) cf->DATA_STACK->pop());
                        rpar->setName(x->args_names[i - 1]);
                        
                        params[i - 1] = rpar;
                    }

                    //Push line of next instruction after call
                    //cout<<ic;
                    //st.push(new Int(ic + 1));

                    // push ebp & ebp = esp
                    //st.push(new Int(ebp));
                    //ebp = st.esp();


                    //ic = y->getLine();

                    //scope_stack.push(new Block());
                    __call__(x, params, FUNCTION);

                    break;

                } else {

                    // Native_Method_Signature* nms = (Native_Method_Signature*) System::call_native_method(cclass->getName(),tokens[2]);


                    //CNIHandlerBlock::addoop(new _c_object() ,st.see(st.esp() - y->num_params + 1));

                    //c_string (*string_func)(c_object, ...);
                    // string_func = (c_string(*)(c_object,...))(nms->get_native_function());
                    // cout<<((Literal *)(CNIHandlerBlock::resolve((*string_func)(cobj))))->getValue()

                    int prev_top = CNIHandlerBlock::top;
                    struct CNIEnv env;
                    void* handle = dlopen((std::string(getenv("HOME")) + "/colibri/native/" + x->module_name + "/libwrapper_" + x->module_name + "_" + x->getName() + x->get_rtype() + ".so").c_str(), RTLD_LAZY);

                    if (!handle) {


                        cout << dlerror();
                        exit(EXIT_FAILURE);
                    }

                    dlerror();

                    void (*wrapper)(CNIEnv*, vs_stack<Object> *);

                    wrapper = (void (*) (CNIEnv*, vs_stack<Object> *)) dlsym(handle, ("wrapper_" + x->module_name + "_" + x->getName() + x->get_rtype()).c_str());

                    if ((dlerror()) != NULL) {


                        exit(EXIT_FAILURE);

                    }

                    (wrapper) (&env, (cf->DATA_STACK));


                    //  ((Object*)st.see(st.esp()))->wrapper_Object_toStringR(&env,&st);
                }



            } else if (p == "print") {

                struct CNIEnv* env;
                c_object x = new _c_object();
                CNIHandlerBlock::addoop(x, (Literal*) (cf->DATA_STACK->pop()));
                System::print(env, x);
                CNIHandlerBlock::remoop();


            } else if (p == "read") {
                string input;
                getline(cin, input);
                cf->DATA_STACK->push(new Literal(input));

            } else if (p == "getfield") {

                //getfield fieldname

                p1 = tokens[1];
                Object* x = (Object*) (cf->DATA_STACK)->pop();

                if (x != NULL) {

                    Field* f = (Field*) (x->mht->lookfor(p1));

                    if (f != NULL) {

                        //Check accessibility

                        if (( PKG_STACK.see(PKG_STACK.esp())->mht !=  (x->getClass())->mht) && (f->get_acc() == PRIVATE_ACC)) {

                            cout << "Error: Access to private field"<<endl;
                            exit(1);
                        }

                    }



                        string classname = (f->get_data())->className();
                        if (classname == "Int") {

                            (cf->DATA_STACK)->push(new Int(((Int*) f->get_data())->getValue()));
                        } else if (classname == "Double") {

                            (cf->DATA_STACK)->push(new Double(((Double*) f->get_data())->getValue()));
                        } else if (classname == "Float") {

                            (cf->DATA_STACK)->push(new Float(((Float*) f->get_data())->getValue()));
                        } else if (classname == "Literal") {

                            (cf->DATA_STACK)->push(new Literal(((Literal*) f->get_data())->getValue()));
                        } else if (classname == "Reference") {
                            (cf->DATA_STACK)->push((Object*) (((Reference*) f->get_data())->getPointer()));
                        }
                    }
                

            } else if (p == "putfield") {

                //value
                //objectref    
                //putfield fieldname

                p1 = tokens[1];

                Object* x = (Object*) (cf->DATA_STACK)->pop();

                Object* value = (Object*) (cf->DATA_STACK)->pop();

                if (x != NULL) {

                    Field* f = (Field*) (x->mht->lookfor(p1));


                    if (f != NULL) {

                        //Check accessibility

                        if (( PKG_STACK.see(PKG_STACK.esp())->mht !=  (x->getClass())->mht) && (f->get_acc() == PRIVATE_ACC)) {

                            cout << "Error: Access to private field"<<endl;
                            exit(1);
                        }


                        string classname = (f->get_data())->className();

                        if (classname == "Int") {

                            ((Int*) f->get_data())->setValue(((Int*) value)->getValue());
                        } else if (classname == "Double") {

                            ((Double*) f->get_data())->setValue(((Double*) value)->getValue());
                        } else if (classname == "Float") {

                            ((Float*) f->get_data())->setValue(((Float*) value)->getValue());
                        } else if (classname == "Literal") {

                            ((Literal*) f->get_data())->setValue(((Literal*) value)->getValue());
                        } else if (classname == "Reference") {
                            ((Reference*) f->get_data())->setPointer(value);
                        }

                    }
                }

            } else if (p == "dup") {

                int nloops;
                p = tokens[1];
                s = (cf->DATA_STACK)->pop();

                nloops = stoi(p);

                for (int i = 0; i < nloops; i++)
                    (cf->DATA_STACK)->push(s);

            } else if (p == "icmpg") {

                int right = ((Int*) (cf->DATA_STACK)->pop())->getValue();
                int left = ((Int*) (cf->DATA_STACK)->pop())->getValue();

                if (left > right)
                    (cf->DATA_STACK)->push(new Int(1));
                else
                    (cf->DATA_STACK)->push(new Int(0));


            } else if (p == "icmp") {

                int right = ((Int*) (cf->DATA_STACK)->pop())->getValue();
                int left = ((Int*) (cf->DATA_STACK)->pop())->getValue();

                if (left > right)
                    (cf->DATA_STACK)->push(new Int(1));
                else if (left == right)
                    (cf->DATA_STACK)->push(new Int(0));
                else
                    (cf->DATA_STACK)->push(new Int(-1));


            } else if (p == "dcmp") {

                double right = ((Double*) (cf->DATA_STACK)->pop())->getValue();
                double left = ((Double*) (cf->DATA_STACK)->pop())->getValue();

                if (left > right)
                    (cf->DATA_STACK)->push(new Int(1));
                else if (left == right)
                    (cf->DATA_STACK)->push(new Int(0));
                else
                    (cf->DATA_STACK)->push(new Int(-1));


            } else if (p == "ifzero") {

                // ifzero label


                p1 = tokens[1];

                int res = ((Int*) (cf->DATA_STACK)->pop())->getValue();

                if (res == 0)
                    cf->jump_to(p1);
                
                    
                continue;

            } else if (p == "ifnotzero") {

                // ifnotzero label


                p1 = tokens[1];

                int res = ((Int*) (cf->DATA_STACK)->pop())->getValue();

                if (res != 0)
                    cf->jump_to(p1);
               
                continue;

            } else if (p == "ifeq") {

                // ifeq label label2


                p1 = tokens[1];
                p2 = tokens[2];

                int res = ((Int*) (cf->DATA_STACK)->pop())->getValue();

                if (res == 0)
                  cf->jump_to(p1);
                else
                  cf->jump_to(p2);

                continue;

            } else if (p == "ifne") {

                // ifne label label2


                p1 = tokens[1];
                p2 = tokens[2];

                int res = ((Int*) (cf->DATA_STACK)->pop())->getValue();

                if (res != 0)
                    cf->jump_to(p1);
                else
                    cf->jump_to(p2);

                continue;

            } else if (p == "ifg") {

                // ifg label label2


                p1 = tokens[1];
                p2 = tokens[2];

                int res = ((Int*) (cf->DATA_STACK)->pop())->getValue();

                if (res == 1)
                    cf->jump_to(p1);
                else
                    cf->jump_to(p2);

                continue;

            } else if (p == "ifge") {

                // ifge label label2


                p1 = tokens[1];
                p2 = tokens[2];

                int res = ((Int*) (cf->DATA_STACK)->pop())->getValue();

                if (res == 1 || res == 0)
                    cf->jump_to(p1);
                else
                    cf->jump_to(p2);

                continue;

            } else if (p == "ifl") {

                // ifle label label2


                p1 = tokens[1];
                p2 = tokens[2];

                int res = ((Int*) (cf->DATA_STACK)->pop())->getValue();

                if (res == -1)
                    cf->jump_to(p1);
                else
                    cf->jump_to(p2);

                continue;

            } else if (p == "ifle") {

                // ifle label label2


                p1 = tokens[1];
                p2 = tokens[2];

                int res = ((Int*) (cf->DATA_STACK)->pop())->getValue();

                if (res == -1 || res == 0)
                   cf->jump_to(p1);
                else
                   cf->jump_to(p2);

                continue;

            } else if (p == "ifnull") {

                // ifge label label2


                p1 = tokens[1];
                p2 = tokens[2];

                symbol* s = (cf->DATA_STACK)->pop();

                if (!s)
                    cf->jump_to(p1);
                else
                    cf->jump_to(p2);

                continue;

            } else if (p == "ifnotnull") {

                // ifge label label2


                p1 = tokens[1];
                p2 = tokens[2];

                symbol* s = (cf->DATA_STACK)->pop();

                if (s)
                    cf->jump_to(p1);
                else
                    cf->jump_to(p2);

                continue;

            } else if (p == "jmp") {

                // jmp label

                p1 = tokens[1];

                cf->jump_to(p1);
                continue;


            } 
            else if (p == "label") {

                //label

                cf->push_block();
                continue;


            }
            else if (p == "end_label") {

                // end_label


                cf->pop_block();
                continue;


            }
            else if (p == "newarray") {

                //length

                Array* ar;
                p = tokens[1];


                int length = ((Int*) (cf->DATA_STACK)->pop())->getValue();

                if (p == "I") {

                    ar = new IntArray(length, 1);
                    
                } 
                
                /*else if (p == "D") {
                    //For double;
                } else {
                    Class* y;
                    Object* x;

                    y = (Class *) class_defs.lookfor(p);

                    if (y != NULL) {

                        //For other classes;
                    } else {

                        // Exception(ClassNotFound);
                    }


                }*/
                
                cf->DATA_STACK->push(ar);

                
            }
            else if (p == "nl") {

                std::cout << endl;

            } /*else if (p == "snext") {

                Literal* str = (Literal *) (cf->DATA_STACK)->pop();

                struct CNIEnv* env;
                c_object x = new _c_object();
                CNIHandlerBlock::addoop(x, str);
                c_object res = str->next(env, x);
                Object* sres = (Object*) CNIHandlerBlock::resolve(res);

                CNIHandlerBlock::remoop();
                CNIHandlerBlock::remoop();


                if (cpush(str)) continue;
                if (cpush(sres)) continue;

            } else if (p == "try") {

                //try 6 :

                p1 = tokens[1];

                try_stack.push(new Literal(p1));

            }*/


            ic++;
        }

    }


}

void CVM::exc_terminate(Exception* e) {

    struct CNIEnv* env;
    c_object x = new _c_object();
    CNIHandlerBlock::addoop(x, e);
    c_object res = e->toString(env, x);
    Literal* sres = (Literal*) CNIHandlerBlock::resolve(res);

    cout << sres->getValue() << endl;

    CNIHandlerBlock::remoop();
    exit(0);
}

bool CVM::catch_exception(Exception* e) {

    Literal* tr = (Literal*) try_stack.pop();
    Code* cd;
    struct CNIEnv* env;

    c_object x = new _c_object();
    CNIHandlerBlock::addoop(x, e);
    c_object res = e->get_title(env, x);
    Literal* sres = (Literal*) CNIHandlerBlock::resolve(res);
    CNIHandlerBlock::remoop();

    //cout<<"except " + sres->getValue() + " " + tr->getValue()<<std::endl;
    ; //cd = (Code*) cur_hs->lookfor("except " + sres->getValue() + " " + tr->getValue());

    if (cd != NULL) {

        ic = (cd)->getLine();
        return true;
    }

    return false;
}



CVM::~CVM() {
    //dtor
}
