/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Object.cpp
 * Author: tasosxak
 * 
 * Created on February 11, 2018, 7:01 PM
 */

#include "Object.h"

/*
static CNINativeMethod methods[] = {
    {"toString", "()V", (void *) & Object::toString}
};*/

Object::Object() {
    //ctor
}

Object::Object(std::string name) : symbol(name) {
    //ctor
}

Object::~Object() {
    //dtor
}

 Object* Object::getClass() {

    //native_stack->push(this->classRef);

    return this->classRef;

}
 
c_bool Object::equals(CNIEnv* env, c_object obj1, c_object obj2){
    
    
    bool eq = env->IntField(env->GetField(obj1, "objectid")) == env->IntField(env->GetField(obj2, "objectid"));
    
    return env->newBool(eq);
}

int Object::getValue(){
    
     return this->object_id;
 }
void Object::setClass(Object* classRef) {

    this->classRef = classRef;
}

/*
void Object::wrapper_Object_toStringV(CNIEnv* env, vs_stack<symbol> *stk){
    
    Object* obj = (Object*) stk->pop();
    
    //Handle
    c_object cobj = new _c_object();
    CNIHandlerBlock::addoop(cobj ,obj);
    
    //Return
    c_string ret = toString(env,cobj);
    
    stk->push(CNIHandlerBlock::resolve(ret));
    
    
}*/

 c_string Object::toString(CNIEnv* env, c_object obj) {

   
    return env->newString("Object");

}
/*
void Object::RegisterNative(CNIEnv* env) {

    env->RegisterNative(methods, 1, "Object");


}*/
