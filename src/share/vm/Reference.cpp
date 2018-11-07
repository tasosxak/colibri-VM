/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Reference.cpp
 * Author: tasosxak
 * 
 * Created on February 11, 2018, 7:02 PM
 */

#include "Reference.h"
#include "Class.h"

Reference::Reference()
{
    //ctor
}

Reference::Reference(Reference* symb)
{
    this->name = symb->getName();
    this->classRef = symb->getStaticDef();
    this->pointer = symb->getPointer();
}


Reference::Reference(std::string name,Class* classdef, Object* obj):Data_Type(name){

  this->pointer = obj;
  this->classRef = classdef;

}

std::string Reference::getName(){

   return symbol::getName();

}

Class* Reference::getDynamicDef(){

   return (Class*)(this->pointer)->getClass();

}

std::string Reference::className(){

    return "Reference";
}

void Reference::setPointer(Object* symb){

  this->pointer =symb;

}

void Reference::setStaticDef(Class* cls){

  this->classRef = cls;

}

Object* Reference::getPointer(){

  return this->pointer;
}

Class* Reference::getStaticDef(){

  return this->classRef;
}

Reference::~Reference()
{
    //dtor
}

c_string Reference::toString(CNIEnv* env, c_object obj){
    
    return this->pointer->toString(env,obj);
    

}