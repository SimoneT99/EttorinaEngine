#include "..\headers\vanilla\inputSystem\SDL2InputSystem\eventHandler\SDL2Handler\SDL2AbstractControllerHandler.hpp"

/**
 * NODE: probably slow, might be optimized
 */

Enums::ControllerButton SDL2AbstractControllerHandler::convertSDLtoControllerButton(SDL_Keycode  sdlButton) const{
  switch (sdlButton) {
        case SDL_CONTROLLER_BUTTON_DPAD_UP : return Enums::ControllerButton::CONTROLLER_DPAD_UP;
        case SDL_CONTROLLER_BUTTON_DPAD_RIGHT : return Enums::ControllerButton::CONTROLLER_DPAD_RIGHT;
        case SDL_CONTROLLER_BUTTON_DPAD_DOWN : return Enums::ControllerButton::CONTROLLER_DPAD_DOWN;
        case SDL_CONTROLLER_BUTTON_DPAD_LEFT : return Enums::ControllerButton::CONTROLLER_DPAD_LEFT;

        case SDL_CONTROLLER_BUTTON_X : return Enums::ControllerButton::CONTROLLER_BUTTON_X;
        case SDL_CONTROLLER_BUTTON_Y : return Enums::ControllerButton::CONTROLLER_BUTTON_Y;
        case SDL_CONTROLLER_BUTTON_B : return Enums::ControllerButton::CONTROLLER_BUTTON_B;
        case SDL_CONTROLLER_BUTTON_A : return Enums::ControllerButton::CONTROLLER_BUTTON_A;

        case SDL_CONTROLLER_BUTTON_LEFTSTICK : return Enums::ControllerButton::CONTROLLER_LEFTSTICK;
        case SDL_CONTROLLER_BUTTON_RIGHTSTICK : return Enums::ControllerButton::CONTROLLER_RIGHTSTICK;

        case SDL_CONTROLLER_BUTTON_BACK : return Enums::ControllerButton::CONTROLLER_BACK;
        case SDL_CONTROLLER_BUTTON_START : return Enums::ControllerButton::CONTROLLER_START;

        case SDL_CONTROLLER_BUTTON_TOUCHPAD : return Enums::ControllerButton::CONTROLLER_TOUCHPAD;

        default : return Enums::ControllerButton::DEFAULT;
    }
}


Enums::ControllerAxis SDL2AbstractControllerHandler::convertSDLAxistoControllerButton(SDL_Keycode sdlAxis) const{
  switch (sdlAxis) {
        case SDL_CONTROLLER_AXIS_LEFTX : return Enums::ControllerAxis::CONTROLLER_LEFT_HORIZONTAL_AXIS;
        case SDL_CONTROLLER_AXIS_LEFTY : return Enums::ControllerAxis::CONTROLLER_LEFT_VERICAL_AXIS;
        case SDL_CONTROLLER_AXIS_RIGHTX : return Enums::ControllerAxis::CONTROLLER_RIGHT_HORIZONTAL_AXIS;
        case SDL_CONTROLLER_AXIS_RIGHTY : return Enums::ControllerAxis::CONTROLLER_RIGHT_VERICAL_AXIS;
        case SDL_CONTROLLER_AXIS_TRIGGERLEFT : return Enums::ControllerAxis::CONTROLLER_LEFT_TRIGGER_AXIS;
        case SDL_CONTROLLER_AXIS_TRIGGERRIGHT : return Enums::ControllerAxis::CONTROLLER_RIGHT_TRIGGER_AXIS;
        default : return Enums::ControllerAxis::DEFAULT;
    }
}
