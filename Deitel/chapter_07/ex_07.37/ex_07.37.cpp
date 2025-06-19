#include <iostream>

int recursiveMinimum(int [], const int, const int = 0, int = 2147483647);

int
main()
{
    std::cout << std::endl;

    const int SIZE = 10;
    int array[SIZE];
    std::cout << "Enter " << SIZE << " numbers to find the smallest: ";
    for (int i = 0; i < SIZE; ++i) {
        std::cin >> array[i];
    }
    std::cout << "The smallest is " << recursiveMinimum(array, SIZE) << std::endl;

    std::cout << std::endl;
    return 0;
}

int
recursiveMinimum(int array[], const int size, const int first, int smallest)
{
    if (size == first) {
        return smallest;
    }
    if (smallest > array[first]) {
        smallest = array[first];
    }
    return recursiveMinimum(array, size, first + 1, smallest);
}

