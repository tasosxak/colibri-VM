#ifndef OUTSTREAM_PRINT274V_H
#define  OUTSTREAM_PRINT274V_H
#include "cni.h"

c_void outstream_print274(CNIEnv* env,c_double dbl){
		std::cout<<env->GetDouble(dbl)<<std::endl;
		return env->newVoid();
}		

 

#endif /*  OUTSTREAM_PRINT274V_H */
