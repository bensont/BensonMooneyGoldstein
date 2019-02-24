#include "TimeCounter.h"

TimeCounter::TimeCounter(){
    _maxDay = 0;
    _currendDay = 0;
    _isDay = false;
}

TimeCounter::TimeCounter(int mxday){
    _maxDay = mxday
    _currendDay = 1;
    _isDay = true;
}

TimeCounter::_isDay(){
    return _isDay;
}

void TimeCounter::AdvanceDay(){
    if(_isDay){
        _isDay = false;
    }else{
        _currendDay++;
    }
}

bool TimeCounter::IsDone(){
    if(_currendDay >= _maxDay){
        return true;
    }else{
        return false;
    }
}
