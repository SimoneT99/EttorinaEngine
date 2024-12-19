#include "../headers/core/inputSystem/Enums/Enums.hpp"
#include "../headers/core/inputSystem/AbstractInputCommand.hpp"
#include "ITickable.hpp"
#include <memory>
#include <map>

class AbstractMouseManager : public ITickable{

    public:
        
        virtual void get_mouse_position(float& x, float& y) const = 0;
        virtual void get_mouse_delta(float& dx, float& dy) const = 0;
        virtual void get_mouse_wheel_delta(float& dx, float& dy) const = 0;

        virtual bool mouse_button_pressed_down(Enums::MouseButton button) const = 0;
        virtual bool mouse_button_pressed(Enums::MouseButton button) const = 0;
        virtual bool mouse_button_released(Enums::MouseButton button) const = 0;

        virtual void bind_mouse_event(Enums::MouseButton button, Enums::ButtonEvent event, std::unique_ptr<AbstractInputCommand> action) = 0;
        virtual void unbind_mouse_event(Enums::MouseButton button, Enums::ButtonEvent event) = 0;

        /**
         * State changers
         */
        virtual void set_mouse_position(float x, float y) = 0;
        virtual void update_mouse_wheel_delta(float dx, float dy) = 0;
        virtual void press_button(Enums::MouseButton button) = 0;
        virtual void release_button(Enums::MouseButton button) = 0;
};