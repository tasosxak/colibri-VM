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

IntArray::IntArray(int length,int dimension)
{
    this->arr = (Object**) new Int*[length];
    this->dimension = dimension;
    this->length = length;
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
