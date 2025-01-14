#include "../AbstractMouseManager.hpp"
#include <map>
#include <unordered_map>
#include <iostream>
#include "../IButtonManager.hpp"

class MouseManager : public AbstractMouseManager
{

private:

    std::unique_ptr<IButtonManager<Enums::MouseButton>> mouse_button_manager;

    inline void save_memento();

    float mouse_x;
    float mouse_y;

    float mouse_delta_x;
    float mouse_delta_y;

    float wheel_delta_x;
    float wheel_delta_y;

    class MouseManagerMemento{
        public:
            float mouse_x;
            float mouse_y;

            float mouse_delta_x;
            float mouse_delta_y;

            float wheel_delta_x;
            float wheel_delta_y;
    };

    MouseManagerMemento mouseManagerMemento;

public:

    MouseManager(std::unique_ptr<IButtonManager<Enums::MouseButton>> manager) :
    mouse_button_manager(std::move(manager)) {}

    /**
     * Polling methods
     */

    void get_mouse_position(float &x, float &y) const override;
    void get_mouse_delta(float &dx, float &dy) const override;
    void get_mouse_wheel_delta(float &dx, float &dy) const override;

    bool mouse_button_pressed_down(Enums::MouseButton button) const override;
    bool mouse_button_pressed(Enums::MouseButton button) const override;
    bool mouse_button_released(Enums::MouseButton button) const override;

    /**
     * Repsonsive methods
     */

    void bind_mouse_event(Enums::MouseButton button, Enums::ButtonEvent event, std::unique_ptr<AbstractInputCommand> action) override;
    void unbind_mouse_event(Enums::MouseButton button, Enums::ButtonEvent event) override;

    /**
     * Interaction methods
     */

    void set_mouse_position(float x, float y) override;
    void update_mouse_wheel_delta(float dx, float dy) override;
    void press_button(Enums::MouseButton button) override;
    void release_button(Enums::MouseButton button) override;

    void tick() override;

};