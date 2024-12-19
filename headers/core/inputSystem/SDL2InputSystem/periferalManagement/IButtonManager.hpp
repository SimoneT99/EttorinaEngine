#include "../headers/core/inputSystem/Enums/ButtonEvent.hpp"
#include "../headers\core\inputSystem\AbstractInputCommand.hpp"
#include <memory>

/**
 * Abstract definition for a button manager class
 * The idea is to use composition and generic to avoid repeated code
 *  int regard to the task of managing the buttons states and events
 */

template<typename ButtonType>
class IButtonManager{

    public:
        virtual bool button_pressed_down(ButtonType button) const = 0;
        virtual bool button_pressed(ButtonType button) const = 0;
        virtual bool button_released(ButtonType button) const = 0;

        virtual void bind_button_event(ButtonType button, Enums::ButtonEvent event, std::unique_ptr<AbstractInputCommand>) = 0;
        virtual void unbind_mouse_event(ButtonType button, Enums::ButtonEvent event) = 0;

        virtual void press_button(ButtonType button) const = 0;
        virtual void release_button(ButtonType button) const = 0;

        virtual void update();
};