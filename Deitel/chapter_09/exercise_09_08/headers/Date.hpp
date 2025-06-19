#ifndef DATE_H
#define DATE_H

class Date
{
public:
    Date(int day = 1, int month = 1, int year = 2000);
    
    void setDate(int day, int month, int year);
    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
    int getYear();
    int getMonth();
    int getDay();

    void nextDay();
    void print();

private:
    int month_;
    int day_;
    int year_;
};

#endif
