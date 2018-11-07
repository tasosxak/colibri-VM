/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Content.h
 * Author: tasosxak
 *
 * Created on August 30, 2018, 10:33 PM
 */

#ifndef CONTENT_H
#define CONTENT_H

#include "Code.h"
#include "symbol.h"
#include "vs_stack.h"

class Content : public symbol {
public:
    Content();
    Content(const Content& orig);
    virtual ~Content();
    Code* __next__();
    void  __add__(Code* cd);
    void  __zero__();
    bool  __has_next__();
    void  __jump__(int);
    int index;
    
private:
    int MAX_CODE_SIZE;
    vs_stack<symbol>* CODE_STACK;

};

#endif /* CONTENT_H */

