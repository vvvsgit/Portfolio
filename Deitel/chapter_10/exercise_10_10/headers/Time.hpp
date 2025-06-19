#ifndef __TIME_HPP__
#define __TIME_HPP__

class Time
{
public:
    Time(const int hour = 0, const int minute = 0, const int second = 0);

    Time& setTime(const int hour, const int minute, const int second);
    Time& setHour(int hour);
    Time& setMinute(int minute);
    Time& setSecond(int second);

    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    void printUniversal() const;
    void printStandard() const;
private:
    int seconds_;
};

#endif

