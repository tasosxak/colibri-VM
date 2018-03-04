/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cni.cpp
 * Author: tasosxak
 * 
 * Created on February 11, 2018, 6:46 PM
 */

#include "cni.h"
#include "Object.h"
#include "Literal.h"
#include "Int.h"
#include "CNIHandlerBlock.h"
#include "Field.h"

c_int CNINativeInterface::CNI_get_version() {

    c_int x;

    return x;
}

c_string CNINativeInterface::CNI_newString(std::string str) {


    Object * coral_string = (Object *) new Literal(str);
    c_string x = new _c_string();
    CNIHandlerBlock::addoop(x, coral_string);
    return x;

}

c_int CNINativeInterface::CNI_newInt(int num) {


    Object * coral_int = (Object *) new Int(num);
    c_int x = new _c_int();
    CNIHandlerBlock::addoop(x, coral_int);
    return x;

}

c_string CNINativeInterface::CNI_IntToString(c_object obj) {

    Int* rs = (Int*) CNIHandlerBlock::resolve(obj);
    Object * coral_string;
    coral_string = (Object *) new Literal(std::to_string(rs->Int::getValue()));


    c_string x = new _c_string();
    CNIHandlerBlock::addoop(x, coral_string);
    return x;

}

c_bool CNINativeInterface::CNI_newBool(bool b) {

    int num = 0;
    if (b == true) num = 1;

    Object * coral_bool = (Object *) new Int(num);
    c_bool x = new _c_bool();
    CNIHandlerBlock::addoop(x, coral_bool);
    return x;
}

int CNINativeInterface::CNI_IntField(c_field field) {

    return ((Int*) ( ((Field*) CNIHandlerBlock::resolve(field))->get_data() ))->Int::getValue();

}

std::string CNINativeInterface::CNI_GetString(c_object obj) {


    Literal* lit = (Literal*) CNIHandlerBlock::resolve(obj);

    return lit->getValue();

}

c_field CNINativeInterface::CNI_GetField(c_object obj, std::string fieldname) {

    Object* ob = (Object*) CNIHandlerBlock::resolve(obj);

    Field* field = (Field*) ob->mht->lookfor(fieldname);

    c_field cf = new _c_field();
    CNIHandlerBlock::addoop(cf, field);

    return cf;
}

/*
c_object CNIEnv::method_signature(std::string name,std::string return_type, void* native_function){

    return  new Native_Method_Signature(name,return_type,native_function);
}
 */


void CNIEnv::RegisterNative(struct CNINativeMethod meth_sign[], int length, std::string classname) {
    /*
        Library* lib = new Library(classname);
    
        for(int i=0; i< length; i++)
        {
           Native_Method_Signature* nms = new Native_Method_Signature(meth_sign[i].name,meth_sign[i].return_type,meth_sign[i].native_function);

           lib->mht->add(nms);
        }
   
        System::add_library(lib);*/

}


