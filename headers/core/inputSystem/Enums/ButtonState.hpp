#include <string>
#include <vector>

namespace Enums{

    enum ButtonState{
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

