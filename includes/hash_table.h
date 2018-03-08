/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hash_table.h
 * Author: tasosxak
 *
 * Created on February 11, 2018, 6:52 PM
 */

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "symbol.h"

class symbol;

class hash_table
{
    public:
        hash_table();
        hash_table(std::string name);
        hash_table(hash_table * hs);
        virtual ~hash_table();
        void clone(hash_table * hs);
        void add(symbol* symb);
        void discard(std::string name);
        symbol* lookfor(std::string name);
        symbol* ids[500];
        std::string getName();
    protected:

    private:
        std::string name;
        int mkkey(const char *s);
        int numSymbols;
        symbol *arr[500];


};

#endif /* HASH_TABLE_H */

