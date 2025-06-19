#include <iostream>

int
main()
{
    std::cout << std::endl;

    const int size1 = 10;
    int counts[size1] = {0};
    
    const int size2 = 15;
    int bonus[size2] = {0};
    for (int i = 0; i < size2; ++i) {
        ++bonus[i];
    }

    const int size3 = 12;
    double monthlyTemperatures[size3];
    for (int i = 0; i < size3; ++i) {
        std::cin >> monthlyTemperatures[i];
    }

    const int size4 = 5;
    int bestScores[size4];
    for (int i = 0; i < size4; ++i) {
        std::cout << bestScores[i] << std::endl;
    }

    std::cout << std::endl;
    return 0;
}

