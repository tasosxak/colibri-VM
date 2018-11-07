/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Frame.h
 * Author: tasosxak
 *
 * Created on August 31, 2018, 9:12 PM
 */

#ifndef FRAME_H
#define FRAME_H

#include "symbol.h"
#include "Block.h"
#include "Object.h"
#include "Method.h"
#include "Reference.h"
#include "vs_stack.h"

enum Call_type {FUNCTION,METHOD};

class Frame: public symbol{
public:
    Frame(Method* meth,Reference* params[],Call_type);
    Frame(const Frame& orig);
    virtual ~Frame();
    
    Call_type ct;
    Method* method;
    Block* params;
    
    
    vs_stack<Object>* DATA_STACK;
    Object* __load__(std::string);
    
    
    void push_block();
    void jump_to(std::string id);
    void pop_block();
    void __def_var__(Object*);
    void __undef_var__(std::string);
    
    int BLOCK_STACK_SIZE;
    
    
private:
    vs_stack<Block>* BLOCK_STACK;

};

#endif /* FRAME_H */

