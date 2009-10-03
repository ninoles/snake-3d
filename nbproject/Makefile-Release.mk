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
	${OBJECTDIR}/Codes/GenericList/ArrayList.o \
	${OBJECTDIR}/Codes/TesteMain.o \
	${OBJECTDIR}/Codes/Events/ButtonEvents.o \
	${OBJECTDIR}/Codes/Events/MenuEvents.o \
	${OBJECTDIR}/Codes/Context/SAppContext.o \
	${OBJECTDIR}/Codes/Events/KeyBoardEvents.o \
	${OBJECTDIR}/Codes/Events/NodeMoviment.o \
	${OBJECTDIR}/Codes/Events/WrapperEvent.o \
	${OBJECTDIR}/Codes/Base/FrameMenu.o \
	${OBJECTDIR}/Codes/Player/GroupPlayers.o \
	${OBJECTDIR}/Codes/Player/Player.o \
	${OBJECTDIR}/Codes/Base/FrameSceneNode.o

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

${OBJECTDIR}/Codes/GenericList/ArrayList.o: nbproject/Makefile-${CND_CONF}.mk Codes/GenericList/ArrayList.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codes/GenericList
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codes/GenericList/ArrayList.o Codes/GenericList/ArrayList.cpp

${OBJECTDIR}/Codes/TesteMain.o: nbproject/Makefile-${CND_CONF}.mk Codes/TesteMain.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codes
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codes/TesteMain.o Codes/TesteMain.cpp

${OBJECTDIR}/Codes/Events/ButtonEvents.o: nbproject/Makefile-${CND_CONF}.mk Codes/Events/ButtonEvents.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codes/Events
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codes/Events/ButtonEvents.o Codes/Events/ButtonEvents.cpp

${OBJECTDIR}/Codes/Events/MenuEvents.o: nbproject/Makefile-${CND_CONF}.mk Codes/Events/MenuEvents.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codes/Events
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codes/Events/MenuEvents.o Codes/Events/MenuEvents.cpp

${OBJECTDIR}/Codes/Context/SAppContext.o: nbproject/Makefile-${CND_CONF}.mk Codes/Context/SAppContext.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codes/Context
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codes/Context/SAppContext.o Codes/Context/SAppContext.cpp

${OBJECTDIR}/Codes/Events/KeyBoardEvents.o: nbproject/Makefile-${CND_CONF}.mk Codes/Events/KeyBoardEvents.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codes/Events
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codes/Events/KeyBoardEvents.o Codes/Events/KeyBoardEvents.cpp

${OBJECTDIR}/Codes/Events/NodeMoviment.o: nbproject/Makefile-${CND_CONF}.mk Codes/Events/NodeMoviment.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codes/Events
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codes/Events/NodeMoviment.o Codes/Events/NodeMoviment.cpp

${OBJECTDIR}/Codes/Events/WrapperEvent.o: nbproject/Makefile-${CND_CONF}.mk Codes/Events/WrapperEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codes/Events
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codes/Events/WrapperEvent.o Codes/Events/WrapperEvent.cpp

${OBJECTDIR}/Codes/Base/FrameMenu.o: nbproject/Makefile-${CND_CONF}.mk Codes/Base/FrameMenu.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codes/Base
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codes/Base/FrameMenu.o Codes/Base/FrameMenu.cpp

${OBJECTDIR}/Codes/Player/GroupPlayers.o: nbproject/Makefile-${CND_CONF}.mk Codes/Player/GroupPlayers.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codes/Player
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codes/Player/GroupPlayers.o Codes/Player/GroupPlayers.cpp

${OBJECTDIR}/Codes/Player/Player.o: nbproject/Makefile-${CND_CONF}.mk Codes/Player/Player.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codes/Player
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codes/Player/Player.o Codes/Player/Player.cpp

${OBJECTDIR}/Codes/Base/FrameSceneNode.o: nbproject/Makefile-${CND_CONF}.mk Codes/Base/FrameSceneNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codes/Base
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codes/Base/FrameSceneNode.o Codes/Base/FrameSceneNode.cpp

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
