/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   System.h
 * Author: tasosxak
 *
 * Created on February 11, 2018, 7:03 PM
 */

#ifndef SYSTEM_H
#define SYSTEM_H
//#define NUMBER_SYSTEM_CLASSES 20

#include <iostream>
#include "Library.h"
#include "cni.h"
#include "hash_table.h"
#include "CallableNativeFunction.h"

using namespace std;

class System
{
    public:

       //static void addSystemClass(Class* sclass);
       //static Class* searchSystemClass(std::string sclassname);
        static void add_library(Library* lib);
        static Native_Method_Signature* call_native_method(std::string libname, std::string methodname);
        static void init();
        static  /*std::map<std::string, CallableNativeFunction<void>>*/ hash_table* NATIVE_LIBRARIES;
        static void print(CNIEnv* env,c_object obj);
        static void read(CNIEnv* env, c_int ivar);
    protected:

    private:


        System();
        virtual ~System();
        //Class* SYSTEM_CLASSES[NUMBER_SYSTEM_CLASSES];

};
#endif /* SYSTEM_H */

