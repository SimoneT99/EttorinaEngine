#include "../headers/core/inputSystem/Enums/ButtonState.hpp"

using namespace Enums;

std::string Enums::ButtonStateHelper::buttonStateToString(Enums::ButtonState buttonState){
    switch(buttonState){
        case ButtonState::PRESSED: return "PRESSED";
        case ButtonState::UNPRESSED: return "UNPRESSED";
    }
}


std::vector<Enums::ButtonState> Enums::ButtonStateHelper::getButtonState(){

    std::vector<ButtonState> buttons = { 
        ButtonState::PRESSED,
        ButtonState::UNPRESSED
    };
    return buttons;
};