#include <iostream>

template <typename T>
T min(T, T);

int
main()
{
    std::cout << "\nEnter two integers: ";
    int integer1, integer2;
    std::cin >> integer1 >> integer2;
    std::cout << "The min is " << min(integer1, integer2) << std::endl;

    std::cout << "\nEnter two characters: ";
    char char1, char2;
    std::cin >> char1 >> char2;
    std::cout << "The min is " << min(char1, char2) << std::endl;

    std::cout << "\nEnter two floating point numbers: ";
    float float1, float2;
    std::cin >> float1 >> float2;
    std::cout << "The min is " << min(float1, float2) << std::endl;

    std::cout << std::endl;
    return 0;
}

template <typename T>
T
min(T x, T y)
{
    if (x > y) {
        return y;
    }
    return x;
}

