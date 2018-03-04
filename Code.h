/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Code.h
 * Author: tasosxak
 *
 * Created on February 11, 2018, 6:48 PM
 */

#ifndef CODE_H
#define CODE_H

#include <string>
#include "symbol.h"

class Code: public symbol
{
    public:
        Code();
        Code(const std::string& code);
        virtual ~Code();
        std::string className();
        std::string getCode();
    protected:

    private:
        std::string code;
};

#endif /* CODE_H */

