/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Allocated_Object.cpp
 * Author: tasosxak
 * 
 * Created on February 11, 2018, 6:37 PM
 */

#include "Allocated_Object.h"

Allocated_Object::Allocated_Object(Object* obj,int references){

this->references = references;
this->obj = obj;
this->age = 0;

}

void Allocated_Object::add_refer(){

this->references++;

}

void Allocated_Object::birthday(){

this->age++;
}


void Allocated_Object::remove_refer(){

this->age--;
}

int Allocated_Object::get_age(){

return this->age;
}

int Allocated_Object::get_num_refer(){

return this->references;
}


Allocated_Object::~Allocated_Object()
{
    //dtor
}

