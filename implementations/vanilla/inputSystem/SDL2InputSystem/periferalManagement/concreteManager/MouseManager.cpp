#include "..\headers\vanilla\inputSystem\SDL2InputSystem\periferalManagement\concreteManager\MouseManager.hpp"

inline void MouseManager::save_memento()
{
    this->mouseManagerMemento.mouse_x = this->mouse_x;
    this->mouseManagerMemento.mouse_y = this->mouse_y;

    this->mouseManagerMemento.mouse_delta_x = this->mouse_delta_x;
    this->mouseManagerMemento.mouse_delta_y = this->mouse_delta_y;

    this->mouseManagerMemento.wheel_delta_x = this->wheel_delta_x;
    this->mouseManagerMemento.wheel_delta_y = this->wheel_delta_y;
}

/**
 * Polling methods
 */

void MouseManager::get_mouse_delta(float &dx, float &dy) const
{
    dx = this->mouseManagerMemento.mouse_delta_x;
    dy = this->mouseManagerMemento.mouse_delta_y;
}

void MouseManager::get_mouse_wheel_delta(float &dx, float &dy) const{
    dx = this->mouseManagerMemento.wheel_delta_x;
    dy = this->mouseManagerMemento.wheel_delta_y;
}

/**
 * ISSUE: is a good idea to send the saved position? or it could be a better idea to
 * send the current position? maybe should be a parameter or a different method?
 */
void MouseManager::get_mouse_position(float &x, float &y) const
{
    x = this->mouseManagerMemento.mouse_delta_x;
    y = this->mouseManagerMemento.mouse_delta_x;
}

bool MouseManager::mouse_button_pressed_down(Enums::MouseButton button) const
{
    return this->mouse_button_manager->button_pressed_down(button);
}

bool MouseManager::mouse_button_pressed(Enums::MouseButton button) const
{
    return this->mouse_button_manager->button_pressed(button);
}

bool MouseManager::mouse_button_released(Enums::MouseButton button) const
{
    return this->mouse_button_manager->button_released(button);
}

/**
 * Responsive methods
 */

void MouseManager::bind_mouse_event(Enums::MouseButton button, Enums::ButtonEvent event, std::unique_ptr<AbstractInputCommand> action)
{
    this->mouse_button_manager->bind_button_event(button, event, std::move(action));
}

void MouseManager::unbind_mouse_event(Enums::MouseButton button, Enums::ButtonEvent event)
{
    this->mouse_button_manager->unbind_mouse_event(button, event);
}

/**
 * Interaction methods
 */

void MouseManager::set_mouse_position(float x, float y)
{
    /**
     * ISSUE: race condition?
     */
    this->mouse_x = x;
    this->mouse_y = y;

    /**
     * What do we do here?
     */
    this->mouse_delta_x += x;
    this->mouse_y += y;
}

void MouseManager::update_mouse_wheel_delta(float dx, float dy)
{
    /**
     * ISSUE: race condition?
     * ISSUE: is this right?
     */
    this->wheel_delta_x += dx;
    this->wheel_delta_y += dy;
}

/**
 * ISSUE: HOW DO WE PASS FROM RELEASED TO UNPRESSED?
 */

/**
 * ISSUE: Here the priority of the updates in the memento are hardcoded
 */

void MouseManager::press_button(Enums::MouseButton button)
{
    this->mouse_button_manager->press_button(button);
}

void MouseManager::release_button(Enums::MouseButton button)
{
    this->mouse_button_manager->press_button(button);
}

void MouseManager::tick(){
    this->save_memento();
    this->mouse_button_manager->update();
}
