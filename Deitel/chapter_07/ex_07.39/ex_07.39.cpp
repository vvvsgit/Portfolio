#include <iostream>
#include <vector>

int rollDies();

int
main()
{
    std::cout << std::endl;

    std::srand(time(0));
    const int dieSum = 11;
    std::vector<int> diePossibility(dieSum);
    int rolledTimes = 360000;
    for (int i = 0; i < rolledTimes; ++i) {
        ++diePossibility[rollDies() - 2];
    }
    for (int i = 0; i < diePossibility.size(); ++i) {
        std::cout << i + 2 << " - " << diePossibility[i] << " times" << std::endl;
    }

    std::cout << std::endl;
    return 0;
}

int
rollDies()
{
    return (rand() % 6 + 1) + (rand() % 6 + 1);
}

