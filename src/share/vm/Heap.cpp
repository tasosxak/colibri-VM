/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Heap.cpp
 * Author: tasosxak
 * 
 * Created on February 11, 2018, 6:52 PM
 */

#include "Heap.h"
/*
Heap::Heap(long memory)
{

    this->num_baby_objects = 0;
    this->num_kid_objects = 0;
    this->num_teen_objects = 0;
    this->num_old_objects = 0;
    this->num_permanent_objects = 0;
    this->memory_space = this->max_memory_space = abs(memory);

    *baby_objects = (Allocated_Object*) malloc(sizeof(Allocated_Object)*(0.3*memory));
    *kid_objects =  (Allocated_Object*) malloc(sizeof(Allocated_Object)*(0.05*memory));
    *teen_objects =  (Allocated_Object*) malloc(sizeof(Allocated_Object)*(0.05*memory));
    *old_objects =   (Allocated_Object*) malloc(sizeof(Allocated_Object)*(0.4*memory));
    *permanent_objects =  (Allocated_Object*) malloc(sizeof(Allocated_Object)*(0.2*memory));

    this->max_num_baby_objects = 0.3*memory;
    this->max_num_kid_objects = 0.05*memory;
    this->max_num_teen_objects = 0.05*memory;
    this->max_num_old_objects = 0.4*memory;
    this->max_num_permanent_objects = 0.2*memory;

    //*FREE_SPACE = (bool*) malloc(sizeof(bool)*memory);

    //for(int i=0; i<memory; i++)
    // FREE_SPACE[i] = true;

}

Heap::~Heap()
{

    //dctor
}

int Heap::get_num_baby()
{

    return this->num_baby_objects;
}

int Heap::get_num_kid()
{

    return this->num_kid_objects;

}

int Heap::get_num_teen()
{

    return this->num_teen_objects;

}

int Heap::get_num_old()
{
    return this->num_old_objects;
}

int Heap::get_num_permanent()
{

    return this->num_permanent_objects;

}

Allocated_Object* Heap::get_baby(int index)
{

    return this->baby_objects[index];

}

Allocated_Object* Heap::get_kid(int index)
{

    return this->kid_objects[index];
}

Allocated_Object* Heap::get_teen(int index)
{

    return this->teen_objects[index];
}

Allocated_Object* Heap::get_old(int index)
{

    return this->old_objects[index];
}

Allocated_Object* Heap::get_permanent(int index)
{

    return this->permanent_objects[index];
}

int Heap::delete_baby(int index)
{

    //this->FREE_SPACE[index] == true;
    this->baby_objects[index] = NULL;

    if(num_baby_objects>0)
    {
        this->num_baby_objects --;
    }

    return 0;
}

int Heap::delete_kid(int index)
{

    // this->FREE_SPACE[index] == true;
    this->kid_objects[index] = NULL;

    if(num_kid_objects>0)
    {
        this->num_kid_objects --;
    }

    return 0;

}

int Heap::delete_teen(int index)
{

    // this->FREE_SPACE[index] == true;
    this->teen_objects[index] = NULL;

    if(num_teen_objects>0)
    {
        this->num_teen_objects --;
    }

    return 0;
}

int Heap::delete_old(int index)
{

    // this->FREE_SPACE[index] == true;
    this->old_objects[index] = NULL;

    if(num_old_objects>0)
    {
        this->num_old_objects --;
    }

    return 0;

}

int Heap::move_baby_to_kid(int index1,int index2)
{

    // if(this->FREE_SPACE[index1] == false)
    //  {
    Allocated_Object* moved_object = baby_objects[index1];
    baby_objects[index1] = NULL;
    // this->FREE_SPACE[index1] = true;

    // if(this->FREE_SPACE[index2] == true)
    //  {

    kid_objects[index2] = moved_object;
    // this->FREE_SPACE[index2] = false;
    //  }
    // }

    if(num_baby_objects>0)
    {
        this->num_baby_objects --;
        this->num_kid_objects ++;
    }

    return 0;

}

int Heap::move_kid_to_teen(int index1, int index2)
{

    // if(this->FREE_SPACE[index1] == false)
    //{
    Allocated_Object* moved_object = kid_objects[index1];
    kid_objects[index1] = NULL;
    //this->FREE_SPACE[index1] = true;

    //  if(this->FREE_SPACE[index2] == true)
    //  {

    teen_objects[index2] = moved_object;
    //this->FREE_SPACE[index2] = false;
    //    }
//   }

    if(num_baby_objects>0)
    {
        this->num_kid_objects --;
        this->num_teen_objects ++;
    }

    return 0;

}

int Heap::move_teen_to_kid(int index1, int index2)
{

    // if(this->FREE_SPACE[index1] == false)
//  {
    Allocated_Object* moved_object = teen_objects[index1];
    teen_objects[index1] = NULL;
    //  this->FREE_SPACE[index1] = true;

    //if(this->FREE_SPACE[index2] == true)
    //  {

    kid_objects[index2] = moved_object;
    //this->FREE_SPACE[index2] = false;
//}
//}

if(num_baby_objects>0)
{
    this->num_teen_objects --;
    this->num_kid_objects ++;
}

return 0;

}

int Heap::move_teen_to_old(int index1, int index2)
{

    //if(this->FREE_SPACE[index1] == false)
    //  {
    Allocated_Object* moved_object = teen_objects[index1];
    teen_objects[index1] = NULL;
    // this->FREE_SPACE[index1] = true;

    // if(this->FREE_SPACE[index2] == true)
    //{

    old_objects[index2] = moved_object;
    //  this->FREE_SPACE[index2] = false;
    //}
    // }

    if(num_baby_objects>0)
    {
        this->num_teen_objects --;
        this->num_old_objects ++;
    }

    return 0;

}

int Heap::move_old_to_permanent(int index1, int index2)
{

    //if(this->FREE_SPACE[index1] == false)
    // {
    Allocated_Object* moved_object = old_objects[index1];
    old_objects[index1] = NULL;
    //  this->FREE_SPACE[index1] = true;

    //if(this->FREE_SPACE[index2] == true)
    // {

    permanent_objects[index2] = moved_object;
    //this->FREE_SPACE[index2] = false;
    //}
    //}

    if(num_baby_objects>0)
    {
        this->num_old_objects --;
        this->num_permanent_objects ++;
    }

    return 0;

}

long Heap::get_memory_space()
{

    return this->memory_space;
}

long Heap::get_max_memory_space()
{

    return this->max_memory_space;
}


void Heap::add_memory_space(long memory)
{

    long mem = abs(memory);

    this->memory_space += mem;
    this->max_memory_space  += mem;

}

int Heap::add_baby_object(Allocated_Object* obj){

    for(int i=0; i<this->num_baby_objects; i++){


        if(this->baby_objects[i] == NULL){

            this->baby_objects[i] = obj;
            return i;
        }

    }

    return -1;

}
*/
