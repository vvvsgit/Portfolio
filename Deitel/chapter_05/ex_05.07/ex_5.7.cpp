#include <iostream>

int
main()
{
    std::cout << "\nEnter two integers in the rage 1-20: ";
    int x, y;
    std::cin >> x >> y;
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            std::cout << '@';
        }
        std::cout << std::endl;
    }
    return 0;
}

