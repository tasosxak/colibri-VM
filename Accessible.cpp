/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Accessible.cpp
 * Author: tasosxak
 * 
 * Created on February 11, 2018, 6:37 PM
 */

#include "Accessible.h"

Accessible::Accessible()
{
    //ctor
}

Accessible:: Accessible(std::string ACC_FLAG)
{
    set_acc(ACC_FLAG);
}

Accessible:: Accessible(int ACC_FLAG)
{
    set_acc(ACC_FLAG);
}

Accessible::~Accessible()
{
    //dtor
}

int Accessible::get_acc(){

    return this->ACC_FLAG;

}

void Accessible::set_acc(int code) {

    ACC_FLAG = code;

}

void Accessible::set_acc(std::string name) {


    if(name == "public")
        ACC_FLAG = 0;
    else if(name == "protected")
        ACC_FLAG = 1;
    else if(name == "private")
        ACC_FLAG = 2;
    else if(name == "abstract")
        ACC_FLAG = 3;
    else if(name == "final")
        ACC_FLAG = 4;

}