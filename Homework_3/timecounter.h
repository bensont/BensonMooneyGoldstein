#pragma once

class TimeCounter{
private:
    TimeCounter();
    TimeCounter(int mxday);
    bool IsDay();
    void AdvanceDay();
    bool IsDone();
public:
    int _maxDay
    int _currentDay;
    bool _isDay;
};
