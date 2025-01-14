#include "..\headers\vanilla\inputSystem\SDL2InputSystem\eventHandler\SDL2Handler\SDL2AbstractMouseHandler.hpp"

/**
 * BAD: SDL seems to not support over 6 buttons
 * BAD: Might be slow...
 */

Enums::MouseButton SDL2AbstractMouseHandler::convertSDLtoMouseButton(Uint8 sdlButton) const{
    switch (sdlButton) {
        case SDL_BUTTON_LEFT:   return Enums::MouseButton::MOUSE_LEFT;
        case SDL_BUTTON_MIDDLE: return Enums::MouseButton::MOUSE_MIDDLE;
        case SDL_BUTTON_RIGHT:  return Enums::MouseButton::MOUSE_RIGHT;
        case SDL_BUTTON_X1:     return Enums::MouseButton::MOUSE_4;
        case SDL_BUTTON_X2:     return Enums::MouseButton::MOUSE_5;
        default:                return Enums::MouseButton::MOUSE_6;
    }
}