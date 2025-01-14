#include <string>
#include <vector>

#pragma once

namespace Enums{

    enum class ButtonState{
        PRESSED,
        UNPRESSED
    };

    /**
     * Better solutions are welcome...
     */

    class ButtonStateHelper{

        public:
            static std::string buttonStateToString(ButtonState buttonState);
            static std::vector<ButtonState> getButtonState();
    };

}

