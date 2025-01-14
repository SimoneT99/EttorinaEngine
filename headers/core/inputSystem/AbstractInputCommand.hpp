/**
 * Abstract definition of an input command
 */

#pragma once

class AbstractInputCommand{
    public:
        virtual void execute_command() = 0;
};