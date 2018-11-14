#ifndef MATH_SIN274D_H
#define  MATH_SIN274D_H
#include "cni.h"
#include <math.h>
#define PI 3.14159265

c_double math_sin274(CNIEnv* env,c_double num){
		
		return env->newDouble(sin( ((env->GetDouble(num))*PI)/180 ));
}		

 

#endif /*  MATH_SIN274D_H */
