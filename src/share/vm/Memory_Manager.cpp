/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Memory_Manager.cpp
 * Author: tasosxak
 * 
 * Created on February 11, 2018, 6:58 PM
 */

#include "Memory_Manager.h"

/*
Memory_Manager::Memory_Manager(long memory,int threshold)
{
    heap_memory = new Heap(memory);
    this->threshold = threshold;
}

Memory_Manager::~Memory_Manager()
{
    //dtor
}

;

void Memory_Manager::add_object(Object* obj){

 Allocated_Object* a_obj = new Allocated_Object(obj,0);

 if(heap_memory->max_num_baby_objects > heap_memory->get_num_baby()){

        int position = heap_memory->add_baby_object(a_obj);

        if(position >= 0){

                //a_obj->set_alloc(position);

        }
        else{

//            std::cout<<"Memory allocation problem";
     //       exit(1);

        }
 }
 else {

//    minor_garbage_collector();

 }
}

void Memory_Manager::minor_garbage_collector(){

    Allocated_Object* obj;

 for(int i=0; i< heap_memory->get_num_baby(); i++){

    obj = heap_memory->get_baby(i);

    if(obj->get_num_refer()>0){

        if(heap_memory->max_num_kid_objects >heap_memory->get_num_kid() ){
            heap_memory->move_baby_to_kid(obj);
        }
        else if(heap_memory->max_num_teen_objects >heap_memory->get_num_teen()){

             heap_memory->move_baby_to_teen(obj);
        }

        obj->birthday();

    }
    else{

        delete obj;

    }

 }

  for(int i=0; i< heap_memory->get_num_kid(); i++){

    obj = heap_memory->get_kid(i);

    if(obj->get_num_refer()>0){

        heap_memory->move_kid_to_teen(obj);
        obj->birthday();

    }
    else{

        delete obj;

    }

 }


}


void remove_object_reference(Object* obj){



}

*/