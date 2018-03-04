/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IntArray.h
 * Author: tasosxak
 *
 * Created on February 11, 2018, 6:54 PM
 */

#ifndef INTARRAY_H
#define INTARRAY_H

#include "Array.h"

class IntArray : public Array
{
    public:
        IntArray(int length,int dimension);
        virtual ~IntArray();

        Object* get_element(int index);
        void set_element(int index, Object* obj);
        void del_element(int index);


    protected:

    private:
};

#endif /* INTARRAY_H */

