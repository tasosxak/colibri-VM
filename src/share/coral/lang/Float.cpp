/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Float.cpp
 * Author: tasosxak
 * 
 * Created on February 11, 2018, 6:51 PM
 */

#include "Float.h"
#include "Literal.h"



Float::Float()
{
    //ctor
}

Float::~Float()
{
    //dtor
}


Float::Float(Float* symb){

  //this->name = symb->getName();
  this->linecode = symb->getLine();
  setValue(symb->getValue());

}

Float::Float(float value)
{
    this->value = value;
}

float Float::getValue(){

    return this->value;
}

void Float::setValue(float value){

    this->value = value;
}


std::string Float::className(){

    return "Float";

}

/*

Float::Float(const std::string& name, float value):Decimal(name){

    this->value = value;

}*/

c_string Float::toString(){


}



