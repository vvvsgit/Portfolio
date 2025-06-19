#include <iostream>

int
main()
{
    double myPi = 0;
    int count = 1;
    double pi = 3.14159;
    int accuracy = 100;
    std::cout << std::endl;
    for (int i = 1, four = 4; accuracy < 1000000; i += 2, four *= -1) {
        myPi += static_cast<double>(four) / i;
        int py = static_cast<int>(myPi * accuracy);
        if (py == static_cast<int>(pi * accuracy)) {
            std::cout << count << ". = " << py / accuracy << '.' << py % accuracy << std::endl;
            accuracy *= 10;
        }
        ++count;
    }
    std::cout << std::endl;
    return 0;
}

