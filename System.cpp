/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   System.cpp
 * Author: tasosxak
 * 
 * Created on February 11, 2018, 7:03 PM
 */

#include "System.h"


hash_table* System::NATIVE_LIBRARIES;

System::System()
{
    //ctor
}

System::~System()
{
    //dtor
}

void System::init(){

   System::NATIVE_LIBRARIES = new hash_table();

}

void System::add_library(Library* lib)
{
    
    System::NATIVE_LIBRARIES->add(lib);

}

Native_Method_Signature* System::call_native_method(std::string libname, std::string methodname)
{

    symbol* lib = System::NATIVE_LIBRARIES->lookfor(libname);

    if(lib != NULL)
    {
        Native_Method_Signature* natm = (Native_Method_Signature*) lib->mht->lookfor(methodname);
        if(natm!=NULL)
        {

            return natm;

        }

    }
}


void System::print(CNIEnv* env,c_object obj){
    
    cout<<env->GetString(obj);
}



