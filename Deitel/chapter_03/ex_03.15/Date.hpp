class Date
{
public:
    Date(int, int, int);
    void setMonth(int);
    void setDay(int);
    void setYear(int);
    int getMonth();
    int getDay();
    int getYear();
    void displayDate();
private:
    int month_;
    int day_;
    int year_;
};

