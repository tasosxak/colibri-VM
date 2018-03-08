/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Object.h
 * Author: tasosxak
 *
 * Created on February 11, 2018, 7:01 PM
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "symbol.h"
#include "vs_stack.h"
#include "cni.h"


class Object : public symbol
{
    public:
        Object();
        Object(std::string name);
        virtual ~Object();

        virtual Object*  getClass();
        virtual c_bool equals(CNIEnv* enc,c_object obj1, c_object obj2);
        //Native
        int getValue();
        virtual c_string toString(CNIEnv* env, c_object obj);
        void setClass(Object* classRef);
        static void RegisterNative(CNIEnv* env);
        
    protected:
        int object_id;


    private:
        Object* classRef;
};

#endif /* OBJECT_H */

