#ifndef OUTSTREAM_PRINT259V_H
#define  OUTSTREAM_PRINT259V_H
#include "cni.h"

c_void outstream_print259(CNIEnv* env,c_int integer){
		std::cout<<"KEKATOS"<< env->GetInt(integer)<<std::endl;
		return env->newVoid();
}		

 

#endif /*  OUTSTREAM_PRINT259V_H */
