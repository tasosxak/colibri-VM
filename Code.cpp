/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Code.cpp
 * Author: tasosxak
 * 
 * Created on February 11, 2018, 6:48 PM
 */

#include "Code.h"


Code::Code()
{
    //ctor
}

Code::Code(const std::string& code){

    this->code = code;

}

std::string Code::getCode(){

    return this->code;

}

std::string Code::className(){

    return "Code";

}

Code::~Code()
{
    //dtor
}
