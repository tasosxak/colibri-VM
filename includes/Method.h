/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Method.h
 * Author: tasosxak
 *
 * Created on February 11, 2018, 6:58 PM
 */

#ifndef METHOD_H
#define METHOD_H

#include "Accessible.h"
#include "hash_table.h"
#include "Object.h"
#include "Content.h"
#include "Modifier.h"
#include <string>
#include <vector>

class Method : public Accessible, public Object, public Modifier
{
    public:
        Method(std::string name,Acc_type ACC_FLAG,Mod_type MOD_FLAG, std::string RTYPE);
        virtual ~Method();
        void set_rtype(std::string rtype);
        std::string get_rtype();
        bool native = false;
        int num_params = 0;
        std::vector <std::string> args;
        std::vector <std::string> args_names;
        std::string class_name;
        
        Content cn;

    protected:

    private:
        std::string rtype;

};

#endif /* METHOD_H */

