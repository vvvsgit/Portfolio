#include <iostream>

template <class A>
A sum(A num1, A num2, A num3)
{
    return num1 + num2 + num3;
}

int printResults(int x, int y)
{
    std::cout << "The sum is " << x + y << '\n';
    return x + y;
}

template <typename T>
T product(T num1, T num2, T num3)
{
    return num1 * num2 * num3;
}

double cube(double);
int cube(int);

int
main()
{
    return 0;
}

