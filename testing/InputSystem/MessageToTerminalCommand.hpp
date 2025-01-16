#include "../headers/core/inputSystem/AbstractInputCommand.hpp"
#include <string>
#include <iostream>
#include <chrono>

/**
 * Simple input command that prints informations when the action is called
 */

class MessageToTerminalCommand : public AbstractInputCommand{
    
    std::string message;
    bool verbose = true;
    bool go_next_line = true;

    public:
        MessageToTerminalCommand(std::string message, bool verbose = true, bool go_next_line = true) : 
            message(message), 
            verbose(verbose),
            go_next_line(go_next_line) {}
        void execute_command() override;
};