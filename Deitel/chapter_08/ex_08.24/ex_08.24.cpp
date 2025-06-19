#include <iostream>

void quickSort(int [], int, int = -1);
void printArray(int [], int);

int
main()
{
    std::cout << std::endl;
    
    const int size = 10;
    int array[size] = {37, 2, 6, 4, 89, 8, 10, 12, 68, 45};

    printArray(array, size);
    quickSort(array, size);
    printArray(array, size);

    std::cout << std::endl;
    return 0;
}

void
quickSort(int array[], int last, int first)
{
    if (last - 1 == first) {
        return;
    }
    int newLast = last - 1;
    int newFirst = first + 1;
    int toSwap = newFirst;
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = newLast; i >= newFirst; --i) {
            if (array[i] < array[newFirst]) {
                std::swap(array[i], array[newFirst]);
                newLast = i;
                newFirst = newFirst + 1;
                toSwap = i;
                swapped = true;
                break;
            }
        }
        for (int i = newFirst; i <= newLast; ++i) {
            if (array[i] > array[newLast]) {
                std::swap(array[i], array[newLast]);
                newLast = newLast - 1;
                newFirst = i;
                toSwap = i;
                swapped = true;
                break;
            }
        }
    }
    quickSort(array, toSwap, first);
    quickSort(array, last, toSwap);
}

void
printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

