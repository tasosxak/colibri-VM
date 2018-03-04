#include "cni.h"
#include "vs_stack.h"
#include "CNIHandlerBlock.h"
#include "Object.h"

/*
Class name: Object
Method name: toString
Return type: R

*/
extern "C" void   wrapper_Object_toStringR(CNIEnv* env, vs_stack<symbol> *stk){
	Object* par0 = (Object*) stk->pop();

	//Handle
	c_object cpar0 = new _c_object();
	CNIHandlerBlock::addoop(cpar0 ,par0);

	//Return
	c_object ret = par0->toString(env ,cpar0 );
	stk->push(CNIHandlerBlock::resolve(ret));

}