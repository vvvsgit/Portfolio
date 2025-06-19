#include <iostream>

int
main()
{
    int count;
    for (int count2 = 1; count2 <= 10; ++count2) {
        if (count == 4) { count2 = 11; }
        std::cout << count << ' ';
        ++count;
    }
    std::cout << "\nBroke out of loop at count = " << count << std::endl;
    return 0;
}

