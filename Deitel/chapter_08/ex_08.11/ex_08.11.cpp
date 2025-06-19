#include <iostream>

void zero(long int bigIntegers[], const int size);
int add1AndSum(int oneTooSmall[], const int size);

int
main()
{
    std::cout << std::endl;
    std::cout << std::endl;
    return 0;
}

void
zero(long int bigIntegers[], const int size)
{
}

int
add1AndSum(int oneTooSmall[], const int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += oneTooSmall[i];
    }
    return 1 + sum;
}

