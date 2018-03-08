/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   symbol.cpp
 * Author: tasosxak
 * 
 * Created on February 11, 2018, 7:02 PM
 */

#include "symbol.h"
#include <string.h>
#include <iostream>
#include <typeinfo>

symbol::symbol()
{
    this->NextSymbol = NULL;
    this->PrevSymbol = NULL;
    this->mht = NULL;
    //ctor
}

symbol::symbol(symbol* symb){


    this->name = symb->getName();
    this->linecode = symb->getLine();
    if(symb->mht != NULL)
        this->mht = new hash_table(symb->mht);


}

symbol::symbol(std::string name){

    this->name = name;

    this->NextSymbol = NULL;
    this->PrevSymbol = NULL;
    this->mht = NULL;

}

std::string symbol::className(){

    return "symbol";
}

std::string symbol::getName(){
    std::string str(this->name);
    return str;

}

int symbol::getLine(){

    return this->linecode;
}

void symbol::setLine(int line){
    this->linecode = line;
}


symbol::~symbol()
{

    this->NextSymbol = NULL;
    this->PrevSymbol = NULL;
    this->mht = NULL;
    name = "";
    linecode = -1;
    //dtor
}

