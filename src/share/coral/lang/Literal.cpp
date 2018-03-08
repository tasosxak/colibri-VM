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



Literal::Literal()
{
    //ctor
}

Literal::~Literal()
{
    //dtor
}


Literal::Literal(const std::string& value):Data_Type(){

    this->value =value;
}

std::string Literal::getValue(){

    return this->value;
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


