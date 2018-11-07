/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Array.h
 * Author: tasosxak
 *
 * Created on February 11, 2018, 6:42 PM
 */

#ifndef ARRAY_H
#define ARRAY_H

#include "Data_Type.h"

class Array: public Data_Type
{
    public:
        Array(int length, int dimension);
        virtual ~Array();

        virtual Object* get_element(int index);
        virtual void set_element(int index, Object* obj);
        virtual void del_element(int index);
        virtual c_object next(CNIEnv* env, c_object c_obj) = 0;
        int get_length();
        int get_dimension();



    protected:
        Object** arr;
        int length;
        int index;
        int dimension;

    private:
};

#endif /* ARRAY_H */

