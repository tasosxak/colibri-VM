/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IntArray.cpp
 * Author: tasosxak
 * 
 * Created on February 11, 2018, 6:54 PM
 */

#include "IntArray.h"
#include "Int.h"

IntArray::IntArray(int length,int dimension): Array(length,dimension)
{
    this->arr = (Object**) new Int*[length];
    
}

IntArray::~IntArray()
{
    //dtor
}

Object* IntArray::get_element(int index)
{

    if(index>=0 && index <= this->length - 1)
    {

        return this->arr[index];

    }
    else
    {

        //cout<<"IndexOutOfBounds";
        exit(1);
    }


}

void IntArray::set_element(int index, Object* obj)
{

    if(index>=0 && index <= length - 1)
    {

        this->arr[index] = obj;
     
    }
    else
    {

        //cout<<"IndexOutOfBounds";
        exit(1);
    }

}

void IntArray::del_element(int index)
{

    if(index>=0 && index <= length  - 1)
    {

        this->arr[index] = NULL;

    }
    else
    {

       // cout<<"ArrayOutOfBounds";
        exit(1);
    }

}


c_object IntArray::next(CNIEnv* env, c_object obj){
    
    
    if(this->index < (this->length)){
        
        return env->newInt( (this->arr[index])->getValue() );
    }
    
    this->index = 0;
    return env->newObject(new Object());
        
}
