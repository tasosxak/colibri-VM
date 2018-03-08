/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tasosxak
 * 
 * Created on February 11, 2018, 6:37 PM
 */

#include "CVM.h"
using namespace std;


int main()
{

    CVM* cvm = new CVM("in.cex");

    cvm->start();

    return 0;
}