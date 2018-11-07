/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Block.h
 * Author: tasosxak
 *
 * Created on August 3, 2018, 4:22 PM
 */

#ifndef BLOCK_H
#define BLOCK_H
#include "hash_table.h"
#include "Object.h"

class Block: public symbol {
public:
    Block();
    Block(const Block& orig);
    void __def__(Object* symb);
    void __undef__(std::string);
    Object* get(std::string id);
    virtual ~Block();
private:
    int size;
    hash_table* _DECLARATIONS;

};

#endif /* BLOCK_H */

