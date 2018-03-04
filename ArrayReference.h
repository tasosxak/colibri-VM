/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayReference.h
 * Author: tasosxak
 *
 * Created on February 11, 2018, 6:43 PM
 */

#ifndef ARRAYREFERENCE_H
#define ARRAYREFERENCE_H

#include "Reference.h"
#include "Array.h"

class ArrayReference: public Reference
{
    public:
        ArrayReference();
        ArrayReference(std::string name,Class* classdef, Array* obj,int dimension);
        virtual ~ArrayReference();



    protected:

    private:
        int dimension;

};

#endif /* ARRAYREFERENCE_H */

