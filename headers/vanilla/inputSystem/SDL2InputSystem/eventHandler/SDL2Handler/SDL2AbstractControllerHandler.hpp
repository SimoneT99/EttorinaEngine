#include "../SDL2AbstractEventHandler.hpp"
#include "../headers/core/inputSystem/enums/Enums.hpp"
#include "../../periferalManagement/AbstractControllerManager.hpp"

class SDL2AbstractControllerHandler : public SDL2AbstractEventHandler
{

private:
  SDL_JoystickID controller_id;
  std::shared_ptr<AbstractControllerManager> abstractControllerManager;

  Enums::ControllerButton convertSDLtoControllerButton(SDL_Keycode sdlButton) const;
  Enums::ControllerAxis convertSDLAxistoControllerButton(SDL_Keycode sdlAxis) const;

public:
  SDL2AbstractControllerHandler(std::shared_ptr<AbstractControllerManager> abstractControllerManager, int controller_id)
      : abstractControllerManager(abstractControllerManager),
        controller_id(controller_id)
  {}
};