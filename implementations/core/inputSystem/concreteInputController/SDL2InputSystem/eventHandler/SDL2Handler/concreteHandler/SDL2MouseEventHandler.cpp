#include "..\headers\core\inputSystem\SDL2InputSystem\eventHandler\SDL2Handler\concreteHandlers\SDL2MouseEventHandler.hpp"

bool SDL2MouseEventHandler::can_handle(SDL_Event event) const
{
    return event.type == SDL_MOUSEMOTION ||
           event.type == SDL_MOUSEBUTTONDOWN ||
           event.type == SDL_MOUSEBUTTONUP ||
           event.type == SDL_MOUSEWHEEL;
}

void SDL2MouseEventHandler::concrete_handle(SDL_Event event) const
{
    switch (event.type)
    {
    case SDL_MOUSEMOTION:
        this->abstractMouseManager->set_mouse_position(event.motion.x, event.motion.y);
        break;
    case SDL_MOUSEBUTTONDOWN:
        this->abstractMouseManager->press_button(this->convertSDLtoMouseButton(event.button.button));
        break;
    case SDL_MOUSEBUTTONUP:
        this->abstractMouseManager->press_button(this->convertSDLtoMouseButton(event.button.button));
        break;
    case SDL_MOUSEWHEEL:
        /**
         * NOTE: Might cause issues later
         */
        this->abstractMouseManager->update_mouse_wheel_delta(event.wheel.x, event.wheel.y);
        break;
    }
}
