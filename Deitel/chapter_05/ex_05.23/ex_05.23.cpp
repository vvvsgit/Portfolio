#include <iostream>

int
main()
{
    std::cout << std::endl;
    int number = 9;
    for (int i = 1; i <= number; ++i) {
        std::cout << '\t';
        for (int j = 1; j <= number; ++j) {
            std::cout << (abs(i - (number + 1) / 2) + abs(j - (number + 1) / 2) <= number / 2 ? '*' : ' ');
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return 0;

}

