/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vs_stack.h
 * Author: tasosxak
 *
 * Created on February 11, 2018, 7:03 PM
 */

#ifndef VS_STACK_H
#define VS_STACK_H

#include "symbol.h"

template <class X>
class vs_stack
{

    public:
        vs_stack();
        virtual ~vs_stack();
        X* pop();
        X* see(int index);
        template <class Y> void push(Y symb);
        int esp();
        void setesp(int newesp);
    protected:

    private:
        int counter;
        int LENGTH_ST;
        X* arr[65000];
};


#include "Code.h"

template <typename X>
vs_stack<X>::vs_stack()
{
    this->counter = -1;
    this->LENGTH_ST = 65000;
}




template <class X>
template <typename Y>
 void vs_stack<X>:: push(Y symb){

    if(counter < LENGTH_ST -1 ){

        this->arr[++counter] = symb;

    }
}

template <class X> X* vs_stack<X>::see(int index){

    if(index >= 0 && index < LENGTH_ST)
        return this->arr[index];

}

template <class X> X* vs_stack<X>::pop(){

    if(counter >= 0){

        return this->arr[counter--];
    }
}

template <class X>int vs_stack<X>::esp() {

    return this->counter;

}

template <class X>void vs_stack<X>::setesp(int newesp){

    this->counter = newesp;
}

template <class X>vs_stack<X>::~vs_stack()
{
    //dtor
}


 
#endif
