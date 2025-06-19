#ifndef __DATE_HPP__
#define __DATE_HPP__

#include <iostream>

class Date
{
    friend std::ostream& operator<<(std::ostream& output, const Date& date);
public:
    Date(const int month = 1, const int day = 1, const int year = 1900);

    void setDate(const int month, const int day, const int year);
    int getMonth() const;
private:
    bool endOfMonth(const int tesDay) const;
private:
    static bool leapYear(const int testYear);
private:
    static const int days[];
private:
    int month_;
    int day_;
    int year_;
};

#endif

