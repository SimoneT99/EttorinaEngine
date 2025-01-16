#include "MessageToTerminalCommand.hpp"

void MessageToTerminalCommand::execute_command(){

    if(this->verbose){
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        std::string time_str = std::ctime(&now_c);
        time_str.pop_back();
        std::cout<< "[" << time_str <<"] ";
    }
    std::cout << this->message;
    if(this->go_next_line){
           std::cout << std::endl; 
    }
};