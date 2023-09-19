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
#include "Class.h"
#include "Double.h"
#include "Float.h"

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

c_object CNINativeInterface::CNI_newObject(Object* obj) {

    c_object x = new _c_object();
    CNIHandlerBlock::addoop(x, obj);
    return x;

}
c_int CNINativeInterface::CNI_newInt(int num) {


    Object * coral_int = (Object *) new Int(num);
    c_int x = new _c_int();
    CNIHandlerBlock::addoop(x, coral_int);
    return x;

}

c_double CNINativeInterface::CNI_newDouble(double dbl) {


    Object * coral_double = (Object *) new Double(dbl);
    c_double x = new _c_double();
    CNIHandlerBlock::addoop(x, coral_double);
    return x;

}

c_float CNINativeInterface::CNI_newFloat(float fl) {


    Object * coral_float = (Object *) new Float(fl);
    c_float x = new _c_float();
    CNIHandlerBlock::addoop(x, coral_float);
    return x;

}

c_void CNINativeInterface::CNI_newVoid() {


    Object * coral_void = new Object();
    c_void x = new _c_void();
    CNIHandlerBlock::addoop(x, coral_void);
    return x;

}

c_string CNINativeInterface::CNI_IntToString(c_int obj) {

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

std::string CNINativeInterface::CNI_GetString(c_string str) {


    Literal* lit = (Literal*) CNIHandlerBlock::resolve(str);

    return lit->getValue();

}

int CNINativeInterface::CNI_GetInt(c_int num) {


    Int* intt = (Int*) CNIHandlerBlock::resolve(num);

    return intt->getValue();

}

double CNINativeInterface::CNI_GetDouble(c_double dbl) {


    Double* doublee = (Double*) CNIHandlerBlock::resolve(dbl);

    return doublee->getValue();

}

float CNINativeInterface::CNI_GetFloat(c_float fl) {


    Float* floatt = (Float*) CNIHandlerBlock::resolve(fl);

    return floatt->getValue();

}


bool CNINativeInterface::CNI_GetBool(c_bool bl) {


    Int* booll = (Int*) CNIHandlerBlock::resolve(bl);

    return booll->getValue() == 1;

}


c_field CNINativeInterface::CNI_GetField(c_object obj, std::string fieldname) {

    Object* ob = (Object*) CNIHandlerBlock::resolve(obj);

    Field* field = (Field*) ob->mht->lookfor(fieldname);

    c_field cf = new _c_field();
    CNIHandlerBlock::addoop(cf, field);

    return cf;
}

void CNINativeInterface::CNI_SetIntVar(c_int obj, int val){
    
    Int* ob = (Int*) CNIHandlerBlock::resolve(obj);
    ob->setValue(val);
    return;
}
c_class CNINativeInterface::CNI_GetObjectClass(c_object obj) {

    Object* ob = (Object*) CNIHandlerBlock::resolve(obj);
    Class* cl = (Class*) ob->getClass();
    c_class cc = new _c_class();
    CNIHandlerBlock::addoop(cc, cl);

    return cc;
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


