/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Frame.cpp
 * Author: tasosxak
 * 
 * Created on August 31, 2018, 9:12 PM
 */

#include "Frame.h"
#include <sstream>
#include <string>


Frame::Frame(Method* meth,Reference* params[],Call_type ct) {
    
    this->method = meth;
    this->ct = ct;
    this->params = new Block();
    
    for(int i=0; i< meth->num_params; i++){
        this->params->__def__(params[i]);
    }
    
    this->BLOCK_STACK_SIZE = 0;
    this->DATA_STACK = new vs_stack<Object>();
    this->BLOCK_STACK = new vs_stack<Block>();
}


void Frame::push_block(){
    
    this->BLOCK_STACK_SIZE++;
    this->BLOCK_STACK->push(new Block());
    return;
}

void Frame::pop_block(){
    
    this->BLOCK_STACK->pop();
    return;
}

void Frame::jump_to(std::string id){
    
    symbol* label = (symbol*) this->method->mht->lookfor(id);
    
    this->method->cn.__jump__(label->getLine());
}

std::vector<std::string> dott_splitter(std::string path){
    
    std::istringstream iss(path);
    std::vector<std::string> tokens;
    std::string token;
    
    while (std::getline(iss, token, '.')) {
    if (!token.empty())
        tokens.push_back(token);
    }
    
    return tokens;
}


Object* Frame::__load__(std::string id){
   
    Object* ld_obj;
    hash_table* cur_sb;
    std::vector<std::string> path;
    Block* b;
    
    path = dott_splitter(id);
    
    for(int i = this->BLOCK_STACK->esp(); i >=0; i--){

        b = this->BLOCK_STACK->see(i);
        ld_obj = b->get(path[0]);

        for(int j=1; j<path.size(); j++){

            if(ld_obj == NULL){

                break;
                
            }else{

                cur_sb = ld_obj->mht;

            }

            ld_obj = (Object*) cur_sb->lookfor(path[j]);

        }
        
        if(ld_obj != NULL){
            
            return ld_obj;
        }
    }
    
    ld_obj = this->params->get(id);
    return ld_obj;
}


void Frame::__def_var__(Object* symb){
    
    Object* ld_obj;
    
    ((Block*) this->BLOCK_STACK->see(this->BLOCK_STACK->esp()))->__def__(symb);
    
    return;
}

void Frame::__undef_var__(std::string id){
    
    Object* ld_obj;
    
    for(int i = this->BLOCK_STACK->esp(); i >=0; i--){
        
        Block* b = this->BLOCK_STACK->see(i);
        ld_obj = b->get(id);
        
        if(ld_obj != NULL){
            
            b->__undef__(ld_obj->getName());
            return;
        }
    }
    
    
    return;
}

Frame::Frame(const Frame& orig) {
}

Frame::~Frame() {
}

