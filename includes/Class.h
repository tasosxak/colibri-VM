/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Class.h
 * Author: tasosxak
 *
 * Created on February 11, 2018, 6:45 PM
 */

#ifndef CLASS_H
#define CLASS_H

#include "Accessible.h"
#include "Object.h"
#include "Modifier.h"

class Object;

class Class : public Object , public Accessible , public Modifier
{
    public:
        Class();
        Class(std::string name, Acc_type ACC_FLAG,Mod_type MOD_FLAG, Class* supercl);
        Class(Class* obj);
        virtual ~Class();
        std::string className();
        Object* createInstance();
        Class* getSuperClass();
        void setSuperClass(Class* supercl);
        

    protected:


    private:
        Class* superclass;


};

#endif /* CLASS_H */

