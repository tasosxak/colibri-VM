/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CNIHandlerBlock.h
 * Author: tasosxak
 *
 * Created on February 11, 2018, 6:47 PM
 */

#ifndef CNIHANDLERBLOCK_H
#define CNIHANDLERBLOCK_H

#include "Object.h"
#include "cni.h"

class CNIHandlerBlock
{
public:

    static Object* oop[];
    static int top;
    static void addoop(c_object jobj, Object* realobj);

    static void remoop();
    static Object* resolve(c_object jobj);
    static void init();
    
protected:
    CNIHandlerBlock();
    virtual ~CNIHandlerBlock();
private:
};

#endif /* CNIHANDLERBLOCK_H */

