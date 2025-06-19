#ifndef __TIME_HPP__
#define __TIME_HPP__

class Time
{
public:
    Time(const int hour = 0, const int minute = 0, const int second = 0 );

    void setTime(const int hour, const int minute, const int second);
    void setHour(const int hour);
    void setMinute(const int minute);
    void setSecond(const int second);

    int getHour();
    int getMinute();
    int getSecond();

    void printUniversal();
    void printStandard();
private:
    int hour_;
    int minute_;
    int second_;
};

#endif
