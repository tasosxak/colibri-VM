/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Array.cpp
 * Author: tasosxak
 * 
 * Created on February 11, 2018, 6:42 PM
 */

#include "Array.h"

Array::Array()
{
    //ctor
}

Array::~Array()
{
    //dtor
}


int Array::get_length(){

 return length;
}

int Array::get_dimension(){

 return this->dimension;
}

 Object* Array::get_element(int index){}

void Array::set_element(int index, Object* obj){}

void Array::del_element(int index){}
