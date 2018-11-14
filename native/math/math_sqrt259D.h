#ifndef MATH_SQRT259D_H
#define  MATH_SQRT259D_H
#include "cni.h"
#include <math.h>

c_double math_sqrt259(CNIEnv* env,c_int dbl){
		
		return env->newDouble(sqrt(env->GetInt(dbl)));
}		

 

#endif /*  MATH_SQRT274D_H */
