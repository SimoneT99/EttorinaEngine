#include "../SDL2AbstractMouseHandler.hpp"

class SDL2MouseEventHandler : public SDL2AbstractMouseHandler{

    protected:
        bool can_handle(SDL_Event event) const override;
        void concrete_handle(SDL_Event event) const override;

    public:
        SDL2MouseEventHandler(std::shared_ptr<AbstractMouseManager> abstractKeyboardManager) :
        SDL2AbstractMouseHandler(abstractKeyboardManager)
        {}

};