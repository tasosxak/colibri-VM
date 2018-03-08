/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "CNIHandlerBlock.h"

int CNIHandlerBlock::top = 0;
Object* CNIHandlerBlock::oop[31];

void CNIHandlerBlock::addoop(c_object jobj, Object* realobj) {
    
    jobj->oop_id = top;
    oop[top] = realobj;
    top++;

}

void CNIHandlerBlock::remoop() {
   
    top--;

}

Object* CNIHandlerBlock::resolve(c_object jobj) {
    
    return oop[jobj->oop_id];
}

void CNIHandlerBlock::init() {
   
}