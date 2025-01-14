#include "../SDL2AbstractEventHandler.hpp"
#include "../../periferalManagement/AbstractKeyboardManager.hpp"
#include "../headers/core/inputSystem/Enums/KeyButton.hpp"

class SDL2AbstractKeyboardHandler : public SDL2AbstractEventHandler{

    protected:
        std::shared_ptr<AbstractKeyboardManager> abstractKeyboardManager;
        Enums::KeyButton convertSDLtoKeyButton(SDL_Keycode  sdlButton) const;

    public:
        SDL2AbstractKeyboardHandler(std::shared_ptr<AbstractKeyboardManager> abstractKeyboardManager) 
        : abstractKeyboardManager(abstractKeyboardManager) 
        {}
    
};