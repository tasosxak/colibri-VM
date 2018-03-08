/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Allocated_Object.h
 * Author: tasosxak
 *
 * Created on February 11, 2018, 6:37 PM
 */

#ifndef ALLOCATED_OBJECT_H
#define ALLOCATED_OBJECT_H

#include "Object.h"

class Allocated_Object
{
    public:
        Allocated_Object(Object* obj,int references);
        virtual ~Allocated_Object();
        void add_refer();
        void remove_refer();

        int get_age();
        int get_num_refer();

        void birthday();

    protected:

    private:
        Object* obj;
        int references;
        int age;
};

#endif /* ALLOCATED_OBJECT_H */

