#include "headers/Date.hpp"

#include <iostream>
#include <string>
const int Date::days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date(const int month, const int day, const int year)
{
    setDate(month, day, year);
}

void Date::setDate(const int month, const int day, const int year)
{
    month_ = (month >= 1 && month <= 12) ? month : 1;
    year_ = (year >= 1900 && year <= 2100) ? year : 1900;

    if (month_ == 2 && leapYear(year_)) {
        day_ = (day >= 1 && day <= 29) ? day : 1;
    } else {
        day_ = (day >= 1 && day <= days[month_]) ? day : 1;
    }
}

int
Date::getMonth() const
{
    return month_;
}

bool Date::leapYear(const int testYear)
{
    if (testYear % 400 == 0 || (testYear % 100 != 0 && testYear % 4 == 0)) {
        return true;
    } else {
        return false;
    }
}

bool Date::endOfMonth(const int testDay) const
{
    if (month_ == 2 && leapYear(year_)) {
        return testDay == 29;
    } else {
        return testDay == days[month_];
    }
}

std::ostream&
operator<<(std::ostream& output, const Date& date)
{
    static std::string monthName[12] = {"January", "February", "March",
                                        "April", "May", "June", "July",
                                        "August", "September", "October",
                                        "November", "December"};
    output << monthName[date.month_ - 1] << ' ' << date.day_ << ", " << date.year_;
    return output;
}

