/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Class.cpp
 * Author: tasosxak
 * 
 * Created on February 11, 2018, 6:45 PM
 */

#include "Class.h"

Class::Class()
{
    //ctor
}

Class::Class(std::string name,std::string ACC_FLAG,Class* supercl):Object(name),Accessible(ACC_FLAG){

this->superclass = supercl;

}

Class::Class(Class* obj){

  if(obj != NULL){
   this->name = obj->getName();
   this->set_acc(obj->get_acc());
   this->mht = new hash_table(obj->mht);
  }
}

Object* Class::createInstance(){

    Class* supercl;

    Object* x = new Object();
    x->mht = new hash_table(this->mht);
    x->setClass(this);

    //Copy the fields of superclasses

    supercl = this->superclass;



    while(supercl != NULL){

        x->mht->clone(supercl->mht);

        supercl = supercl->getSuperClass();
    }

    return x;

}

std::string Class::className(){

return "Class";

}


Class* Class::getSuperClass() {

return this->superclass;

}

void Class::setSuperClass(Class* supercl){

this->superclass = supercl;

}


Class::~Class()
{
    //dtor
}

