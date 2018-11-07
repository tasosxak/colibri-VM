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

Accessible:: Accessible(Acc_type ACC_FLAG)
{
    set_acc(ACC_FLAG);
}

Accessible::~Accessible()
{
    //dtor
}

Acc_type Accessible::get_acc(){

    return this->ACC_FLAG;

}


void Accessible::set_acc(Acc_type accessor) {

    this->ACC_FLAG = accessor;

}