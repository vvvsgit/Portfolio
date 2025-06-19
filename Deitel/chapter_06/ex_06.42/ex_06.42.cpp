#include <iostream>

void hanoi(int, int peg1 = 1, int peg2 = 2, int peg3 = 3);

int
main()
{
    std::cout << "\nEnter number for hanoi tower disks (1 - 64): ";
    int number;
    std::cin >> number;
    if (number < 1 || number > 64) {
        std::cerr << "\nError 1: Out of rage." << std::endl;
        return 1;
    }
    hanoi(number);
    std::cout << std::endl;
    return 0;
}

void
hanoi(int number, int peg1, int peg2, int peg3)
{
    static int c = 0;
    if (number == 0) {
        return;
    }

    hanoi(number - 1, peg1, peg3, peg2);
    std::cout << ++c << ". ";
    std::cout << peg1 << " -> " << peg3 << std::endl;

    hanoi(number - 1, peg2, peg1, peg3);
}

