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
#include "Method.h"

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

    vs_stack<symbol> st; // Variable Stack

    vs_stack<hash_table> hts; // Symbol Table Stack

    hash_table hs; // Global Symbol Table
    hash_table class_defs; // Class Definitions Pool

    hash_table* cur_hs = &hs; //Current symbol table
    Class* cur_class; //Current class

    int Loader(string filename);
    template <class Container>
    void split(const std::string& str, Container& cont);
    int compile();
    int execute();
    void method_arg_analyzer(Method* meth, const std::string& args);

};

#endif /* CVM_H */

