#include "headers/Time.hpp"

#include <iostream>
#include <iomanip>
#include <ctime>

Time::Time(const int hour, const int minute, const int second)
{
    setTime(hour, minute, second);
} 

Time::Time()
{
    int current = time(0);
    int second = current % 60;
    int minute = current % 3600 / 60;
    int hour = current % 86400 / 3600 + 4;

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
    hour_ = (hour >= 0 && hour < 24) ? hour : 0;
} 

void
Time::setMinute(const int minute)
{
    minute_ = (minute >= 0 && minute < 60) ? minute : 0;
}

void
Time::setSecond(const int second)
{
    second_ = (second >= 0 && second < 60) ? second : 0;
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

