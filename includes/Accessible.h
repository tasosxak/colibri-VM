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

class Accessible
{
    public:
        Accessible();
        Accessible(std::string ACC_FLAG);
        Accessible(int ACC_FLAG);
        virtual ~Accessible();
        int get_acc();
        void set_acc(std::string name);
        void set_acc(int code);

    protected:

    private:
        int ACC_FLAG;
};

#endif /* ACCESSIBLE_H */

