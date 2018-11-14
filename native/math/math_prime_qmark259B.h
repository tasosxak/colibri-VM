#ifndef MATH_PRIME_QMARK259B_H
#define  MATH_PRIME_QMARK259B_H
#include "cni.h"
#include <math.h>

c_bool math_prime_qmark259(CNIEnv* env,c_int num){
		
		int x = env->GetInt(num);
 		int flag = 0;
		for(int i=2; i<=x/2; ++i){

			// condition for nonprime number
	      	  	if(x%i==0){
		  		return env->newBool(false);
	       		 }
	   	 }
		
		return env->newBool(true);
}		

 

#endif /*   MATH_PRIME_QMARK259B_H*/
