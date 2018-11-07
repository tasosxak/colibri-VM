/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Package.cpp
 * Author: tasosxak
 * 
 * Created on August 30, 2018, 3:59 AM
 */

#include "Package.h"
#include "hash_table.h"
#include "symbol.h"

Package::Package(std::string name): symbol(name) {
    
    this->mht = new hash_table();
}

Package::Package(const Package& orig) {
}

Package::~Package() {
}


