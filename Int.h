/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Int.h
 * Author: tasosxak
 *
 * Created on February 11, 2018, 6:53 PM
 */

#ifndef INT_H
#define INT_H

#include "cni.h"
#include "Integer.h"

class Int : public Integer
{
    public:
        Int();
        Int(int value);
        Int(Int* symb);

        virtual ~Int();
       // Int(const std::string& name,int value);

        int getValue();
        void setValue(int value);

        c_string toString(CNIEnv* env, c_object obj);
        std::string className();

    protected:

    private:
        int value;

};

#endif /* INT_H */

