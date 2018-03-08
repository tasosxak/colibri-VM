/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Native_Method_Signature.h
 * Author: tasosxak
 *
 * Created on February 11, 2018, 6:59 PM
 */

#ifndef NATIVE_METHOD_SIGNATURE_H
#define NATIVE_METHOD_SIGNATURE_H

#include "symbol.h"

class Native_Method_Signature : public symbol
{
    public:
        Native_Method_Signature(std::string name, std::string return_type, void *native_function);
        virtual ~Native_Method_Signature();
        std::string get_return_type();
        void* get_native_function();

    protected:

    private:
        std::string return_type;
        void *native_function;
};

#endif /* NATIVE_METHOD_SIGNATURE_H */

