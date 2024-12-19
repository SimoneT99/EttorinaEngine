#include "../IButtonManager.hpp"
#include "../headers/core/inputSystem/Enums/ButtonState.hpp"
#include <map>
#include <unordered_map>
#include <iostream>


/**
 * @brief: Thread safe implementation of a Button manager to be used by periferal
 */
/**
 * TODO: implement thread safety
 */
template<typename ButtonType>
class ThreadSafeButtonManager : IButtonManager<typename ButtonType>{
    
    private:
    std::map<ButtonType, Enums::ButtonState> button_state;
    std::unordered_multimap<ButtonType, Enums::ButtonEvent> button_event_bucket;
    std::map<std::pair<ButtonType, Enums::ButtonEvent>, std::unique_ptr<AbstractInputCommand>> buttons_events_bindings;

    inline bool check_event_presence(ButtonType button, Enums::ButtonEvent event) const;
    inline void fire_event(Enums::MouseButton button, Enums::ButtonEvent event) const;

    public:
        bool button_pressed_down(ButtonType button) const override;
        bool button_pressed(ButtonType button) const override;
        bool button_released(ButtonType button) const override;

        void bind_button_event(ButtonType button, Enums::ButtonEvent event, std::unique_ptr<AbstractInputCommand>)override;
        void unbind_mouse_event(ButtonType button, Enums::ButtonEvent event) override;
        void press_button(ButtonType button) override;
        void release_button(ButtonType button) override;
};