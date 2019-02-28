#include "logger.h"

int Logger::minLevel_ = 0;

void Logger::print(std::string text){
    std::cout << text << std::endl;
}

void Logger::print(std::string text, MessageLevel level){
    if(minLevel_ == 0){
        print(text);
    }
    if(level <= minLevel_){
        print(text);
    }
}

void Logger::setMessageLevel(MessageLevel minlvl){
    minLevel_ = minlvl;
}
