/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Data_Type.h
 * Author: tasosxak
 *
 * Created on February 11, 2018, 6:48 PM
 */

#ifndef DATA_TYPE_H
#define DATA_TYPE_H

#include "cni.h"
#include "Object.h"


class Data_Type : public Object
{
    public:
        Data_Type();
        Data_Type(std::string name);
        virtual ~Data_Type();
        //std::string className();


    protected:

    private:
};

#endif /* DATA_TYPE_H */

