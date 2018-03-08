/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Double.cpp
 * Author: tasosxak
 * 
 * Created on February 11, 2018, 6:50 PM
 */

#include "Double.h"
#include "Literal.h"

Double::Double()
{
    //ctor
}

Double::~Double()
{
    //dtor
}

Double::Double(Double* symb){

  //this->name = symb->getName();
  this->linecode = symb->getLine();
  setValue(symb->getValue());

}

Double::Double(double value)
{
    this->value = value;
}

double Double::getValue(){

    return this->value;
}

void Double::setValue(double value){

    this->value = value;
}


std::string Double::className(){

    return "Double";

}

/*

Double::Double(const std::string& name, double value):Decimal(name){

    this->value = value;

}*/

c_string Double::toString(){



}
