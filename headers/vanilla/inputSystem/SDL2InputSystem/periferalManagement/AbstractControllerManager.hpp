#include "../headers/core/inputSystem/Enums/Enums.hpp"
#include "../headers/core/inputSystem/AbstractInputCommand.hpp"
#include "ITickable.hpp"
#include <memory>
#include <map>

#pragma once

class AbstractControllerManager : public ITickable{

    public:
        virtual bool controller_button_pressed_down(Enums::ControllerButton button) const = 0;
        virtual bool controller_button_pressed(Enums::ControllerButton button) const = 0;
        virtual bool controller_button_released(Enums::ControllerButton button) const = 0;
    
        virtual void get_controller_axis(Enums::ControllerAxis axis, float& value) const = 0;

        virtual void bind_controller_event(Enums::ControllerButton button, Enums::ButtonEvent event, std::unique_ptr<AbstractInputCommand> action) = 0;
        virtual void unbind_controller_event(Enums::ControllerButton button, Enums::ButtonEvent event) = 0;

        /**
         * Note: value will be clamped in a [-1,1] interval
         */
        virtual void set_axis(Enums::ControllerAxis axis, float value) = 0;

        /**
         * State changers
         */

        virtual void press_button(Enums::ControllerButton button) = 0;
        virtual void release_button(Enums::ControllerButton button) = 0;

};