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
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Release
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Codes/ButtonEvents.o \
	${OBJECTDIR}/Codes/WrapperEvent.o \
	${OBJECTDIR}/Codes/MenuEvents.o \
	${OBJECTDIR}/Codes/KeyBoardEvents.o \
	${OBJECTDIR}/Codes/SAppContext.o \
	${OBJECTDIR}/Codes/ArrayList.o \
	${OBJECTDIR}/Codes/TesteMain.o \
	${OBJECTDIR}/Codes/NodeMoviment.o \
	${OBJECTDIR}/Codes/Player.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Release.mk dist/Release/GNU-Linux-x86/snake_3d

dist/Release/GNU-Linux-x86/snake_3d: ${OBJECTFILES}
	${MKDIR} -p dist/Release/GNU-Linux-x86
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/snake_3d ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/Codes/ButtonEvents.o: nbproject/Makefile-${CND_CONF}.mk Codes/ButtonEvents.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codes
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codes/ButtonEvents.o Codes/ButtonEvents.cpp

${OBJECTDIR}/Codes/WrapperEvent.o: nbproject/Makefile-${CND_CONF}.mk Codes/WrapperEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codes
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codes/WrapperEvent.o Codes/WrapperEvent.cpp

${OBJECTDIR}/Codes/MenuEvents.o: nbproject/Makefile-${CND_CONF}.mk Codes/MenuEvents.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codes
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codes/MenuEvents.o Codes/MenuEvents.cpp

${OBJECTDIR}/Codes/KeyBoardEvents.o: nbproject/Makefile-${CND_CONF}.mk Codes/KeyBoardEvents.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codes
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codes/KeyBoardEvents.o Codes/KeyBoardEvents.cpp

${OBJECTDIR}/Codes/SAppContext.o: nbproject/Makefile-${CND_CONF}.mk Codes/SAppContext.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codes
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codes/SAppContext.o Codes/SAppContext.cpp

${OBJECTDIR}/Codes/ArrayList.o: nbproject/Makefile-${CND_CONF}.mk Codes/ArrayList.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codes
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codes/ArrayList.o Codes/ArrayList.cpp

${OBJECTDIR}/Codes/TesteMain.o: nbproject/Makefile-${CND_CONF}.mk Codes/TesteMain.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codes
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codes/TesteMain.o Codes/TesteMain.cpp

${OBJECTDIR}/Codes/NodeMoviment.o: nbproject/Makefile-${CND_CONF}.mk Codes/NodeMoviment.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codes
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codes/NodeMoviment.o Codes/NodeMoviment.cpp

${OBJECTDIR}/Codes/Player.o: nbproject/Makefile-${CND_CONF}.mk Codes/Player.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codes
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codes/Player.o Codes/Player.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Release
	${RM} dist/Release/GNU-Linux-x86/snake_3d

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
