/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Literal.h
 * Author: tasosxak
 *
 * Created on February 11, 2018, 6:57 PM
 */

#ifndef LITERAL_H
#define LITERAL_H

#include <string>
#include "Data_Type.h"
#include "cni.h"

class Literal : public Data_Type
{
    public:
        Literal();
        Literal(const std::string& value);
        Literal(Literal* symb);
        virtual ~Literal();

        std::string getValue();
        void setValue(const std::string& value);
        
        std::string className();
        
        c_object next(CNIEnv* env, c_object obj);
        c_string toString(CNIEnv* env, c_object obj);

    protected:

    private:
        int index;
        std::string value;

};

#endif /* LITERAL_H */

