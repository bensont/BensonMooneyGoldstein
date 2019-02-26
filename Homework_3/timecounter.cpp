#include "timecounter.h"

TimeCounter::TimeCounter(){
    maxDay_ = 0;
    currentDay_ = 0;
    isDay_ = false;
}

TimeCounter::TimeCounter(int mxday){
    maxDay_ = mxday;
    currentDay_ = 1;
    isDay_ = true;
}

bool TimeCounter::IsDay(){
    return isDay_;
}

void TimeCounter::AdvanceDay(){
    if(isDay_){
        isDay_ = false;
    }else{
        currentDay_++;
        isDay_ = true;
    }
}

bool TimeCounter::IsDone(){
    if(currentDay_ >= maxDay_){
        return true;
    }else{
        return false;
    }
}

int TimeCounter::get_day() {
  return currentDay_;
}
