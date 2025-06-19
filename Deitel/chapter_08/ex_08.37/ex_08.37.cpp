#include <iostream>
#include <cassert>

int strcmp(const char *, const char *);
void quickSort(char *[], int, int = -1);
void printArray(char *[], int);

int
main()
{
    std::cout << std::endl;

    const int SIZE = 10;
    char *towns[SIZE] = {"Germany", "Haiti", "Mauritania", "Grenada", "Tuvalu",
                         "Cambodia", "Kiribati", "Peru", "Bermuda", "Congo"};

    printArray(towns, SIZE);
    std::cout << std::endl;
    quickSort(towns, SIZE);
    printArray(towns, SIZE);
    std::cout << std::endl;

    char *ABC[26] = {"M", "N", "B", "V", "C", "X", "Z", "A", "S",
                     "D", "F", "G", "H", "J", "K", "L", "P", "O",
                     "I", "U", "Y", "T", "R", "E", "W", "Q"};

    printArray(ABC, 26);
    std::cout << std::endl;
    quickSort(ABC, 26);
    printArray(ABC, 26);
    std::cout << std::endl;

    return 0;
}

int
strcmp(const char *string1, const char *string2)
{
    while (*string1 != '\0' || *string2 != '\0') {
        if (*string1 > *string2) {
            return 1;
        }
        if (*string1 < *string2) {
            return -1;
        }
        ++string1;
        ++string2;
    }
    if (*string1 != '\0') {
        return 1;
    }
    if (*string2 != '\0') {
        return -1;
    }
    return 0;
}

void
quickSort(char *array[], int last, int first)
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
            if (strcmp(array[i], array[newFirst]) == -1) {
                std::swap(array[i], array[newFirst]);
                newLast = i;
                newFirst = newFirst + 1;
                toSwap = i;
                swapped = true;
                break;
            }
        }
        for (int i = newFirst; i <= newLast; ++i) {
            if (strcmp(array[i], array[newLast]) == 1) {
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
printArray(char *array[], int size)
{
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << std::endl;
    }
}

