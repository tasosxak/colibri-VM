/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Content.cpp
 * Author: tasosxak
 * 
 * Created on August 30, 2018, 10:33 PM
 */

#include "Content.h"
#include "Code.h"
#include "vs_stack.h"

Content::Content() {
    
    this->index = 0;
    this->MAX_CODE_SIZE = 0;
    this->CODE_STACK = new vs_stack<symbol>();
    
}

Content::Content(const Content& orig) {
}

Content::~Content() {
}

Code* Content::__next__(){
    
    return (this->index < this->MAX_CODE_SIZE)?(Code*)this->CODE_STACK->see(this->index++) : NULL;
}

void Content::__add__(Code* cd){
    
    this->CODE_STACK->push(cd);
    this->MAX_CODE_SIZE++;
}

void Content::__jump__(int line){
    
    this->index = line;
}

    
void Content::__zero__(){
    
    this->index = 0;
}

bool Content::__has_next__(){
    
    return this->index < this->MAX_CODE_SIZE;
}