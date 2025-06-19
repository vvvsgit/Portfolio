#include <iostream>

void bucketSort(int [], const int);
void printArray(int [], const int);
bool isSorted(int [], const int);

int
main()
{
    std::cout << std::endl;

    const int SIZE = 10;
    int array[SIZE];
    std::cout << "Enter " << SIZE << " numbers to sort(positive): ";
    for (int i = 0; i < SIZE; ++i) {
        std::cin >> array[i];
        if (array[i] < 1) {
            std::cerr << "\nError 1: Negative." << std::endl;
            return 1;
        }
    }

    std::cout << "\nArray before sorting." << std::endl;
    printArray(array, SIZE);
    
    bucketSort(array, SIZE);

    std::cout << "\nArray after sorting." << std::endl;
    printArray(array, SIZE);

    std::cout << std::endl;
    return 0;
}

void
bucketSort(int array[], const int size)
{
    int bucket[10][size];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < size; ++j) {
            bucket[i][j] = 0;
        }
    }
    for (int tents = 1; !isSorted(array, size); tents *= 10) {
        for (int i = 0; i < size; ++i) {
            bucket[(array[i] % (tents * 10)) / tents][i] = array[i];
        }
        int k = 0;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < size; ++j) {
                if (bucket[i][j] > 0) {
                    array[k] = bucket[i][j];
                    bucket[i][j] = 0;
                    ++k;
                }
            }
        }
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

bool
isSorted(int array[], const int size)
{
    for (int i = 1; i < size; ++i) {
        if (array[i - 1] > array[i]) {
            return false;
        }
    }
    return true;
}

