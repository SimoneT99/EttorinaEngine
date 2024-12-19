#include "..\headers\core\inputSystem\SDL2InputSystem\periferalManagement\concreteManager\KeyboardManager.hpp"

bool KeyboardManager::key_pressed_down(Enums::KeyButton button) const{
    return this->keyboard_button_manager->button_pressed_down(button);
}

bool KeyboardManager::key_pressed(Enums::KeyButton button) const{
    return this->keyboard_button_manager->button_pressed(button);
}

bool KeyboardManager::key_released(Enums::KeyButton button) const{
    return this->keyboard_button_manager->button_pressed(button); 
}

void KeyboardManager::bind_key_event(Enums::KeyButton button, Enums::ButtonEvent event, std::unique_ptr<AbstractInputCommand> action){
    this->keyboard_button_manager->bind_button_event(button, event, std::move(action));
}

void KeyboardManager::unbind_key_event(Enums::KeyButton button, Enums::ButtonEvent event){
    this->keyboard_button_manager->unbind_mouse_event(button, event);
}

void KeyboardManager::tick(){
    this->keyboard_button_manager->update();
}
