#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/share/coral/lang/Accessible.o \
	${OBJECTDIR}/src/share/coral/lang/Array.o \
	${OBJECTDIR}/src/share/coral/lang/ArrayReference.o \
	${OBJECTDIR}/src/share/coral/lang/Class.o \
	${OBJECTDIR}/src/share/coral/lang/Data_Type.o \
	${OBJECTDIR}/src/share/coral/lang/Decimal.o \
	${OBJECTDIR}/src/share/coral/lang/Double.o \
	${OBJECTDIR}/src/share/coral/lang/Error.o \
	${OBJECTDIR}/src/share/coral/lang/Exception.o \
	${OBJECTDIR}/src/share/coral/lang/Field.o \
	${OBJECTDIR}/src/share/coral/lang/Float.o \
	${OBJECTDIR}/src/share/coral/lang/Int.o \
	${OBJECTDIR}/src/share/coral/lang/IntArray.o \
	${OBJECTDIR}/src/share/coral/lang/Integer.o \
	${OBJECTDIR}/src/share/coral/lang/Library.o \
	${OBJECTDIR}/src/share/coral/lang/Literal.o \
	${OBJECTDIR}/src/share/coral/lang/Method.o \
	${OBJECTDIR}/src/share/coral/lang/Modifier.o \
	${OBJECTDIR}/src/share/coral/lang/Numeric.o \
	${OBJECTDIR}/src/share/coral/lang/Object.o \
	${OBJECTDIR}/src/share/coral/lang/Primitive.o \
	${OBJECTDIR}/src/share/coral/lang/StopIterationException.o \
	${OBJECTDIR}/src/share/coral/lang/System.o \
	${OBJECTDIR}/src/share/coral/lang/symbol.o \
	${OBJECTDIR}/src/share/vm/Allocated_Object.o \
	${OBJECTDIR}/src/share/vm/Block.o \
	${OBJECTDIR}/src/share/vm/CNIHandlerBlock.o \
	${OBJECTDIR}/src/share/vm/CVM.o \
	${OBJECTDIR}/src/share/vm/CallableNativeFunction.o \
	${OBJECTDIR}/src/share/vm/Code.o \
	${OBJECTDIR}/src/share/vm/Content.o \
	${OBJECTDIR}/src/share/vm/Frame.o \
	${OBJECTDIR}/src/share/vm/Heap.o \
	${OBJECTDIR}/src/share/vm/Memory_Manager.o \
	${OBJECTDIR}/src/share/vm/Native_Method_Signature.o \
	${OBJECTDIR}/src/share/vm/Package.o \
	${OBJECTDIR}/src/share/vm/Reference.o \
	${OBJECTDIR}/src/share/vm/cni.o \
	${OBJECTDIR}/src/share/vm/hash_table.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-rdynamic -I includes
CXXFLAGS=-rdynamic -I includes

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/colibrivm

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/colibrivm: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/colibrivm ${OBJECTFILES} ${LDLIBSOPTIONS} -ldl

${OBJECTDIR}/src/main.o: src/main.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/src/share/coral/lang/Accessible.o: src/share/coral/lang/Accessible.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/share/coral/lang
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/coral/lang/Accessible.o src/share/coral/lang/Accessible.cpp

${OBJECTDIR}/src/share/coral/lang/Array.o: src/share/coral/lang/Array.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/share/coral/lang
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/coral/lang/Array.o src/share/coral/lang/Array.cpp

${OBJECTDIR}/src/share/coral/lang/ArrayReference.o: src/share/coral/lang/ArrayReference.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/share/coral/lang
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/coral/lang/ArrayReference.o src/share/coral/lang/ArrayReference.cpp

${OBJECTDIR}/src/share/coral/lang/Class.o: src/share/coral/lang/Class.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/share/coral/lang
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/coral/lang/Class.o src/share/coral/lang/Class.cpp

${OBJECTDIR}/src/share/coral/lang/Data_Type.o: src/share/coral/lang/Data_Type.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/share/coral/lang
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/coral/lang/Data_Type.o src/share/coral/lang/Data_Type.cpp

${OBJECTDIR}/src/share/coral/lang/Decimal.o: src/share/coral/lang/Decimal.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/share/coral/lang
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/coral/lang/Decimal.o src/share/coral/lang/Decimal.cpp

${OBJECTDIR}/src/share/coral/lang/Double.o: src/share/coral/lang/Double.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/share/coral/lang
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/coral/lang/Double.o src/share/coral/lang/Double.cpp

${OBJECTDIR}/src/share/coral/lang/Error.o: src/share/coral/lang/Error.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/share/coral/lang
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/coral/lang/Error.o src/share/coral/lang/Error.cpp

${OBJECTDIR}/src/share/coral/lang/Exception.o: src/share/coral/lang/Exception.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/share/coral/lang
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/coral/lang/Exception.o src/share/coral/lang/Exception.cpp

${OBJECTDIR}/src/share/coral/lang/Field.o: src/share/coral/lang/Field.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/share/coral/lang
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/coral/lang/Field.o src/share/coral/lang/Field.cpp

${OBJECTDIR}/src/share/coral/lang/Float.o: src/share/coral/lang/Float.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/share/coral/lang
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/coral/lang/Float.o src/share/coral/lang/Float.cpp

${OBJECTDIR}/src/share/coral/lang/Int.o: src/share/coral/lang/Int.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/share/coral/lang
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/coral/lang/Int.o src/share/coral/lang/Int.cpp

${OBJECTDIR}/src/share/coral/lang/IntArray.o: src/share/coral/lang/IntArray.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/share/coral/lang
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/coral/lang/IntArray.o src/share/coral/lang/IntArray.cpp

${OBJECTDIR}/src/share/coral/lang/Integer.o: src/share/coral/lang/Integer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/share/coral/lang
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/coral/lang/Integer.o src/share/coral/lang/Integer.cpp

${OBJECTDIR}/src/share/coral/lang/Library.o: src/share/coral/lang/Library.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/share/coral/lang
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/coral/lang/Library.o src/share/coral/lang/Library.cpp

${OBJECTDIR}/src/share/coral/lang/Literal.o: src/share/coral/lang/Literal.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/share/coral/lang
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/coral/lang/Literal.o src/share/coral/lang/Literal.cpp

${OBJECTDIR}/src/share/coral/lang/Method.o: src/share/coral/lang/Method.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/share/coral/lang
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/coral/lang/Method.o src/share/coral/lang/Method.cpp

${OBJECTDIR}/src/share/coral/lang/Modifier.o: src/share/coral/lang/Modifier.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/share/coral/lang
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/coral/lang/Modifier.o src/share/coral/lang/Modifier.cpp

${OBJECTDIR}/src/share/coral/lang/Numeric.o: src/share/coral/lang/Numeric.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/share/coral/lang
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/coral/lang/Numeric.o src/share/coral/lang/Numeric.cpp

${OBJECTDIR}/src/share/coral/lang/Object.o: src/share/coral/lang/Object.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/share/coral/lang
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/coral/lang/Object.o src/share/coral/lang/Object.cpp

${OBJECTDIR}/src/share/coral/lang/Primitive.o: src/share/coral/lang/Primitive.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/share/coral/lang
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/coral/lang/Primitive.o src/share/coral/lang/Primitive.cpp

${OBJECTDIR}/src/share/coral/lang/StopIterationException.o: src/share/coral/lang/StopIterationException.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/share/coral/lang
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/coral/lang/StopIterationException.o src/share/coral/lang/StopIterationException.cpp

${OBJECTDIR}/src/share/coral/lang/System.o: src/share/coral/lang/System.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/share/coral/lang
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/coral/lang/System.o src/share/coral/lang/System.cpp

${OBJECTDIR}/src/share/coral/lang/symbol.o: src/share/coral/lang/symbol.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/share/coral/lang
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/coral/lang/symbol.o src/share/coral/lang/symbol.cpp

${OBJECTDIR}/src/share/vm/Allocated_Object.o: src/share/vm/Allocated_Object.cpp
	${MKDIR} -p ${OBJECTDIR}/src/share/vm
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/vm/Allocated_Object.o src/share/vm/Allocated_Object.cpp

${OBJECTDIR}/src/share/vm/Block.o: src/share/vm/Block.cpp
	${MKDIR} -p ${OBJECTDIR}/src/share/vm
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/vm/Block.o src/share/vm/Block.cpp

${OBJECTDIR}/src/share/vm/CNIHandlerBlock.o: src/share/vm/CNIHandlerBlock.cpp
	${MKDIR} -p ${OBJECTDIR}/src/share/vm
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/vm/CNIHandlerBlock.o src/share/vm/CNIHandlerBlock.cpp

${OBJECTDIR}/src/share/vm/CVM.o: src/share/vm/CVM.cpp
	${MKDIR} -p ${OBJECTDIR}/src/share/vm
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/vm/CVM.o src/share/vm/CVM.cpp

${OBJECTDIR}/src/share/vm/CallableNativeFunction.o: src/share/vm/CallableNativeFunction.cpp
	${MKDIR} -p ${OBJECTDIR}/src/share/vm
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/vm/CallableNativeFunction.o src/share/vm/CallableNativeFunction.cpp

${OBJECTDIR}/src/share/vm/Code.o: src/share/vm/Code.cpp
	${MKDIR} -p ${OBJECTDIR}/src/share/vm
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/vm/Code.o src/share/vm/Code.cpp

${OBJECTDIR}/src/share/vm/Content.o: src/share/vm/Content.cpp
	${MKDIR} -p ${OBJECTDIR}/src/share/vm
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/vm/Content.o src/share/vm/Content.cpp

${OBJECTDIR}/src/share/vm/Frame.o: src/share/vm/Frame.cpp
	${MKDIR} -p ${OBJECTDIR}/src/share/vm
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/vm/Frame.o src/share/vm/Frame.cpp

${OBJECTDIR}/src/share/vm/Heap.o: src/share/vm/Heap.cpp
	${MKDIR} -p ${OBJECTDIR}/src/share/vm
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/vm/Heap.o src/share/vm/Heap.cpp

${OBJECTDIR}/src/share/vm/Memory_Manager.o: src/share/vm/Memory_Manager.cpp
	${MKDIR} -p ${OBJECTDIR}/src/share/vm
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/vm/Memory_Manager.o src/share/vm/Memory_Manager.cpp

${OBJECTDIR}/src/share/vm/Native_Method_Signature.o: src/share/vm/Native_Method_Signature.cpp
	${MKDIR} -p ${OBJECTDIR}/src/share/vm
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/vm/Native_Method_Signature.o src/share/vm/Native_Method_Signature.cpp

${OBJECTDIR}/src/share/vm/Package.o: src/share/vm/Package.cpp
	${MKDIR} -p ${OBJECTDIR}/src/share/vm
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/vm/Package.o src/share/vm/Package.cpp

${OBJECTDIR}/src/share/vm/Reference.o: src/share/vm/Reference.cpp
	${MKDIR} -p ${OBJECTDIR}/src/share/vm
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/vm/Reference.o src/share/vm/Reference.cpp

${OBJECTDIR}/src/share/vm/cni.o: src/share/vm/cni.cpp
	${MKDIR} -p ${OBJECTDIR}/src/share/vm
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/vm/cni.o src/share/vm/cni.cpp

${OBJECTDIR}/src/share/vm/hash_table.o: src/share/vm/hash_table.cpp
	${MKDIR} -p ${OBJECTDIR}/src/share/vm
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/share/vm/hash_table.o src/share/vm/hash_table.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
