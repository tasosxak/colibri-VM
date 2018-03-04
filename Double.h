/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Double.h
 * Author: tasosxak
 *
 * Created on February 11, 2018, 6:50 PM
 */

#ifndef DOUBLE_H
#define DOUBLE_H

#include "Decimal.h"
#include "cni.h"

class Double : public Decimal
{
    public:
        Double();
        Double(double value);
        Double(Double* symb);

        virtual ~Double();

        //Double(const std::string& name,double value);
        std::string className();
        double getValue();

        void setValue(double value);
        c_string toString();

    protected:

    private:
        double value;
};

#endif /* DOUBLE_H */

