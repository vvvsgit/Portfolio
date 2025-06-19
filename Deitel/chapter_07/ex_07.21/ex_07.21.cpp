#include <iostream>

void someFunction(int [], int, int);

int
main()
{
    std::cout << std::endl;

    const int arraySize = 10;
    int a[arraySize] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "The values in the array are:" << std::endl;
    someFunction(a, 0, arraySize);
    std::cout << std::endl;

    std::cout << std::endl;
    return 0;
}

void someFunction (int b[], int current, int size)
{
    if (current < size) {
        someFunction(b, current + 1, size);
        std::cout << b[current] << ' ';
    }
}

