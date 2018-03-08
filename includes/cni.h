/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cni.h
 * Author: tasosxak
 *
 * Created on February 11, 2018, 6:46 PM
 */

#ifndef CNI_H
#define CNI_H

#include <iostream>
#include <string>
#include "Native_Method_Signature.h"
#include "Library.h"


class _c_object { public: int oop_id = 0;};
class _c_class: public _c_object{};
class _c_string: public _c_object{};
class _c_int : public _c_object{};
class _c_double : public _c_object{};
class _c_float : public _c_object{};
class _c_field : public _c_object{};
class _c_bool : public _c_object{};

// CNI Types
typedef _c_object* c_object;
typedef _c_string* c_string;
typedef _c_class* c_class;
typedef _c_int* c_int;
typedef _c_double* c_double;
typedef _c_float* c_float;
typedef _c_field* c_field;
typedef _c_bool* c_bool;

struct CNINativeMethod {

std::string name;
std::string return_type;
void *native_function;

};

typedef struct CNINativeMethod CNINativeMethod;

struct CNINativeInterface;
struct CNIEnv;
struct _CNIHandlerBlock;


struct CNINativeInterface {

    c_int CNI_get_version() ;
    c_string CNI_newString(std::string str);
    c_int CNI_newInt(int num);
    c_bool CNI_newBool(bool b);
    c_string CNI_IntToString(c_object num);
    std::string CNI_GetString(c_object obj);
    int CNI_IntField(c_field field);
    c_field CNI_GetField(c_object obj , std::string fieldname);
    c_class get_super_class(CNIEnv *env, c_class sub);
   

};



struct CNIEnv {

    CNINativeInterface functions;

    c_int get_version() {

            return functions.CNI_get_version();
    }

    c_string newString(std::string str)  {

            return functions.CNI_newString(str);
           // return functions->CNI_newString(str);
    }
    
    c_int newInt(int num)  {

            return functions.CNI_newInt(num);
           
    }
    
    c_string IntToString(c_object num){
        
        return functions.CNI_IntToString(num);
    }
    std::string GetString(c_object obj){
        
        return functions.CNI_GetString(obj);
    }
    
    c_field GetField(c_object obj, std::string fieldname){
        
        return functions.CNI_GetField(obj,fieldname);
    }
    
    int IntField(c_field field){
        
        return functions.CNI_IntField(field);
    }

    c_bool newBool(bool b){
        
        return functions.CNI_newBool(b);
    }
    
    c_object method_signature(std::string name,std::string return_type, void* native_function);
    void RegisterNative(struct CNINativeMethod meth_sign[], int length, std::string classname);

  //  c_class get_super_class(CNIEnv *env, c_class sub){

          //  return functions->get_super_class(this,sub);
   // }

};

#endif /* CNI_H */

