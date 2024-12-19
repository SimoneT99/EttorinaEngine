#include "../headers\core\inputSystem\SDL2InputSystem\periferalManagement\AbstractControllerManager.hpp"
#include <map>

class ControllerManager : public AbstractControllerManager{

    private:
        std::map<Enums::ControllerButton, Enums::ButtonEvent> controller_buttons;
        std::map<std::pair<Enums::ControllerButton, Enums::ButtonEvent>, AbstractInputCommand> controller_buttons_events;
        std::map<Enums::ControllerAxis, float> controller_axis;

        inline Enums::ButtonState get_controller_button_state(Enums::ControllerButton button) const;

    public:
        bool controller_button_pressed_down(Enums::ControllerButton button) const override;
        bool controller_button_pressed(Enums::ControllerButton button) const override;
        bool controller_button_released(Enums::ControllerButton button) const override;
    
        void get_controller_axis(Enums::ControllerAxis axis, float& value) const override;

        void bind_controller_event(Enums::ControllerButton button, Enums::ButtonEvent event, std::unique_ptr<AbstractInputCommand> action) override;
        void unbind_controller_event(Enums::ControllerButton button, Enums::ButtonEvent event) override;
};