#include <iostream>

int linearSearch(int [], const int, int);
void printArray(int [], const int);

int
main()
{
    std::cout << std::endl;

    const int SIZE = 10;
    int array[SIZE] = {99, 25, 4, 0, 48, 36, 586, 24, 596, 1};
    printArray(array, SIZE);

    std::cout << "Enter positive number to search in the array: ";
    int number;
    std::cin >> number;
    if (number < 0) {
        std::cerr << "\nErreo 1: Negative." << std::endl;
        return 1;
    }
    int subscript = linearSearch(array, SIZE, number);
    if (subscript == -1) {
        std::cout << "The number isn't in the array." << std::endl;
    } else {
        std::cout << "The number is in the array under subscript " << subscript << std::endl;
    }

    std::cout << std::endl;
    return 0;
}

int
linearSearch(int array[], const int size, int key)
{
    if (0 == size) { return -1; }
    if (key == array[size - 1]) { return size - 1; }
    return linearSearch(array, size - 1, key);
}

void
printArray(int array[], const int size)
{
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

