#include "headers/Time.hpp"

#include <iostream>
#include <iomanip>


Time::Time(const int hour, const int minute, const int second)
{
    setTime(hour, minute, second);
} 

void
Time::setTime(const int hour, const int minute, const int second)
{
    setHour(hour);
    setMinute(minute);
    setSecond(second);
}

void
Time::setHour(const int hour)
{
    if (hour < 0 || hour > 24) {
        std::cout << "Error 1: invalid hour, set to 0." << std::endl;
        hour_ = 0;
        return;
    }
    hour_ = hour;
} 

void
Time::setMinute(const int minute)
{
    if (minute < 0 || minute > 59) {
        std::cout << "Error 2: invalid minute, set to 0" << std::endl;
        minute_ = 0;
        return;
    }
    minute_ = minute;
}

void
Time::setSecond(const int second)
{
    if (second < 0 || second > 59) {
        std::cout << "Error 3: invalid second, set to 0" << std::endl;
        second_ = 0;
        return;
    }
    second_ = second;
} 

int
Time::getHour()
{
    return hour_;
}

int
Time::getMinute()
{
    return minute_;
}

int
Time::getSecond()
{
    return second_;
}

void
Time::printUniversal()
{
    std::cout << std::setfill('0') << std::setw(2) << getHour() << ":"
    << std::setw(2) << getMinute() << ":" << std::setw(2) << getSecond() << std::setfill(' ');
}

void
Time::printStandard()
{
    std::cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
    << ":" << std::setfill('0') << std::setw(2) << getMinute()
    << ":" << std::setw(2) << getSecond() << (getHour() < 12 ? " AM" : " PM") << std::setfill(' ');
}

