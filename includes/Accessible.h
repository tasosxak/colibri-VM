/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Accessible.h
 * Author: tasosxak
 *
 * Created on February 11, 2018, 6:35 PM
 */

#ifndef ACCESSIBLE_H
#define ACCESSIBLE_H

#include <iostream>

enum Acc_type {PRIVATE_ACC,PUBLIC_ACC,PROTECTED_ACC};

class Accessible
{
    public:
        Accessible();
        Accessible(Acc_type ACC_FLAG);
        virtual ~Accessible();
        Acc_type get_acc();
        void set_acc(Acc_type accessor);

    protected:

    private:
        Acc_type ACC_FLAG;
};

#endif /* ACCESSIBLE_H */

