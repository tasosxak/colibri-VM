#ifndef MATH_SQRT274D_H
#define  MATH_SQRT274D_H
#include "cni.h"
#include <math.h>

c_double math_sqrt274(CNIEnv* env,c_double dbl){
		
		return env->newDouble(sqrt(env->GetDouble(dbl)));
}		

 

#endif /*  MATH_SQRT274D_H */
