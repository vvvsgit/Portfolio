#include <iostream>
using namespace std;

int
main()
{
    int x = 9, y = 11;
    cout << "a." << endl;
    if (x < 10)
    if (y > 10)
    cout << "*****" << endl;
    else
    cout << "#####" << endl;
    cout << "$$$$$" << endl;

    cout << "b." << endl;
    if (x < 10)
    {
    if (y > 10)
    cout << "*****" << endl;
    }
    else
    {
    cout << "#####" << endl;
    cout << "$$$$$" << endl;
    }

    cout << "_____\n" << endl;

    x = 11;
    y = 9;
    cout << "a." << endl;
    if (x < 10)
    if (y > 10)
    cout << "*****" << endl;
    else
    cout << "#####" << endl;
    cout << "$$$$$" << endl;

    cout << "b." << endl;
    if (x < 10)
    {
    if (y > 10)
    cout << "*****" << endl;
    }
    else
    {
    cout << "#####" << endl;
    cout << "$$$$$" << endl;
    }

    return 0;
}

