#include "../AbstractKeyboardManager.hpp"
#include "../IButtonManager.hpp"
#include <map>

class KeyboardManager : public AbstractKeyboardManager{

    private:
        std::unique_ptr<IButtonManager<Enums::KeyButton>> keyboard_button_manager;

    public:
    
        KeyboardManager(std::unique_ptr<IButtonManager<Enums::KeyButton>> manager) :
            keyboard_button_manager(std::move(manager)) {}

        bool key_pressed_down(Enums::KeyButton button) const override;
        bool key_pressed(Enums::KeyButton button) const override;
        bool key_released(Enums::KeyButton button) const override;

        void bind_key_event(Enums::KeyButton button, Enums::ButtonEvent event, std::unique_ptr<AbstractInputCommand> action) override;
        void unbind_key_event(Enums::KeyButton button, Enums::ButtonEvent event) override;

        void press_button(Enums::KeyButton button) override;
        void release_button(Enums::KeyButton button) override;

        void tick() override;
};