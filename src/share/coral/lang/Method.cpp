/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Method.cpp
 * Author: tasosxak
 * 
 * Created on February 11, 2018, 6:58 PM
 */

#include "Method.h"

Method::Method(std::string name,std::string ACC_FLAG, std::string RTYPE):Object(name),Accessible(ACC_FLAG)
{

    set_rtype(RTYPE);
    //this->args = new std::vector<std::string*>();
}

void Method::set_rtype(std::string rtype){

    this->rtype = rtype;
}

std::string Method::get_rtype(){

    return rtype;
}



Method::~Method()
{
    //dtor
}

