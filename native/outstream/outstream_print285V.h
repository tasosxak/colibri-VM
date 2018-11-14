#ifndef OUTSTREAM_PRINT285V_H
#define  OUTSTREAM_PRINT285V_H
#include "cni.h"

c_void outstream_print285(CNIEnv* env,c_string str){
		std::cout<<env->GetString(str)<<std::endl;
		return env->newVoid();
}		

 

#endif /*  OUTSTREAM_PRINT285V_H */
