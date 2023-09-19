#include "cni.h"
#include "vs_stack.h"
#include "CNIHandlerBlock.h"
#include "outstream_print259V.h"

/*
Module name: outstream
Function name: print259
Return type: V

*/
extern "C" void   wrapper_outstream_print259V(CNIEnv* env, vs_stack<symbol> *stk){
	 Object* par0 = (Object*) stk->pop();

	//Handle
	c_int cpar0 = new _c_int();
	CNIHandlerBlock::addoop(cpar0 ,par0);

	//Return
	c_void ret = outstream_print259(env ,cpar0 );
	stk->push(CNIHandlerBlock::resolve(ret));

}