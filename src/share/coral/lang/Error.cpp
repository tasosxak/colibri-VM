/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Error.cpp
 * Author: tasosxak
 * 
 * Created on August 3, 2018, 1:27 AM
 */

#include "Error.h"

Error::Error(std::string title, std::string message) {
    
    this->title = title;
    this->message = message;
}




c_string Error::toString(CNIEnv* env, c_object obj){
    
    return env->newString(this->title + ": " + this->message);
}

c_string Error::get_message(CNIEnv* env, c_object obj){
    
    return env->newString(this->message);
}

c_string Error::get_title(CNIEnv* env, c_object obj){
    
    return env->newString(this->title);
    
}
    
Error::~Error() {
}

