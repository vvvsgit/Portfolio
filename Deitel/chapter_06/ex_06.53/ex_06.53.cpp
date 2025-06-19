#include <iostream>

float cube(float);
float cube(float number)
{
    return number * number * number;
}

double square(double number)
{
    return number * number;
}

int sum(int n)
{
    if(n == 0) {
        return 0;
    } else {
        return n + sum(n - 1);
    }
}

int
main()
{
    {
    register int x = 7;
    }

    {
    int randomNumber = rand();
    }

    {
    float y = 123.45678;
    float x;
    x = y;
    std::cout << x << std::endl;
    }

    return 0;
}

