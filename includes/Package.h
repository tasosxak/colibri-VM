/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Package.h
 * Author: tasosxak
 *
 * Created on August 30, 2018, 3:59 AM
 */

#ifndef PACKAGE_H
#define PACKAGE_H

#include "symbol.h"
#include "vs_stack.h"
#include "Content.h"

class Package : public symbol {
public:
    Package(std::string);
    Package(const Package& orig);
    virtual ~Package();
    
    Content cn;
    
private:
    
};

#endif /* PACKAGE_H */

