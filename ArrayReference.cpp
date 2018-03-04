/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayReference.cpp
 * Author: tasosxak
 * 
 * Created on February 11, 2018, 6:43 PM
 */

#include "ArrayReference.h"

ArrayReference::ArrayReference()
{
    //ctor
}

ArrayReference::ArrayReference(std::string name,Class* classdef, Array* obj,int dimension):Reference(name,classdef,obj)
{

this->dimension = dimension;

}

ArrayReference::~ArrayReference()
{
    //dtor
}
