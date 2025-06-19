#include "headers/Date.hpp"

int
main()
{
    Date date1("12/21/2001");
    Date date2("355 2001");
    Date date3("01/18/2025");
    Date date4("018 2025");
    Date date5("02/29/2000");
    Date date6("060 2000");
    Date date7("02/28/2001");
    Date date8("060 2001");
    Date date9("May 15, 1111");
    Date date10("January 15, 1111");
    Date date11("December 15, 1111");
    Date date12;
    date12.printMMDDYYYY();
    date12.printDDDYYYY();
    date12.printMonthDDYYYY();
    return 0;
}

