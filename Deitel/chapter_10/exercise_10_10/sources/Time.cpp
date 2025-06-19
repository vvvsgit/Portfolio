#include "headers/Time.hpp"

#include <iostream>
#include <iomanip>

const int MINUTE_IN_SECONDS = 60;
const int HOUR_IN_MINUTES = 60;
const int HOUR_IN_SECONDS = HOUR_IN_MINUTES * MINUTE_IN_SECONDS;

Time::Time(const int hour, const int minute, const int second)
    : seconds_(0)
{
    setTime(hour, minute, second);
}

Time&
Time::setTime(const int hour, const int minute, const int second)
{
    setHour(hour);
    setMinute(minute);
    setSecond(second);
    return *this;
}

Time&
Time::setHour(int hour)
{
    hour = (hour >= 0 && hour < 24) ? hour : 0;
    seconds_ = (seconds_ % HOUR_IN_SECONDS) + (hour * HOUR_IN_SECONDS);
    return *this;
}

Time&
Time::setMinute(int minute)
{
    minute = (minute >= 0 && minute < 60) ? minute : 0;
    seconds_ = (seconds_ - seconds_ % HOUR_IN_SECONDS) + (seconds_ % MINUTE_IN_SECONDS) + minute * HOUR_IN_MINUTES;
    return *this;
}

Time&
Time::setSecond(int second)
{
    second = (second >= 0 && second < 60) ? second : 0;
    seconds_ = (seconds_ - seconds_ % MINUTE_IN_SECONDS) + second;
    return *this;
}

int
Time::getHour() const
{
    return seconds_ / HOUR_IN_SECONDS;
}

int
Time::getMinute() const
{
    return seconds_ % HOUR_IN_SECONDS / HOUR_IN_MINUTES;
}

int
Time::getSecond() const
{
    return seconds_ % MINUTE_IN_SECONDS;
}

void
Time::printUniversal() const
{
    const char fill = std::cout.fill('0');
    std::cout << std::setw(2) << getHour() << ":"
    << std::setw(2) << getMinute() << ":" << std::setw(2) << getSecond() << std::setfill(fill);
}

void
Time::printStandard() const
{
    const char fill = std::cout.fill('0');
    std::cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
    << ":" << std::setw(2) << getMinute()
    << ":" << std::setw(2) << getSecond() << (getHour() < 12 ? " AM" : " PM") << std::setfill(fill);
}

