/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Error.h
 * Author: tasosxak
 *
 * Created on August 3, 2018, 1:27 AM
 */

#ifndef ERROR_H
#define ERROR_H

#include "Object.h"

class Error: public Object {
public:
    Error(std::string title, std::string message);
    c_string toString(CNIEnv* env, c_object obj);
    c_string get_message(CNIEnv* env, c_object obj);
    c_string get_title(CNIEnv* env, c_object obj);
    virtual ~Error();
private:
    std::string message;
    std::string title;

};

#endif /* ERROR_H */

