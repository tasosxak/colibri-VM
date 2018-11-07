/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Field.cpp
 * Author: tasosxak
 * 
 * Created on February 11, 2018, 6:50 PM
 */

#include "Field.h"
#include "Int.h"
#include "Double.h"
#include "Literal.h"
#include "Reference.h"

Field::Field(std::string name,Acc_type ACC_FLAG , Data_Type* data): Object(name),Accessible(ACC_FLAG){

    set_data(data);
}

Field::Field(Field* field):Object(field->getName()),Accessible(field->get_acc()){



    std::string className = (field->get_data())->className();

    if(className == "Int"){

        Data_Type* x = field->get_data();
        Int* y = (Int*)x;
        set_data(new Int(y));
    }
    else if (className == "Double"){

        set_data(new Double((Double*)field->get_data()));
    }
    else if (className == "Literal"){

        Data_Type* x = field->get_data();
        Literal* y = (Literal*)x;
        set_data(new Literal(y));
    }
    else if (className == "Reference"){

        set_data(new Reference((Reference*)field->get_data()));
    }

}

Data_Type* Field::get_data(){

    return this->data;
}

void Field::set_data(Data_Type* data){

    this->data = data;
}


std::string Field::className(){

return "Field";
}

Field::~Field()
{
    //dtor
}