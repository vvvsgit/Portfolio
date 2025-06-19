#include "Date.hpp"

#include <iostream>

Date::Date(int month, int day, int year)
{
    setMonth(month);
    setDay(day);
    setYear(year);
}

void
Date::setMonth(int month)
{
    if (month < 1) {
        std::cout << "Invalid month, set to 1." << std::endl;
        month_ = 1;
        return;
    }
    if (month > 12) {
        std::cout << "Invalid month, set to 1." << std::endl;
        month_ = 1;
        return;
    }
    month_ = month;
}

void
Date::setDay(int day)
{
    if (day < 1) {
        std::cout << "Invalid day, set to 1." << std::endl;
        day_ = 1;
        return;
    }
    day_ = day;
}

void
Date::setYear(int year)
{
    year_ = year;
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

int
Date::getYear()
{
    return year_;
}

void
Date::displayDate()
{
    std::cout << "\t\n" << getMonth() << '/' << getDay() << '/' << getYear() << '\n' << std::endl;
}

