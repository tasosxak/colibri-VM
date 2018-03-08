/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Float.h
 * Author: tasosxak
 *
 * Created on February 11, 2018, 6:51 PM
 */

#ifndef FLOAT_H
#define FLOAT_H

#include "Decimal.h"


class Float : public Decimal
{
    public:
        Float();
        Float(float value);
        Float(Float* symb);

        virtual ~Float();

        //Float(const std::string& name,float value);

        float getValue();
        void setValue(float value);

        c_string toString();
        std::string className();

    protected:

    private:
        float value;
};

#endif /* FLOAT_H */

