#include <iostream>

bool isUnique(int [], const int, int);

int
main()
{
    std::cout << std::endl;

    std::cout << "Enter 20 number (10 - 100): ";
    const int size = 19;
    int unique[size] = {0};
    int next;
    for (int i = 0; i < size + 1; ++i) {
        std::cin >> next;
        if (next < 20 || next > 100) {
            std::cerr << "\nError 1: wrong number." << std::endl;
            return 1;
        }
        if (i == size) { break; }
        if (isUnique(unique, size, next)) {
            unique[i] = next;
        }
    }
    for (int i = 0; i < size; ++i) {
        if (unique[i] != 0) {
            std::cout << unique[i] << ' ';
        }
    }
    if (isUnique(unique, size, next)) {
        std::cout << next << std::endl;
    }

    std::cout << std::endl;
    return 0;
}

bool
isUnique(int array[], const int size, int number)
{
    for (int i = 0; i < size; ++i) {
        if (number == array[i]) {
            return false;
        }
    }
    return true;
}

