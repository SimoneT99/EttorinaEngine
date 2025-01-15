#include "..\headers\vanilla\inputSystem\SDL2InputSystem\eventHandler\SDL2Handler\concreteHandlers\SDL2KeyboardEventHandler.hpp"

bool SDL2KeyboardEventHandler::can_handle(SDL_Event event) const{
    SDL2_PRINT_FOR_DEBUG("Checking can_handle key handler...", false)
    return event.type == SDL_KEYDOWN || event.type == SDL_KEYUP;
};

void SDL2KeyboardEventHandler::concrete_handle(SDL_Event event) const{

    SDL2_PRINT_FOR_DEBUG("Handling a keybaord event...", false)

    switch (event.type) {
        case SDL_KEYDOWN :
            this->abstractKeyboardManager->press_button(this->convertSDLtoKeyButton(event.button.button));
            break;
        case SDL_KEYUP:
            this->abstractKeyboardManager->release_button(this->convertSDLtoKeyButton(event.button.button));
            break;
    }

};

