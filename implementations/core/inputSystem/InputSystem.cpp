#include "../headers/core/inputSystem/InputSystem.hpp"

std::shared_ptr<InputSystem> InputSystem::input_system = nullptr;

void InputSystem::setBuilder(std::shared_ptr<AbstractInputControllerBuilder> builder){
    this->builder = builder;
}

void InputSystem::startInputSystem(){
    if(this->input_controller){
        std::cerr << "Trying to start the input syste, but it's already working" << std::endl;
    }
    this->input_controller = this->builder->get_input_controller_interface();
}

std::shared_ptr<InputSystem> InputSystem::get_istance(){
    if(!InputSystem::input_system){
        InputSystem::input_system = std::make_shared<InputSystem>();
    }
    return InputSystem::input_system;
}

std::shared_ptr<InputControllerInterface> InputSystem::getInputController(){
    return this->input_controller;
}