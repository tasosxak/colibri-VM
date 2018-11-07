/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Modifier.cpp
 * Author: tasosxak
 * 
 * Created on October 21, 2018, 1:56 PM
 */

#include "Modifier.h"

Modifier::Modifier() {
}

Modifier::Modifier(const Modifier& orig) {
}

Modifier::~Modifier() {
}

Modifier::Modifier(Mod_type MOD_FLAG){
    
    this->MOD_FLAG = MOD_FLAG;
}

Mod_type Modifier::get_mod(){
    
    return this->MOD_FLAG;
}
       
void Modifier::set_mod(Mod_type modifier){
    
    this->MOD_FLAG = modifier;
    
}