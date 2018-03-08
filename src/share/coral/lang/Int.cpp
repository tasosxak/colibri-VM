/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Int.cpp
 * Author: tasosxak
 * 
 * Created on February 11, 2018, 6:53 PM
 */

#include "Int.h"
#include "Literal.h"
#include "CNIHandlerBlock.h"

Int::Int()
{
    //ctor
}

Int::~Int()
{
    //dtor
}

Int::Int(Int* symb){

  //this->name = symb->getName();
  this->linecode = symb->getLine();
  setValue(symb->getValue());

}

Int::Int(int value)
{
    this->value = value;
}

int Int::getValue(){
   
    return this->value;
}

void Int::setValue(int value){

    this->value = value;
}

std::string Int::className(){

    return "Int";
}


c_string Int::toString(CNIEnv* env, c_object obj){
    
    return env->IntToString(obj);
    

}

/*
Int::Int(const std::string& name, int value):Integer(name){

    this->value = value;

}
*/


