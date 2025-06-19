#include <iostream>

bool flip();

int
main()
{
    std::cout << std::endl;
    srand(time(0));
    int heads = 0;
    int tails = 0;
    for (int i = 0; i < 100000; ++i) {
        if (flip()) {
            ++heads;
            std::cout << "Heads" << std::endl;
        } else {
            ++tails;
            std::cout << "Tails" << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << "Heads " << heads << " times." << std::endl;
    std::cout << "Tails " << tails << " times." << std::endl;
    std::cout << std::endl;
    return 0;
}

bool
flip()
{
    return (rand() % 2 + 1) == 1;
}

