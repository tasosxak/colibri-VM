/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Modifier.h
 * Author: tasosxak
 *
 * Created on October 21, 2018, 1:56 PM
 */

#ifndef MODIFIER_H
#define MODIFIER_H

enum Mod_type {DEFAULT_MOD,ABSTRACT_MOD,FINAL_MOD};

class Modifier {
public:
    Modifier();
    Modifier(Mod_type modifier);
    Modifier(const Modifier& orig);
    virtual ~Modifier();
    Mod_type get_mod();
    void set_mod(Mod_type modifier);
    
private:
    Mod_type MOD_FLAG;

};

#endif /* MODIFIER_H */

