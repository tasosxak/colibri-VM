/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hash_table.cpp
 * Author: tasosxak
 * 
 * Created on February 11, 2018, 6:52 PM
 */

#include "hash_table.h"
#include "symbol.h"
#include <string.h>
#include <iostream>
#include <typeinfo>

#include "Int.h"
#include "Field.h"
#include "Reference.h"

#include <iostream>
using namespace std;


hash_table::hash_table()
{
    this->numSymbols = 0;
    
    for(int i = 0; i < 500; i++)
        this->arr[i] = NULL;
    
    //ctor
}

hash_table::hash_table(std::string name)
{
    this->numSymbols = 0;
    
    for(int i = 0; i < 500; i++)
        this->arr[i] = NULL;
    
    this->name = name;
    
    //ctor
}

hash_table::~hash_table()
{
    //dtor
}

void hash_table::add(symbol* symb)
{
    int i;
    symbol *p;
    
    i=this->mkkey((symb->getName().c_str()));
    this->ids[numSymbols] = symb;
    p=this->arr[i];
    symb->NextSymbol=p;
    symb->PrevSymbol=NULL;
    if(p) p->PrevSymbol=symb;
    
    this->arr[i]=symb;
    
    numSymbols++;



}

void hash_table::discard(std::string name)
{

    symbol *symbp;

    symbp = this->lookfor(name);

    if(symbp)
    {

        if(symbp->PrevSymbol != NULL)
            symbp->PrevSymbol->NextSymbol = symbp->NextSymbol;

        if(symbp->NextSymbol != NULL)
            symbp->NextSymbol->PrevSymbol = symbp->PrevSymbol;

        symbp->PrevSymbol = NULL;
        symbp->NextSymbol = NULL;
        delete symbp;

    }


}

void hash_table::clone(hash_table * hs){

 for(int i =0; i<hs->numSymbols; i++){


    if(hs->ids[i]->className() == "Field" && ((Field*)hs->ids[i])->get_acc() !=2)
    {

        Field* cx = new Field((Field *) hs->ids[i]);

        this->add(cx);

    }


 }

}

hash_table::hash_table(hash_table* hs){

this->numSymbols = 0;
    
    for(int i = 0; i < 500; i++)
        this->arr[i] = NULL;

 for(int i =0; i<hs->numSymbols; i++){


    if(hs->ids[i]->className() == "Field")
    {
        Field* cx = new Field((Field *) hs->ids[i]);

        this->add(cx);

    }

     /*
    else if(hs->ids[i]->className() == "symbol")
    {
        symbol* cx = (symbol*)hs->ids[i];
        this->add(new symbol(cx));

    }

    else if(hs->ids[i]->get_data()->className() == "Reference")
    {
        Reference* cx = (Reference*)hs->ids[i];
        this->add(new Reference(cx));

    }*/

 }

}

std::string hash_table::getName(){

return this->name;

}

symbol* hash_table::lookfor(std::string name)
{


    int i;
    symbol *p;

    i=this->mkkey(name.c_str());
    p= this->arr[i];

    while(p && (p->getName() != name) )
        p=p->NextSymbol;



    return p;

}

int hash_table::mkkey(const char *s)
{
    const char *p;
    int athr=0;

    for(p=s; *p; p++) athr=athr+(*p);
    return (athr % 500);
}






