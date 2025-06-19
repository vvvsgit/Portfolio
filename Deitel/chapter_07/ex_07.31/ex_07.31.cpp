#include <iostream>

void selectionSort(int [], const int, const int = 0);
void printArray(int [], const int);

int
main()
{
    std::cout << std::endl;

    const int SIZE = 10;
    int array[SIZE];
    std::cout << "Enter numbers to fill array for sorting: ";
    for (int i = 0; i < SIZE; ++i) {
        std::cin >> array[i];
    }

    std::cout << "\nArray before sorting." << std::endl;
    printArray(array, SIZE);

    selectionSort(array, SIZE);

    std::cout << "\nArray after sorting." << std::endl;
    printArray(array, SIZE);

    std::cout << std::endl;
    return 0;
}

void
selectionSort(int array[], const int size, const int first)
{
    if (first == size) { return; }
    int smallest = array[first];
    int subNumber = first;
    for (int i = first + 1; i < size; ++i) {
        if (smallest > array[i]) {
            smallest = array[i];
            subNumber = i;
        }
    }
    array[subNumber] = array[first];
    array[first] = smallest;
    selectionSort(array, size, first + 1);
}

void
printArray(int array[], const int size)
{
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

