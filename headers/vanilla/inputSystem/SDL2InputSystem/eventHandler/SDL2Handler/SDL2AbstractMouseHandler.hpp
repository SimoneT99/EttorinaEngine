#include "../SDL2AbstractEventHandler.hpp"
#include "../../periferalManagement/AbstractMouseManager.hpp"



class SDL2AbstractMouseHandler : public SDL2AbstractEventHandler{

    protected:
        std::shared_ptr<AbstractMouseManager> abstractMouseManager;
        Enums::MouseButton convertSDLtoMouseButton(Uint8 sdlButton) const;

    public:
        SDL2AbstractMouseHandler(std::shared_ptr<AbstractMouseManager> abstractMouseManager) 
        : abstractMouseManager(abstractMouseManager) 
        {}
};