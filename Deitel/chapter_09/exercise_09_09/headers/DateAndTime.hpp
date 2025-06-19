#ifndef __DateAndTIME_HPP__
#define __DateAndTIME_HPP__

class DateAndTime
{
public:
    DateAndTime(const int hour = 1, const int minut = 1, const int second = 1,
                const int day = 1, const int month = 1, const int year = 1);

    void setTime(const int hour, const int minute, const int second);
    void setDate(const int day, const int month, const int year);

    void setHour(const int hour);
    void setMinute(const int minute);
    void setSecond(const int second);
    void setYear(const int year);
    void setMonth(const int month);
    void setDay(const int day);

    int getYear();
    int getMonth();
    int getDay();
    int getHour();
    int getMinute();
    int getSecond();

    void printUniversal();
    void printStandard();

    void tick();
    void nextDay();

private:
    int year_;
    int month_;
    int day_;
    int hour_;
    int minute_;
    int second_;
};

#endif

