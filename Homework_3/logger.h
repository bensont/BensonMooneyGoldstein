#pragma once
#include <string>
#include <iostream>

enum MessageLevel{exception, error, warning, message, info1, info2, debug};

//Info2 is for the full stack
//Info1 is for actions, like renting and returning

//This should be a singleton class

class Logger{
public:
    static void print(std::string text);
    static void print(std::string text, MessageLevel level);
    void setMessageLevel(MessageLevel minlvl);
    static bool isDebug();
private:
    static int minLevel_;
    //might need somethint if we want to write to files
};
