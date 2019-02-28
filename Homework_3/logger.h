#pragma once
#include <string>
#include <iostream>

enum MessageLevel{exception, error, warning, message, info1, info2, debug};

//This should be a singleton class

class Logger{
public:
    static void print(std::string text);
    static void print(std::string text, MessageLevel level);
    void setMessageLevel(MessageLevel minlvl);
private:
    static int minLevel_;
    //might need somethint if we want to write to files
};
