#include <iostream>

int
main()
{
    std::cout << "\nEnter three nonzero integers: ";
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a <= 0) {
        std::cerr << "\nError 1: Nonzero said." << std::endl;
        return 1;
    }
    if (b <= 0) {
        std::cerr << "\nError 1: Nonzero said." << std::endl;
        return 1;
    }
    if (c <= 0) {
        std::cerr << "\nError 1: Nonzero said." << std::endl;
        return 1;
    }
    if (a + b <= c) {
        std::cout << "\nIt's not a triangle." << std::endl;
        return 0;
    }
    if (a + c < b) {
        std::cout << "\nIt's not a triangle." << std::endl;
        return 0;
    }
    if (b + c <= a) {
        std::cout << "\nIt's not a triangle." << std::endl;
        return 0;
    }
    if (a * a + b * b == c * c) {
        std::cout << "\nIt's a right triangle." << std::endl;
        return 0;
    }
    if (a * a + c * c == b * b) {
        std::cout << "\nIt's a right triangle." << std::endl;
        return 0;
    }
    if (b * b + c * c == a * a) {
        std::cout << "\nIt's a right triangle." << std::endl;
        return 0;
    }
    std::cout << "\nIt's not a right triangle." << std::endl;
    return 0;
}

