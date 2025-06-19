#include <iostream>

template <typename T>
T max(T, T, T);

int
main()
{
    std::cout << "\nEnter three integers: ";
    int integer1, integer2, integer3;
    std::cin >> integer1 >> integer2 >> integer3;
    std::cout << "The max is " << max(integer1, integer2, integer3) << std::endl;

    std::cout << "\nEnter three characters: ";
    char char1, char2, char3;
    std::cin >> char1 >> char2 >> char3;
    std::cout << "The max is " << max(char1, char2, char3) << std::endl;

    std::cout << "\nEnter two floating point numbers: ";
    float float1, float2, float3;
    std::cin >> float1 >> float2 >> float3;
    std::cout << "The max is " << max(float1, float2, float3) << std::endl;

    std::cout << std::endl;
    return 0;
}

template <typename T>
T
max(T x, T y, T z)
{
    if (x > y && x > z) {
        return x;
    }
    if (y > x && y > z) {
        return y;
    }
    return z;
}

