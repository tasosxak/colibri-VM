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
	${OBJECTDIR}/Accessible.o \
	${OBJECTDIR}/Allocated_Object.o \
	${OBJECTDIR}/Array.o \
	${OBJECTDIR}/ArrayReference.o \
	${OBJECTDIR}/CNIHandlerBlock.o \
	${OBJECTDIR}/CVM.o \
	${OBJECTDIR}/CallableNativeFunction.o \
	${OBJECTDIR}/Class.o \
	${OBJECTDIR}/Code.o \
	${OBJECTDIR}/Data_Type.o \
	${OBJECTDIR}/Decimal.o \
	${OBJECTDIR}/Double.o \
	${OBJECTDIR}/Field.o \
	${OBJECTDIR}/Float.o \
	${OBJECTDIR}/Heap.o \
	${OBJECTDIR}/Int.o \
	${OBJECTDIR}/IntArray.o \
	${OBJECTDIR}/Integer.o \
	${OBJECTDIR}/Library.o \
	${OBJECTDIR}/Literal.o \
	${OBJECTDIR}/Memory_Manager.o \
	${OBJECTDIR}/Method.o \
	${OBJECTDIR}/Native_Method_Signature.o \
	${OBJECTDIR}/Numeric.o \
	${OBJECTDIR}/Object.o \
	${OBJECTDIR}/Primitive.o \
	${OBJECTDIR}/Reference.o \
	${OBJECTDIR}/System.o \
	${OBJECTDIR}/cni.o \
	${OBJECTDIR}/hash_table.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/symbol.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-rdynamic
CXXFLAGS=-rdynamic

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/coralvm

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/coralvm: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/coralvm ${OBJECTFILES} ${LDLIBSOPTIONS} -ldl

${OBJECTDIR}/Accessible.o: Accessible.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Accessible.o Accessible.cpp

${OBJECTDIR}/Allocated_Object.o: Allocated_Object.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Allocated_Object.o Allocated_Object.cpp

${OBJECTDIR}/Array.o: Array.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Array.o Array.cpp

${OBJECTDIR}/ArrayReference.o: ArrayReference.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ArrayReference.o ArrayReference.cpp

${OBJECTDIR}/CNIHandlerBlock.o: CNIHandlerBlock.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CNIHandlerBlock.o CNIHandlerBlock.cpp

${OBJECTDIR}/CVM.o: CVM.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CVM.o CVM.cpp

${OBJECTDIR}/CallableNativeFunction.o: CallableNativeFunction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CallableNativeFunction.o CallableNativeFunction.cpp

${OBJECTDIR}/Class.o: Class.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Class.o Class.cpp

${OBJECTDIR}/Code.o: Code.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Code.o Code.cpp

${OBJECTDIR}/Data_Type.o: Data_Type.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Data_Type.o Data_Type.cpp

${OBJECTDIR}/Decimal.o: Decimal.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Decimal.o Decimal.cpp

${OBJECTDIR}/Double.o: Double.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Double.o Double.cpp

${OBJECTDIR}/Field.o: Field.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Field.o Field.cpp

${OBJECTDIR}/Float.o: Float.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Float.o Float.cpp

${OBJECTDIR}/Heap.o: Heap.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Heap.o Heap.cpp

${OBJECTDIR}/Int.o: Int.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Int.o Int.cpp

${OBJECTDIR}/IntArray.o: IntArray.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IntArray.o IntArray.cpp

${OBJECTDIR}/Integer.o: Integer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Integer.o Integer.cpp

${OBJECTDIR}/Library.o: Library.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Library.o Library.cpp

${OBJECTDIR}/Literal.o: Literal.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Literal.o Literal.cpp

${OBJECTDIR}/Memory_Manager.o: Memory_Manager.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Memory_Manager.o Memory_Manager.cpp

${OBJECTDIR}/Method.o: Method.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Method.o Method.cpp

${OBJECTDIR}/Native_Method_Signature.o: Native_Method_Signature.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Native_Method_Signature.o Native_Method_Signature.cpp

${OBJECTDIR}/Numeric.o: Numeric.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Numeric.o Numeric.cpp

${OBJECTDIR}/Object.o: Object.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Object.o Object.cpp

${OBJECTDIR}/Primitive.o: Primitive.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Primitive.o Primitive.cpp

${OBJECTDIR}/Reference.o: Reference.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Reference.o Reference.cpp

${OBJECTDIR}/System.o: System.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/System.o System.cpp

${OBJECTDIR}/cni.o: cni.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/cni.o cni.cpp

${OBJECTDIR}/hash_table.o: hash_table.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hash_table.o hash_table.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/symbol.o: symbol.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -ldl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/symbol.o symbol.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/coralvm

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
