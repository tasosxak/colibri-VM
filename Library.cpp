/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Library.cpp
 * Author: tasosxak
 * 
 * Created on February 11, 2018, 6:56 PM
 */

#include "Library.h"

Library::Library(std::string name) : symbol(name) {
    this->mht = new hash_table();

}

Library::~Library() {
    //dtor
}

