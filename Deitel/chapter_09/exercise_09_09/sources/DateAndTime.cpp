#include "headers/DateAndTime.hpp"

#include <iostream>
#include <iomanip>
#include <ctime>


DateAndTime::DateAndTime(const int hour, const int minute, const int second,
                         const int day, const int month, const int year)
{
    setTime(hour, minute, second);
    setDate(year, month, day);
}

void
DateAndTime::setTime(const int hour, const int minute, const int second)
{
    setHour(hour);
    setMinute(minute);
    setSecond(second);
}

void
DateAndTime::setDate(const int year, const int month, const int day)
{
    setYear(year);
    setMonth(month);
    setDay(day);
}

void
DateAndTime::setHour(const int hour)
{
    hour_ = (hour >= 0 && hour < 24) ? hour : 0;
} 

void
DateAndTime::setMinute(const int minute)
{
    minute_ = (minute >= 0 && minute < 60) ? minute : 0;
}

void
DateAndTime::setSecond(const int second)
{
    second_ = (second >= 0 && second < 60) ? second : 0;
} 

void
DateAndTime::setYear(const int year)
{
    if (year < 1) {
        year_ = 1;
        return;
    }
    year_ = year;
}

void
DateAndTime::setMonth(const int month)
{
    if (month < 1 || month > 12) {
        month_ = 1;
        return;
    }
    month_ = month;
}

void
DateAndTime::setDay(const int day)
{
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (2 == getMonth() && 29 == day && 0 == getYear() % 4 && 0 == getYear() % 100 && 0 == getYear() % 400) {
        day_ = day;
        return;
    }
    if (day < 1 || day > days[getMonth() - 1]) {
        day_ = 1;
        return;
    }
    day_ = day;
}

int
DateAndTime::getHour()
{
    return hour_;
}

int
DateAndTime::getMinute()
{
    return minute_;
}

int
DateAndTime::getSecond()
{
    return second_;
}

int
DateAndTime::getYear()
{
    return year_;
}

int
DateAndTime::getMonth()
{
    return month_;
}

int
DateAndTime::getDay()
{
    return day_;
}


void
DateAndTime::nextDay()
{
    setDay(getDay() + 1);
    if (1 == getDay()) {
        setMonth(getMonth() + 1);
        if (1 == getMonth()) {
            setYear(getYear() + 1);
        }
    }
}

void
DateAndTime::tick()
{
    setSecond(getSecond() + 1);
    if (0 == getSecond()) {
        setMinute(getMinute() + 1);
        if (0 == getMinute()) {
            setHour(getHour() + 1);
            if (0 == getHour()) {
                nextDay();
            }
        }
    }
}

void
DateAndTime::printUniversal()
{
    std::cout << getMonth() << '/' << getDay() << '/' << getYear() << std::endl;

    std::cout << std::setfill('0') << std::setw(2) << getHour() << ":"
    << std::setw(2) << getMinute() << ":" << std::setw(2) << getSecond() << std::setfill(' ');
}

void
DateAndTime::printStandard()
{
    std::cout << getMonth() << '/' << getDay() << '/' << getYear() << std::endl;

    std::cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
    << ":" << std::setfill('0') << std::setw(2) << getMinute()
    << ":" << std::setw(2) << getSecond() << (hour_ < 12 ? " AM" : " PM") << std::setfill(' ');
}

