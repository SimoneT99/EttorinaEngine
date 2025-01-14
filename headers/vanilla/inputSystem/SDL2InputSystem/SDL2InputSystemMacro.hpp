#pragma once
#include <iostream>
#define DEBUG_SDL2_INPUT_SYSTEM true

#if DEBUG_SDL2_INPUT_SYSTEM
#define SDL2_PRINT_FOR_DEBUG(message, ignore) if(!ignore){std::cout << message <<std::endl;}
#elif
#define SDL2_PRINT_FOR_DEBUG(message, ignore)
#endif