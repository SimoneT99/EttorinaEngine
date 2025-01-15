#include "..\headers\vanilla\inputSystem\SDL2InputSystem\SDL2InputControllerBuilder.hpp"

std::shared_ptr<InputControllerInterface> SDL2InputControllerBuilder::get_input_controller_interface(){

    SDL2_PRINT_FOR_DEBUG("SDL2 input controller builder called...", false)
    SDL2_PRINT_FOR_DEBUG("Building the keyboard manager...", false)
    std::shared_ptr<SDL2InputController> input_controller = std::make_shared<SDL2InputController>(
        10
    );

    //Keyboard

    std::unique_ptr<IButtonManager<Enums::KeyButton>> KeyButtonManager =  std::make_unique<ThreadSafeButtonManager<Enums::KeyButton>>();
    std::shared_ptr<AbstractKeyboardManager> keyboardManager = std::make_shared<KeyboardManager>(std::move(KeyButtonManager));

    SDL2_PRINT_FOR_DEBUG("Setting the keyboard manager...", false)
    input_controller->set_keyboard_manager(
        keyboardManager
    );

    SDL2_PRINT_FOR_DEBUG("Building the mouse manager...", false) 
    //Mouse
    std::unique_ptr<IButtonManager<Enums::MouseButton>> mouseButtonManager =  std::make_unique<ThreadSafeButtonManager<Enums::MouseButton>>();
    std::shared_ptr<AbstractMouseManager> mouseManager = std::make_shared<MouseManager>(std::move(mouseButtonManager));

    SDL2_PRINT_FOR_DEBUG("Setting the mouse manager...", false)
    input_controller->set_mouse_manager(
        mouseManager
    );

    SDL2_PRINT_FOR_DEBUG("Building the controller manager (TBA)...", false) 
    //Controller
    input_controller->set_controller_manager(
        std::make_shared<ControllerManager>()
    );

    /**
     * TODO: add support for controllers
     */

    SDL2_PRINT_FOR_DEBUG("Building the handler chain...", false)
    std::shared_ptr<SDL2EventHandlerInterface> mouse_handler = std::make_shared<SDL2MouseEventHandler>(
        mouseManager
    );

    std::shared_ptr<SDL2EventHandlerInterface> keyboard_handler = std::make_shared<SDL2KeyboardEventHandler>(
        keyboardManager
    );

    std::shared_ptr<SDL2EventHandlerInterface> tail = std::make_shared<SDL2EventHandlerTail>();

    mouse_handler->setNext(keyboard_handler);
    keyboard_handler->setNext(tail);

    SDL2_PRINT_FOR_DEBUG("Setting the handler chain...", false)
    input_controller->set_event_handler(mouse_handler);

    SDL2_PRINT_FOR_DEBUG("Starting the event loop...", false)
    input_controller->run();
    
    /**
     * ISSUE: should be started here?
     */
    return input_controller;
}