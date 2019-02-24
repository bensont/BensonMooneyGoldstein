#pragma once

class TimeCounter{
public:
    TimeCounter();
    TimeCounter(int mxday);
    bool IsDay();
    void AdvanceDay();
    bool IsDone();
    int get_day();
    
private:
    int maxDay_;
    int currentDay_;
    bool isDay_;
};
