#include "cni.h"
#include "vs_stack.h"
#include "CNIHandlerBlock.h"
#include "Object.h"

/*
Class name: Object
Method name: equals
Return type: B

*/
extern "C" void   wrapper_Object_equalsB(CNIEnv* env, vs_stack<symbol> *stk){
	Object* par0 = (Object*) stk->pop();
	Object* par1 = (Object*) stk->pop();

	//Handle
	c_object cpar0 = new _c_object();
	CNIHandlerBlock::addoop(cpar0 ,par0);
	c_object cpar1 = new _c_object();
	CNIHandlerBlock::addoop(cpar1 ,par1);

	//Return
	c_bool ret = par0->equals(env ,cpar0 ,cpar1 );
	stk->push(CNIHandlerBlock::resolve(ret));

}