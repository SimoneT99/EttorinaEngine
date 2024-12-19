#include "../headers/core/inputSystem/Enums/Enums.hpp"
#include "../headers/core/inputSystem/AbstractInputCommand.hpp"
#include "ITickable.hpp"
#include <memory>
#include <map>

class AbstractKeyboardManager : public ITickable{

    public:
        virtual bool key_pressed_down(Enums::KeyButton button) const = 0;
        virtual bool key_pressed(Enums::KeyButton button) const = 0;
        virtual bool key_released(Enums::KeyButton button) const = 0;

        virtual void bind_key_event(Enums::KeyButton button, Enums::ButtonEvent event, std::unique_ptr<AbstractInputCommand> action) = 0;
        virtual void unbind_key_event(Enums::KeyButton button, Enums::ButtonEvent event) = 0;

        /**
         * State changers
         */

        virtual void press_button(Enums::KeyButton button);
        virtual void release_button(Enums::KeyButton button);
};