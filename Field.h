/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Field.h
 * Author: tasosxak
 *
 * Created on February 11, 2018, 6:50 PM
 */

#ifndef FIELD_H
#define FIELD_H

#include "Accessible.h"
#include "Data_Type.h"
#include "Object.h"


class Field : public Accessible, public Object
{
    public:
        Field(std::string name, std::string ACC_FLAG , Data_Type* data);
        Field(Field* field);
        virtual std::string className();
        virtual ~Field();
        Data_Type* get_data();
        void set_data(Data_Type* data);

    protected:

    private:
        Data_Type* data;
};

#endif /* FIELD_H */

