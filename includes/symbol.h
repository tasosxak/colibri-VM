/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   symbol.h
 * Author: tasosxak
 *
 * Created on February 11, 2018, 7:02 PM
 */

#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>
#include "hash_table.h"

class hash_table;

class symbol
{
    public:
        symbol();
        symbol(std::string name);
        symbol(symbol* symb);

        virtual ~symbol();

        std::string getName();
        void setName(std::string);
        int getLine();

        void setLine(int line);

        virtual std::string className();
        //virtual std::string print();

        symbol *NextSymbol;
        symbol *PrevSymbol;
        hash_table *mht;
        

    protected:
        std::string name;
        int linecode;
    private:


};

#endif /* SYMBOL_H */

