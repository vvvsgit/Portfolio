#include "headers/Date.hpp"

#include <iostream>
#include <iomanip>
#include <cassert>
#include <string>
#include <ctime>

static const int DAYS_PER_MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static const char* MONTHS[] = {"January", "February", "March", "April", "May", "June",
                               "July", "August", "September", "October", "November", "December"};

Date::Date(const Date::Format givenFormat, const std::string& date)
{
    const Date::Format format = getFormat(date);
    assert(format == givenFormat);
    switch(givenFormat) {
    case DDDYYYY:     setDateFormat1(date); break;
    case MMDDYYYY:    setDateFormat2(date); break;
    case MonthDDYYYY: setDateFormat3(date); break;
    default: assert(0);                     break;
    }
}

Date::Date()
{
    int day = std::time(0) / (24 * 60 * 60) + 1;
    int year = 1970;
    calculateCurrentDayAndYear(day, year);
    int month = 1;
    calculateCurrentMonth(month, day, year);
    
    setYear(year);
    setMonth(month);
    setDay(day);
}

void
Date::calculateCurrentDayAndYear(int& day, int& year) const
{
    while (day > 366) {
        day -= (isLeapYear(year) ? 366 : 365);
        ++year;
    }
    if (day == 366 && !isLeapYear(year)) {
        day -= 365;
        ++year;
    }
}

void
Date::calculateCurrentMonth(int& month, int& day, const int year) const
{
    while (day > 31) {
        switch (month) {
        case 4: case 6: case 9: case 11: day -= 30; break;
        case 2: day -= (isLeapYear(year) ? 29 : 28); break;
        default: day -= 31; break;
        }
        ++month;
    }
    if (day > 28) {
        switch (month) {
        case 4: case 6: case 9: case 11: if (day == 31) { day -= 30; ++month; } break;
        case 2: 
            if (day == 30) {
                day -= (isLeapYear(year) ? 29 : 28);
                ++month;
            } else if (day == 29 && !isLeapYear(year)) {
                day -= 28;
                ++month;
            }
            break;
        default: break;
        }
    }
}

Date::Date(const std::string& date)
{
    const Date::Format format = getFormat(date);
    assert(format != INVALID);
    switch(format) {
    case DDDYYYY:     setDateFormat1(date); break;
    case MMDDYYYY:    setDateFormat2(date); break;
    case MonthDDYYYY: setDateFormat3(date); break;
    default: assert(0);                     break;
    }
}

void
Date::setDateFormat1(const std::string& date)
{
    size_t start = 0;
    size_t end = start;
    for (; date[end] != ' '; ++end);
    const int day = stringToInt(date, start, end);

    start = ++end;
    end = date.length();
    setYear(stringToInt(date, start, end));

    const bool isLeap = isLeapYear(getYear());
    int days = 0;
    int month = 0;
    for (; month < 12; ++month) {
        if (isLeap && 1 == month) ++days;
        if ((days + DAYS_PER_MONTH[month]) >= day) break;
        days += DAYS_PER_MONTH[month];
    }
    setMonth(month + 1);

    setDay(day - days);
}

void
Date::setDateFormat2(const std::string& date)
{
    size_t start = 0;
    size_t end = start;
    for (; date[end] != '/'; ++end);
    setMonth(stringToInt(date, start, end));

    start = ++end;
    for (; date[end] != '/'; ++end);
    const int day = stringToInt(date, start, end);

    start = ++end;
    end = date.length();
    setYear(stringToInt(date, start, end));
    
    setDay(day);
}

void
Date::setDateFormat3(const std::string& date)
{
    size_t start = 0;
    size_t end = start;
    std::string monthString = "";
    for (; date[end] != ' '; ++end) {
        monthString += date[end];
    }
    int monthNumber = 0;
    for (; MONTHS[monthNumber] != monthString; ++monthNumber);
    setMonth(monthNumber + 1);

    start = ++end;
    for (; date[end] != ','; ++end);
    const int day = stringToInt(date, start, end);

    start = ++(++end);
    end = date.length();
    setYear(stringToInt(date, start, end));

    setDay(day);
}

int
Date::stringToInt(const std::string& number, const size_t start, const size_t end) const
{
    int result = 0;
    for (size_t i = start; i < end; ++i) {
        result = result * 10 + (number[i] - '0');
    }
    return result;
}

void
Date::setYear(const int year)
{
    assert(year > 0);
    year_ = year;
}

void
Date::setMonth(const int month)
{
    assert(month > 0 && month <= 12);
    month_ = month;
}

void
Date::setDay(const int day)
{
    assert(day > 0);
    if ((isLeapYear(getYear()) && day > 366) || (!isLeapYear(getYear()) && day > 365)) {
        assert(0);
    }
    day_ = checkDay(day);
}

int
Date::getDay() const
{
    return day_;
}

int
Date::getMonth() const
{
    return month_;
}

int
Date::getYear() const
{
    return year_;
}

void
Date::printMMDDYYYY() const
{
    const char fill = std::cout.fill('0');
    std::cout << std::setw(2) 
              << getMonth() << '/' << std::setw(2) 
              << getDay() << '/' << std::setw(4)  
              << getYear() << std::setfill(fill) << std::endl;
}

void
Date::printDDDYYYY() const
{
    int day = getDay();
    int month = getMonth() - 1;
    int year = getYear();
    while (month > 0) {
        switch (month) {
        case 4: case 6: case 9: case 11: day += 30; break;
        case 2: day += ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? 29 : 28); break;
        default: day += 31; break;
        }
        --month;
    }
    const char fill = std::cout.fill('0');
    std::cout << std::setw(3) 
              << day << ' ' << std::setw(4) 
              << year << std::setfill(fill) << std::endl;
}

void
Date::printMonthDDYYYY() const
{
    const char fill = std::cout.fill('0');
    std::cout << MONTHS[getMonth() - 1] << ' ' 
              << std::setw(2) << getDay() << ", " 
              << std::setw(4) << getYear() 
              << std::setfill(fill) << std::endl;
}

int 
Date::checkDay(const int testDay) const
{
    if (testDay > 0 && testDay <= DAYS_PER_MONTH[getMonth() - 1]) return testDay;
    if (getMonth() == 2 && testDay == 29 &&isLeapYear(getYear())) return testDay;
    return 1;
}
bool
Date::isLeapYear(const int year) const
{
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

Date::Format
Date::getFormat(const std::string& date)
{
    if ('A' <= date[0] && date[0] <= 'Z') {
        return formatMonthDDYYYY(date);
    }
    if (' ' == date[3]) {
        return formatDDDYYYY(date);
    }
    if ('/' == date[2]) {
        return formatMMDDYYYY(date);
    }
    return INVALID;
}

Date::Format
Date::formatDDDYYYY(const std::string& date)
{
    static const std::string rightFormat = "DDD YYYY";
    ///index[]                              01234567

    const size_t length = date.length();
    if (length != rightFormat.length()) return INVALID;

    if (date[3] != ' ') return INVALID;

    for (size_t i = 0; i < length; ++i) {
        if (3 == i) continue;
        if (date[i] < '0' || '9' < date[i]) return INVALID;
    }
    return DDDYYYY;
}

Date::Format
Date::formatMMDDYYYY(const std::string& date)
{
    static const std::string rightFormat = "MM/DD/YYYY";
    ///index[]                              0123456789

    const size_t length = date.length();
    if (length != rightFormat.length()) return INVALID;

    if (date[2] != '/' || date[5] != '/') return INVALID;

    for (size_t i = 0; i < length; ++i) {
        if (2 == i || 5 == i) continue;
        if (date[i] < '0' || '9' < date[i]) return INVALID;
    }
    return MMDDYYYY;
}

Date::Format
Date::formatMonthDDYYYY(const std::string& date)
{
    static const std::string rightFormat = "Month DD, YYYY";
    ///index[]                              .....9876543210 

    const size_t length = date.length();

    if (date[length - 5] != ' ' || date[length - 6] != ',' || date[length - 9] != ' ') return INVALID;

    for (size_t i = length - 1; i > length - 9; --i) {
        if (length - 5 == i || length - 6 == i) continue;
        if (date[i] < '0' || '9' < date[i]) return INVALID;
    }
    
    std::string month = "";
    for (size_t i = 0; i < length - 9; ++i) {
        month += date[i];
    }
    for (int i = 0; i <= 12; ++i) {
        if (12 == i) return INVALID;
        if (month == MONTHS[i]) break;
    }

    return MonthDDYYYY;
}

