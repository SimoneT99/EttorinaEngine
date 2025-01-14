#include "../headers/core/inputSystem/Enums/ButtonState.hpp"
#pragma once

/**
 * I do not like this class...
 */

class ITickable{

    public:
        virtual void tick() = 0;
};