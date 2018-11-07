/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StopIterationException.h
 * Author: tasosxak
 *
 * Created on August 3, 2018, 4:02 AM
 */

#ifndef STOPITERATIONEXCEPTION_H
#define STOPITERATIONEXCEPTION_H
#include "Exception.h"
class StopIterationException : public Exception {
public:
    StopIterationException();
    virtual ~StopIterationException();
private:

};

#endif /* STOPITERATIONEXCEPTION_H */

