#include <iostream>

void printArray(int [], const int, const int = 0);

int
main()
{
    std::cout << std::endl;

    const int SIZE = 10;
    int array[SIZE] = {2, 0, 3, 5, 9, 8, 6, 4, 1, 7};
    printArray(array, SIZE);
    std::cout << std::endl;

    std::cout << std::endl;
    return 0;
}

void
printArray(int array[], const int size, const int first)
{
    if (size == first) { return; }
    std::cout << array[first] << ' ';
    printArray(array, size, first + 1);
}

