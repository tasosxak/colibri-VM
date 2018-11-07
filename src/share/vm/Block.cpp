/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Block.cpp
 * Author: tasosxak
 * 
 * Created on August 3, 2018, 4:22 PM
 */

#include "Block.h"
#include "hash_table.h"

Block::Block() {
    
    this->size = 0;
    this->_DECLARATIONS = new hash_table();
}

Block::Block(const Block& orig) {
}

void Block::__def__(Object* symb){

    this->_DECLARATIONS->add(symb);
    this->size++;
    
}

void Block::__undef__(std::string id){
    
    this->_DECLARATIONS->discard(id);
    this->size++;
    
}

Object* Block::get(std::string id){
    
    return (Object*) this->_DECLARATIONS->lookfor(id);
}
    
Block::~Block() {
}

