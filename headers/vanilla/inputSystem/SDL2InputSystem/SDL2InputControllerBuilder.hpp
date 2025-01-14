#include "../headers/core/inputSystem/AbstractInputControllerBuilder.hpp"
#include "./SDL2InputController.hpp"
#include "./periferalManagement\concreteManager\MouseManager.hpp"
#include "./periferalManagement\concreteManager\KeyboardManager.hpp"
#include "./periferalManagement\concreteManager\ControllerManager.hpp"
#include ".\eventHandler\SDL2EventHandlerInterface.hpp"
#include "./eventHandler\SDL2Handler\concreteHandlers\SDL2ConcreteHandlers.hpp"
#include "./periferalManagement/concreteManager/ThreadSafeButtonManager.hpp"
#include <memory>

class SDL2InputControllerBuilder : public AbstractInputControllerBuilder{

    public:
    std::shared_ptr<InputControllerInterface> get_input_controller_interface() override;

};