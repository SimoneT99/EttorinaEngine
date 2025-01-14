#include "..\headers\vanilla\inputSystem\SDL2InputSystem\periferalManagement\concreteManager\ControllerManager.hpp"

inline Enums::ButtonState ControllerManager::get_controller_button_state(Enums::ControllerButton button) const{
    return Enums::ButtonState::UNPRESSED;
}

bool ControllerManager::controller_button_pressed_down(Enums::ControllerButton button) const{
    return true;
}

bool ControllerManager::controller_button_pressed(Enums::ControllerButton button) const{
    return true;
}

bool ControllerManager::controller_button_released(Enums::ControllerButton button) const{
    return true;
}
   
void ControllerManager::get_controller_axis(Enums::ControllerAxis axis, float& value) const{
    auto controller_axis = this->controller_axis.find(axis);
    value = controller_axis != this->controller_axis.end() ? controller_axis->second : 0;
}

void ControllerManager::bind_controller_event(Enums::ControllerButton button, Enums::ButtonEvent event, std::unique_ptr<AbstractInputCommand> action){
}

void ControllerManager::unbind_controller_event(Enums::ControllerButton button, Enums::ButtonEvent event){
}

void ControllerManager::tick(){
    
}


void ControllerManager::set_axis(Enums::ControllerAxis axis, float value){
    
}

void ControllerManager::press_button(Enums::ControllerButton button){

}

void ControllerManager::release_button(Enums::ControllerButton button){
    
}