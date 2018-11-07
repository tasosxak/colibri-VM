/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Literal.cpp
 * Author: tasosxak
 * 
 * Created on February 11, 2018, 6:57 PM
 */

#include "Literal.h"
#include <string>
#include <sstream>
#include "StopIterationException.h"

Literal::Literal()
{
    //ctor
}

Literal::~Literal()
{
    //dtor
}


Literal::Literal(const std::string& value):Data_Type(){

    this->index = 0;
    this->value =value;
}

Literal::Literal(Literal* symb){

  //this->name = symb->getName();
  this->linecode = symb->getLine();
  setValue(symb->getValue());

}

std::string Literal::getValue(){

    return this->value;
}

c_object Literal::next(CNIEnv* env, c_object obj){
    
    std::string st;
    std::stringstream sst;
    
    if(this->index < (this->value).length()){
        
        sst<<(this->value).at(this->index++);
        sst >> st;
        return env->newString( st );
    }
    
    this->index = 0;
    return env->newObject(new StopIterationException());
        
}


std::string Literal::className(){

    return "Literal";
}

void Literal::setValue(const std::string& value){

   this->value = value;
}

c_string Literal::toString(CNIEnv* env, c_object obj) {

    return env->newString(this->value);

}


