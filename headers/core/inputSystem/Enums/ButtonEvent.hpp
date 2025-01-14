#include <string>
#include <vector>

#pragma once

namespace Enums{

    enum class ButtonEvent{
        PRESSED_DOWN,
        PRESSED,
        RELEASED
    };

    /**
     * Better solutions are welcome...
     */

    class ButtonEventHelper{

        public:
            static std::string buttonEventToString(ButtonEvent buttonEvent);
            static std::vector<ButtonEvent> getButtonEvent();
        
    };

}
