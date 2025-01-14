#Makefile for the input system tester

# Root directory
ROOT_DIR := $(realpath ../..)

# Compiler and flags
CC = g++

HEADERS = $(ROOT_DIR)/headers/
IMPLEMENTATIONS = $(ROOT_DIR)/implementations/

OUT = ManualInputTester.exe
OUT_DEBUG = ManualInputTester_DB.exe

INCLUDE = $(ROOT_DIR)include
LIBS = $(ROOT_DIR)/lib

FLAGS = -I${HEADERS} -I${INCLUDE}

DEBUG_FLAGS = -g -O0

all : release_setup
debug : debug_setup

debug_setup : CFLAGS = -g -Og $(FLAGS)
debug_setup : COUT = $(OUT_DEBUG)
debug_setup : Main

release_setup : CFLAGS = $(FLAGS)
release_setup : COUT = $(OUT)
release_setup : Main


clean : 
	del $(OBJS) main.o

Main : MessageToTerminalCommand.o ManualInputTester.o InputSystem.o
	   @echo "Linking main..."
	   ${CC} ${CFLAGS} ManualInputTester.o MessageToTerminalCommand.o InputSystem.o -mconsole -L${LIBS}/ -llibSDL2InputSystem -o ${COUT}

ManualInputTester.o : ManualInputTester.cpp \
		 MessageToTerminalCommand.o
		${CC}  ${CFLAGS} -c ManualInputTester.cpp

MessageToTerminalCommand.o : MessageToTerminalCommand.hpp \
							 MessageToTerminalCommand.cpp \
							 ${HEADERS}\core\inputSystem\AbstractInputCommand.hpp
							 ${CC} ${CFLAGS} -c MessageToTerminalCommand.cpp		

InputSystem.o : ${IMPLEMENTATIONS}core/inputSystem/InputSystem.cpp \
				${HEADERS}core/inputSystem/AbstractInputControllerBuilder.hpp \
				${HEADERS}core/inputSystem/InputControllerInterface.hpp
				${CC} ${FLAGS} -c ${IMPLEMENTATIONS}core/inputSystem/InputSystem.cpp
