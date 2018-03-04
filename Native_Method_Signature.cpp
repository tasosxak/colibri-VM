/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Native_Method_Signature.cpp
 * Author: tasosxak
 * 
 * Created on February 11, 2018, 6:59 PM
 */

#include "Native_Method_Signature.h"

Native_Method_Signature::Native_Method_Signature(std::string name, std::string return_type, void *native_function): symbol(name)
{
    
   this->return_type = return_type;
   this->native_function = native_function;
}

Native_Method_Signature::~Native_Method_Signature()
{
    //dtor
}


std::string Native_Method_Signature::get_return_type(){

return this->return_type;
}

void* Native_Method_Signature::get_native_function() {

return this->native_function;
}
