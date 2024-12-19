#include "../headers\core\inputSystem\SDL2InputSystem\SDL2InputControllerBuilder.hpp"
#include "../headers\core\inputSystem\SDL2InputSystem\SDL2InputController.hpp"
#include "../headers\core\inputSystem\SDL2InputSystem\periferalManagement\concreteManager\MouseManager.hpp"
#include "../headers\core\inputSystem\SDL2InputSystem\periferalManagement\concreteManager\KeyboardManager.hpp"
#include "../headers\core\inputSystem\SDL2InputSystem\periferalManagement\concreteManager\ControllerManager.hpp"
#include "../headers\core\inputSystem\SDL2InputSystem\eventHandler\SDL2EventHandlerInterface.hpp"
#include "../headers\core\inputSystem\SDL2InputSystem\eventHandler\SDL2Handler\concreteHandlers\SDL2ConcreteHandlers.hpp"


std::shared_ptr<InputControllerInterface> SDL2InputControllerBuilder::get_input_controller_interface(){

    std::shared_ptr<SDL2InputController> input_controller = std::make_shared<SDL2InputController>();

    input_controller->set_keyboard_manager(
        std::make_shared<KeyboardManager>()
    );

    input_controller->set_mouse_manager(
        std::make_shared<MouseManager>()
    );

    input_controller->set_controller_manager(
        std::make_shared<ControllerManager>()
    );

    /**
     * TODO: add support for controllers
     */

    std::shared_ptr<SDL2EventHandlerInterface> mouse_handler = std::make_shared<SDL2MouseEventHandler>();
    std::shared_ptr<SDL2EventHandlerInterface> keyboard_handler = std::make_shared<SDL2KeyboardEventHandler>();
    std::shared_ptr<SDL2EventHandlerInterface> tail = std::make_shared<SDL2EventHandlerTail>();

    mouse_handler->setNext(keyboard_handler);
    keyboard_handler->setNext(tail);
    input_controller->set_event_handler(mouse_handler);

    input_controller->run();
}