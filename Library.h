/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Library.h
 * Author: tasosxak
 *
 * Created on February 11, 2018, 6:56 PM
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include "symbol.h"

class Library: public symbol
{
    public:
        Library(std::string name);
        virtual ~Library();

    protected:

    private:


};


#endif /* LIBRARY_H */

