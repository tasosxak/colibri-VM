#ifndef PERSON_H
#define PERSON_H

#include "cni.h"

class Person : public Object
{
    public:
        void helloworld(CNIEnv* env, c_object obj){
		int x;
		printf("HELLO WORLD!");
		std::cin>>x;
		std::cout<<x;
	}

	c_int helloborld(CNIEnv* env, c_object obj){
		int x=665;
		
		return env->newInt(x);
	}
    protected:

    private:
        

};

#endif /* PERSON_H */

