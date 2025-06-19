#include "headers/Date.hpp"

#include <iostream>


Date::Date(int day, int month, int year)
{
    setDate(year, month, day);
}

void
Date::setDate(int year, int month, int day)
{
    setYear(year);
    setMonth(month);
    setDay(day);
}

void
Date::setYear(int year)
{
    if (year < 1) {
        year_ = 1;
        return;
    }
    year_ = year;
}

void
Date::setMonth(int month)
{
    if (month < 1 || month > 12) {
        month_ = 1;
        return;
    }
    month_ = month;
}

void
Date::setDay(int day)
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
Date::getYear()
{
    return year_;
}

int
Date::getMonth()
{
    return month_;
}

int
Date::getDay()
{
    return day_;
}


void
Date::nextDay()
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
Date::print()
{
    std::cout << getMonth() << '/' << getDay() << '/' << getYear() << std::endl;
}

