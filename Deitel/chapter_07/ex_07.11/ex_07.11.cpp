#include <iostream>

void fillArray(int [], const int);
void printArray(int [], const int);
void bubbleSort(int [], const int);

int
main()
{
    std::cout << std::endl;
    const int length = 10;
    int sortingArray[length];
    fillArray(sortingArray, length);

    std::cout << "Array before sorting." << std::endl;
    printArray(sortingArray, length);

    bubbleSort(sortingArray, length);

    std::cout << "Array after sorting." << std::endl;
    printArray(sortingArray, length);

    std::cout << std::endl;
    return 0;
}

void
fillArray(int array[], const int size)
{
    std::cout << "Enter arays elements(" << size << ") ";
    for (int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }
}

void
printArray(int array[], const int size)
{
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

void
bubbleSort(int array[], const int size)
{
    bool swapped = true;
    while (swapped == true) {
        swapped = false;
        for (int i = 1; i < size; ++i) {
            if (array[i - 1] > array[i]) {
                swapped = true;
                int tempo = array[i - 1];
                array[i - 1] = array[i];
                array[i] = tempo;
            }
        }
    }
}

