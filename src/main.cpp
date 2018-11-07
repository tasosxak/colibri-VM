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
#include <string>
#include <sstream>
using namespace std;


int main(int argc, char* argv[])
{
    std::ostringstream filename;
    filename << argv[1];
    
    CVM* cvm = new CVM(filename.str());

    cvm->start();

    return 0;
}