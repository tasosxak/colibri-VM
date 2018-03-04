/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Reference.h
 * Author: tasosxak
 *
 * Created on February 11, 2018, 7:02 PM
 */

#ifndef REFERENCE_H
#define REFERENCE_H

#include <string>
#include "symbol.h"
#include "Numeric.h"
#include "Class.h"

class Reference: public Data_Type
{
    public:

        Reference();
        Reference(std::string name,Class* classdef, Object* obj);
        Reference(Reference* symb);
        virtual ~Reference();

        std::string getName(); //returns the name of reference
        std::string className();

        Class* getDynamicDef(); //returns the class of object
        Class* getStaticDef();
        Object* getPointer();

        void setStaticDef(Class* cls);
        void setPointer(Object* symb);




    protected:
        Class  *classRef;
        Object *pointer;

    private:

};
#endif /* REFERENCE_H */

