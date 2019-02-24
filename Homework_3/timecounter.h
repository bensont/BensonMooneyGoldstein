#pragma once

class TimeCounter{
private:
    TimeCounter();
    TimeCounter(int mxday);
    bool IsDay();
    void AdvanceDay();
    bool IsDone();
public:
    int maxDay_;
    int currentDay_;
    bool isDay_;
};
