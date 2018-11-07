/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StopIterationException.cpp
 * Author: tasosxak
 * 
 * Created on August 3, 2018, 1:53 AM
 */

#include "StopIterationException.h"
#include "Exception.h"

StopIterationException::StopIterationException() : 
Exception("StopIterationException" ,
        "The iteration finished") {
}

StopIterationException::StopIterationException(const StopIterationException& orig) {
}

StopIterationException::~StopIterationException() {
}

