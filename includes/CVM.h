/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CVM.h
 * Author: tasosxak
 *
 * Created on February 11, 2018, 6:33 PM
 */

#ifndef CVM_H
#define CVM_H

#include <iostream>

#include "vs_stack.h"
#include "Class.h"
#include "Exception.h"
#include "Method.h"
#include "Package.h"
#include "Frame.h"

using namespace std;

class CVM{

public:
    CVM(std::string bytecodefile);
    virtual ~CVM();
    int start();

protected:

private:
    std::string bytecodefile;
    
    //Basic Registers
    int eoc = -1; // End of code
    int ic = 0; // Instruction Counter
    int ebp = 0; // Stack Frame
    
    vs_stack<symbol>    st; // Variable Stack
    vs_stack<symbol>    scope_stack; // Declaration Stack
    vs_stack<symbol>    try_stack; // Try/except block stack
    vs_stack<Frame>     CALL_STACK; 
    vs_stack<symbol>*   CUR_BLOCK_STACK;
    vs_stack<symbol>*   CUR_DATA_STACK;
    vs_stack<symbol>    PKG_STACK;

    vs_stack<hash_table> hts; // Symbol Table Stack

    hash_table          GLOBAL_SB; // Global Symbol Table
    hash_table          class_defs; // Class Definitions Pool

    hash_table*         CUR_SB = &GLOBAL_SB; //Current symbol table
    //Class* cur_class; //Current class
    
    Frame*      __call__(Method*,Reference* params[],Call_type);
    Package*    load(string filename);
    Package*    compile(Package*);
    int         execute();
    
    template <class Container>
    void        split(const std::string& str, Container& cont);
    
    
    void        method_arg_analyzer(Method* meth, const std::string& args);
    void        exc_terminate(Exception*);
    bool        catch_exception(Exception* e);
    Object*     __pkg_id_load__(std::string id);
};  

#endif /* CVM_H */

