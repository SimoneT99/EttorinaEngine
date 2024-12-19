#include "../SDL2AbstractMouseHandler.hpp"

class SDL2MouseEventHandler : public SDL2AbstractMouseHandler{

    protected:
        bool can_handle(SDL_Event event) const override;
        void concrete_handle(SDL_Event event) const override;

};