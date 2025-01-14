#include "../SDL2AbstractKeyboardHandler.hpp"

class SDL2KeyboardEventHandler : public SDL2AbstractKeyboardHandler{

    protected:
        bool can_handle(SDL_Event event) const override;
        void concrete_handle(SDL_Event event) const override;

    public:
        SDL2KeyboardEventHandler(std::shared_ptr<AbstractKeyboardManager> abstractKeyboardManager) :
        SDL2AbstractKeyboardHandler(abstractKeyboardManager)
        {}

};