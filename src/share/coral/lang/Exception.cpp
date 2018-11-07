/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Exception.cpp
 * Author: tasosxak
 * 
 * Created on August 3, 2018, 1:47 AM
 */

#include "Exception.h"

Exception::Exception(std::string title, std::string message) : Error(title,message) {
    
    
}


Exception::~Exception() {
}

