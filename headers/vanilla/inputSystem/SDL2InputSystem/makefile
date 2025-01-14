## Vanilla module makefile

#Metadata
MODULE_TYPE = inputSystem
MODULE_NAME = SDL2InputSystem
STATIC_LIB = SDL2InputSystem.a
DYNAMIC_LIB = SDL2InputSystem.dll

# Setup
ROOT_DIR := $(realpath ../../../..)
CC = g++

HEADERS = $(ROOT_DIR)/headers/vanilla/$(MODULE_TYPE)/$(MODULE_NAME)/

HEADER_FOLDER = $(ROOT_DIR)/headers/

IMPLEMENTATIONS = $(ROOT_DIR)/implementations/vanilla/$(MODULE_TYPE)/$(MODULE_NAME)/

CORE_HEADERS = $(ROOT_DIR)/headers/core/$(MODULE_TYPE)/

LIBS = $(ROOT_DIR)/lib/
INCLUDE = $(ROOT_DIR)/include/

FLAGS = -I${HEADER_FOLDER} -I${INCLUDE}

DEBUG_FLAGS = -v -g -O0

LDFLAGS = `sdl2-config --libs`

#Objects
OBJS =  SDL2InputControllerBuilder.o \
		SDL2InputController.o \
		MouseManager.o \
		KeyboardManager.o \
		ControllerManager.o \
		SDL2AbstractEventHandler.o \
		SDL2AbstractMouseHandler.o \
		SDL2AbstractKeyboardHandler.o \
		SDL2MouseEventHandler.o \
		SDL2KeyboardEventHandler.o \
		SDL2EventHandlerTail.o \
		ButtonEvent.o \
		ButtonState.o \
		ControllerButton.o \
		ControllerAxis.o \
		KeyButton.o \
		MouseButton.o


#Entry points
dynamic : release_dynamic
static : release_static

dynamic_debug : debug_dynamic
static_debug :	debug_static

clean:
	del /f /q $(OBJS) 2>nul || true

clean_all:
	del /f /q $(OBJS) SDL2InputSystem.a SDL2InputSystem.so SDL2InputSystem.dll libSDL2InputSystem.lib 2>nul || true

debug:
	@echo "ROOT_DIR: $(ROOT_DIR)" \
    @echo "HEADERS: $(HEADERS)" \
	@echo "HEADERS_GENERAL: $(HEADER_FOLDER)" \
    @echo "IMPLEMENTATIONS: $(IMPLEMENTATIONS)" \

#Initial rules

release_dynamic : CFLAGS = -fPIC $(FLAGS)
release_dynamic : COUT = $(OUT)
release_dynamic : Main_dynamic

release_static : CFLAGS = $(FLAGS)
release_static : COUT = $(OUT)
release_static : Main_static

debug_dynamic : CFLAGS = -g -Og -fPIC $(FLAGS)
debug_dynamic : COUT = $(OUT_DEBUG)
debug_dynamic : Main_dynamic

debug_static : CFLAGS = -g -Og $(FLAGS)
debug_static : COUT = $(OUT_DEBUG)
debug_static : Main_static



Main_dynamic : ${OBJS}
	${CC} ${CFLAGS}  -shared -o ${DYNAMIC_LIB} -Wl,--out-implib,libSDL2InputSystem.lib ${OBJS} -mconsole  -L${LIBS} -Wall -lSDL2


Main_static : ${OBJS}
	ar rcs ${STATIC_LIB} ${OBJS}


#Object rules

SDL2InputControllerBuilder.o : 	${IMPLEMENTATIONS}SDL2InputControllerBuilder.cpp \
								${HEADERS}SDL2InputControllerBuilder.hpp \
								${HEADERS}SDL2InputController.hpp \
								${HEADERS}periferalManagement\AbstractMouseManager.hpp \
								${HEADERS}periferalManagement\AbstractKeyboardManager.hpp \
								${HEADERS}periferalManagement\AbstractControllerManager.hpp \
								${HEADERS}eventHandler\SDL2EventHandlerInterface.hpp \
								${HEADERS}eventHandler\SDL2Handler\concreteHandlers\SDL2ConcreteHandlers.hpp \
								${CORE_HEADERS}AbstractInputCommand.hpp 
							${CC} ${CFLAGS} -c ${IMPLEMENTATIONS}SDL2InputControllerBuilder.cpp




SDL2InputController.o :	${IMPLEMENTATIONS}SDL2InputController.cpp \
						${HEADERS}SDL2InputController.hpp \
						${HEADERS}periferalManagement\AbstractMouseManager.hpp \
						${HEADERS}periferalManagement\AbstractKeyboardManager.hpp \
						${HEADERS}periferalManagement\AbstractControllerManager.hpp \
						${HEADERS}eventHandler\SDL2EventHandlerInterface.hpp \
						${CORE_HEADERS}AbstractInputCommand.hpp
					${CC} ${CFLAGS} -c ${IMPLEMENTATIONS}SDL2InputController.cpp

ThreadSafeButtonManager.o : ${IMPLEMENTATIONS}periferalManagement\concreteManager\ThreadSafeButtonManager.cpp \
							${HEADERS}periferalManagement\concreteManager\ThreadSafeButtonManager.hpp \
							${HEADERS}periferalManagement\IButtonManager.hpp \
							${CORE_HEADERS}enums\ButtonState.hpp
						${CC} ${CFLAGS} -c ${IMPLEMENTATIONS}periferalManagement\concreteManager\ThreadSafeButtonManager.cpp

MouseManager.o : 	${IMPLEMENTATIONS}periferalManagement\concreteManager\MouseManager.cpp \
					${HEADERS}periferalManagement\concreteManager\MouseManager.hpp \
					${HEADERS}periferalManagement\AbstractControllerManager.hpp \
					${HEADERS}periferalManagement\IButtonManager.hpp 
				${CC} ${CFLAGS} -c ${IMPLEMENTATIONS}periferalManagement\concreteManager\MouseManager.cpp

KeyboardManager.o : ${IMPLEMENTATIONS}periferalManagement\concreteManager\KeyboardManager.cpp \
					${HEADERS}periferalManagement\concreteManager\KeyboardManager.hpp \
					${HEADERS}periferalManagement\AbstractKeyboardManager.hpp \
					${HEADERS}periferalManagement\IButtonManager.hpp 
				${CC} ${CFLAGS} -c ${IMPLEMENTATIONS}periferalManagement\concreteManager\KeyboardManager.cpp


ControllerManager.o : 	${IMPLEMENTATIONS}periferalManagement\concreteManager\ControllerManager.cpp \
						${HEADERS}periferalManagement\concreteManager\ControllerManager.hpp \
						${HEADERS}periferalManagement\AbstractControllerManager.hpp
					${CC} ${CFLAGS} -c ${IMPLEMENTATIONS}periferalManagement\concreteManager\ControllerManager.cpp

#event handler logic

SDL2AbstractEventHandler.o : 	${IMPLEMENTATIONS}eventHandler\SDL2AbstractEventHandler.cpp \
								${HEADERS}eventHandler\SDL2AbstractEventHandler.hpp \
								${HEADERS}eventHandler\SDL2EventHandlerInterface.hpp
						${CC} ${CFLAGS} -c ${IMPLEMENTATIONS}eventHandler\SDL2AbstractEventHandler.cpp


SDL2AbstractMouseHandler.o : 	${IMPLEMENTATIONS}eventHandler\SDL2Handler\SDL2AbstractMouseHandler.cpp \
								${HEADERS}eventHandler\SDL2Handler\SDL2AbstractMouseHandler.hpp \
								${HEADERS}periferalManagement\AbstractMouseManager.hpp \
								${HEADERS}eventHandler\SDL2AbstractEventHandler.hpp \
							   	${CORE_HEADERS}enums\KeyButton.hpp
						${CC} ${CFLAGS} -c ${IMPLEMENTATIONS}eventHandler\SDL2Handler\SDL2AbstractMouseHandler.cpp


SDL2AbstractKeyboardHandler.o : ${IMPLEMENTATIONS}eventHandler\SDL2Handler\SDL2AbstractKeyboardHandler.cpp \
								${HEADERS}eventHandler\SDL2Handler\SDL2AbstractKeyboardHandler.hpp \
								${HEADERS}periferalManagement\AbstractKeyboardManager.hpp \
								${HEADERS}eventHandler\SDL2AbstractEventHandler.hpp \
							   	${CORE_HEADERS}enums\KeyButton.hpp
						${CC} ${CFLAGS} -c ${IMPLEMENTATIONS}eventHandler\SDL2Handler\SDL2AbstractKeyboardHandler.cpp


SDL2AbstractControllerHandler.o : ${IMPLEMENTATIONS}eventHandler\SDL2Handler\SDL2AbstractControllerHandler.cpp \
								  ${HEADERS}eventHandler\SDL2Handler\SDL2AbstractControllerHandler.hpp \
								  ${HEADERS}periferalManagement/AbstractControllerManager.hpp \
								  ${HEADERS}eventHandler\SDL2AbstractEventHandler.hpp \
							   	  ${CORE_HEADERS}enums\Enums.hpp
						${CC} ${CFLAGS} -c ${IMPLEMENTATIONS}eventHandler\SDL2Handler\SDL2AbstractControllerHandler.cpp


SDL2MouseEventHandler.o : 	${IMPLEMENTATIONS}eventHandler\SDL2Handler\concreteHandler\SDL2MouseEventHandler.cpp \
							${HEADERS}eventHandler\SDL2Handler\concreteHandlers\SDL2MouseEventHandler.hpp \
							${HEADERS}eventHandler\SDL2Handler\SDL2AbstractMouseHandler.hpp 
						${CC} ${CFLAGS} -c ${IMPLEMENTATIONS}eventHandler\SDL2Handler\concreteHandler\SDL2MouseEventHandler.cpp


SDL2KeyboardEventHandler.o :   ${IMPLEMENTATIONS}eventHandler\SDL2Handler\concreteHandler\SDL2KeyboardEventHandler.cpp \
							   ${HEADERS}eventHandler\SDL2Handler\concreteHandlers\SDL2KeyboardEventHandler.hpp \
							   ${HEADERS}eventHandler\SDL2Handler\SDL2AbstractKeyboardHandler.hpp 
							${CC} ${CFLAGS} -c ${IMPLEMENTATIONS}eventHandler\SDL2Handler\concreteHandler\SDL2KeyboardEventHandler.cpp

SDL2ControllerEventHandler.o : ${IMPLEMENTATIONS}eventHandler\SDL2Handler\concreteHandler\SDL2ControllerEventHandler.cpp \
							   ${HEADERS}eventHandler\SDL2Handler\concreteHandlers\SDL2ControllerEventHandler.hpp \
							   ${HEADERS}eventHandler\SDL2Handler\SDL2AbstractControllerHandler.hpp \
							   ${HEADERS}periferalManagement/AbstractControllerManager.hpp \
							   ${CORE_HEADERS}enums\ControllerAxis.hpp \
							   ${CORE_HEADERS}enums\ControllerButton.hpp 
							${CC} ${CFLAGS} -c ${IMPLEMENTATIONS}eventHandler\SDL2Handler\concreteHandler\SDL2ControllerEventHandler.cpp


SDL2EventHandlerTail.o : ${IMPLEMENTATIONS}eventHandler\SDL2Handler\concreteHandler\SDL2EventHandlerTail.cpp \
					${HEADERS}eventHandler\SDL2Handler\concreteHandlers\SDL2EventHandlerTail.hpp \
					${HEADERS}eventHandler\SDL2AbstractEventHandler.hpp 
					${CC} ${CFLAGS} -c ${IMPLEMENTATIONS}eventHandler\SDL2Handler\concreteHandler\SDL2EventHandlerTail.cpp


#enums

ButtonEvent.o : ${ROOT_DIR}\implementations\core\inputSystem\Enums\ButtonEvent.cpp \
				${ROOT_DIR}\headers\core\inputSystem\Enums\ButtonEvent.hpp
				${CC} ${CFLAGS} -c ${ROOT_DIR}\implementations\core\inputSystem\Enums\ButtonEvent.cpp

ButtonState.o : ${ROOT_DIR}\implementations\core\inputSystem\Enums\ButtonState.cpp \
				${ROOT_DIR}\headers\core\inputSystem\Enums\ButtonState.hpp
				${CC} ${CFLAGS} -c ${ROOT_DIR}\implementations\core\inputSystem\Enums\ButtonState.cpp

ControllerButton.o : ${ROOT_DIR}\implementations\core\inputSystem\Enums\ControllerButton.cpp \
				${ROOT_DIR}\headers\core\inputSystem\Enums\ControllerButton.hpp
				${CC} ${CFLAGS} -c ${ROOT_DIR}\implementations\core\inputSystem\Enums\ControllerButton.cpp

ControllerAxis.o : ${ROOT_DIR}\implementations\core\inputSystem\Enums\ControllerAxis.cpp \
				${ROOT_DIR}\headers\core\inputSystem\Enums\ControllerAxis.hpp
				${CC} ${CFLAGS} -c ${ROOT_DIR}\implementations\core\inputSystem\Enums\ControllerAxis.cpp

KeyButton.o : ${ROOT_DIR}\implementations\core\inputSystem\Enums\KeyButton.cpp \
				${ROOT_DIR}\headers\core\inputSystem\Enums\KeyButton.hpp
				${CC} ${CFLAGS} -c ${ROOT_DIR}\implementations\core\inputSystem\Enums\KeyButton.cpp

MouseButton.o : ${ROOT_DIR}\implementations\core\inputSystem\Enums\MouseButton.cpp \
				${ROOT_DIR}\headers\core\inputSystem\Enums\MouseButton.hpp
				${CC} ${CFLAGS} -c ${ROOT_DIR}\implementations\core\inputSystem\Enums\MouseButton.cpp
