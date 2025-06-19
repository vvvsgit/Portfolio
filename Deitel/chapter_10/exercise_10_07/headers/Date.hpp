#ifndef __DATE_HPP__
#define __DATE_HPP__

#include <string>

class Date
{
    enum Format {DDDYYYY, MMDDYYYY, MonthDDYYYY, INVALID};
public:
    static Format getFormat(const std::string& date);

private:
    static Format formatDDDYYYY(const std::string& date);
    static Format formatMMDDYYYY(const std::string& date);
    static Format formatMonthDDYYYY(const std::string& date);

public:
    Date();
    Date(const std::string& date);
    Date(const Format format, const std::string& date);

    void setYear(const int year);
    void setMonth(const int month);
    void setDay(const int day);

    int getYear() const;
    int getMonth() const;
    int getDay() const;

    void printDDDYYYY() const;
    void printMMDDYYYY() const;
    void printMonthDDYYYY() const;

private:

    void setDateFormat1(const std::string& date);
    void setDateFormat2(const std::string& date);
    void setDateFormat3(const std::string& date);

    void calculateCurrentDayAndYear(int& day, int&  year) const;
    void calculateCurrentMonth(int& month, int& day, const int year) const;

    int checkDay(const int day) const;
    bool isLeapYear(const int year) const;
    int stringToInt(const std::string& number, const size_t start, const size_t end) const;

private:
    int month_;
    int day_;
    int year_;
 
};

#endif

