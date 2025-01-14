#include "../IButtonManager.hpp"
#include "../headers/core/inputSystem/Enums/Enums.hpp"
#include <map>
#include <unordered_map>
#include <iostream>

/**
 * @brief: Thread safe implementation of a Button manager to be used by periferal
 */
/**
 * TODO: implement thread safety
 */
template <typename ButtonType>
class ThreadSafeButtonManager : public IButtonManager<ButtonType>{

private:
    std::map<ButtonType, Enums::ButtonState> button_state;
    std::unordered_multimap<ButtonType, Enums::ButtonEvent> button_event_bucket;
    std::map<std::pair<ButtonType, Enums::ButtonEvent>, std::unique_ptr<AbstractInputCommand>> buttons_events_bindings;

    inline bool check_event_presence(ButtonType button, Enums::ButtonEvent event) const
    {
        auto range = this->button_event_bucket.equal_range(button);
        for (auto it = range.first; it != range.second; ++it)
        {
            if (it->second == event)
            {
                return true;
            }
        }

        return false;
    }

    inline void fire_event(ButtonType button, Enums::ButtonEvent event) const
    {
        auto it = this->buttons_events_bindings.find(std::make_pair(button, event)); // Cerca la coppia chiave
        if (it != this->buttons_events_bindings.end())
        {
            it->second->execute_command();
        }
    }

    inline Enums::ButtonState get_button_state(ButtonType button){
        auto it = this->button_state.find(button);
    
        if (it != this->button_state.end()) {
            return it->second;
        } else {
        return Enums::ButtonState::UNPRESSED;
        }
    }

public:

    ThreadSafeButtonManager(){
        this->button_state = std::map<ButtonType, Enums::ButtonState>();
        this->button_event_bucket = std::unordered_multimap<ButtonType, Enums::ButtonEvent>();
        this->buttons_events_bindings = std::map<std::pair<ButtonType, Enums::ButtonEvent>, std::unique_ptr<AbstractInputCommand>>();
    }

    bool button_pressed_down(ButtonType button) const override
    {
        return this->check_event_presence(button, Enums::ButtonEvent::PRESSED_DOWN);
    };

    bool button_pressed(ButtonType button) const override
    {
        return this->check_event_presence(button, Enums::ButtonEvent::PRESSED);
    };

    bool button_released(ButtonType button) const override
    {
        return this->check_event_presence(button, Enums::ButtonEvent::RELEASED);
    };

    void bind_button_event(ButtonType button, Enums::ButtonEvent event, std::unique_ptr<AbstractInputCommand> action) override
    {
        std::cout << "Into the button manager ass" << std::endl;
        this->buttons_events_bindings.insert({std::make_pair(button, event), std::move(action)});
    };

    void unbind_mouse_event(ButtonType button, Enums::ButtonEvent event) override
    {
        this->buttons_events_bindings.erase({button, event});
    };

    void press_button(ButtonType button) override
    {
        Enums::ButtonState state = this->get_button_state(button);
        switch (state)
        {
        case Enums::ButtonState::PRESSED:
            this->button_event_bucket.emplace(button, Enums::ButtonEvent::PRESSED);
            this->fire_event(button, Enums::ButtonEvent::PRESSED);
            break;
        case Enums::ButtonState::UNPRESSED:
            this->button_event_bucket.emplace(button, Enums::ButtonEvent::PRESSED_DOWN);
            this->button_state.emplace(button, Enums::ButtonState::PRESSED);
            this->fire_event(button, Enums::ButtonEvent::PRESSED_DOWN);
            break;
        default:
            std::cerr << "Invalid state, something went wrong at " << __FILE__ << " " << __LINE__ << std::endl;
            break;
        }
    };

    void release_button(ButtonType button) override
    {
        Enums::ButtonState state = this->get_button_state(button);
        switch (state)
        {
        case Enums::ButtonState::PRESSED:
            this->button_event_bucket.emplace(button, Enums::ButtonEvent::RELEASED);
            this->button_state.emplace(button, Enums::ButtonState::UNPRESSED);
            this->fire_event(button, Enums::ButtonEvent::RELEASED);
            break;
        case Enums::ButtonState::UNPRESSED:
            // do nothing here
            break;
        default:
            std::cerr << "Invalid state, something went wrong at " << __FILE__ << " " << __LINE__ << std::endl;
            break;
        }
    };

    void update() override
    {
        /**
         * TODO: update logic
         */
    }
};