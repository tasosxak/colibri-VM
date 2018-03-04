#include "cni.h"
#include "vs_stack.h"
#include "CNIHandlerBlock.h"
#include "Person.h"

/*
Class name: Person
Method name: helloworld
Return type: V

*/
extern "C" void   wrapper_Person_helloworldV(CNIEnv* env, vs_stack<symbol> *stk){
	Person* par0 = (Person*) stk->pop();

	//Handle
	c_object cpar0 = new _c_object();
	CNIHandlerBlock::addoop(cpar0 ,par0);

	//Return
par0->helloworld(env ,cpar0 );

}