/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Exception.h
 * Author: tasosxak
 *
 * Created on August 3, 2018, 1:47 AM
 */

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "Error.h"

class Exception : public Error {
public:
    Exception(std::string title, std::string message);
    Exception(const Exception& orig);
    virtual ~Exception();
private:

};

#endif /* EXCEPTION_H */

