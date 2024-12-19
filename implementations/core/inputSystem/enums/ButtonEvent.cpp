#include "../headers/core/inputSystem/Enums/ButtonEvent.hpp"

using namespace Enums;

std::string Enums::ButtonEventHelper::buttonEventToString(Enums::ButtonEvent buttonState){
    switch(buttonState){
        case ButtonEvent::PRESSED_DOWN: return "PRESSED_DOWN";
        case ButtonEvent::PRESSED: return "PRESSED";
        case ButtonEvent::RELEASED: return "RELEASED";
    }
}


std::vector<Enums::ButtonEvent> Enums::ButtonEventHelper::getButtonEvent(){
    std::vector<Enums::ButtonEvent> buttons = { 
        ButtonEvent::PRESSED_DOWN,
        ButtonEvent::PRESSED,
        ButtonEvent::RELEASED
    };
    return buttons;
};