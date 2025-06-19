#include <iostream>
#include <cassert>

template <typename T>
T fibonacci(T);

int
main()
{
    char charType = 1;
    std::cout << "\nMax fibonacci for char is " << static_cast<int>(fibonacci(charType)) << std::endl;
    short shortType = 1;
    std::cout << "\nMax fibonacci for short is " << fibonacci(shortType) << std::endl;
    int intType = 1;
    std::cout << "\nMax fibonacci for int is " << fibonacci(intType) << std::endl;
    double doubleType = 1;
    std::cout << "\nMax fibonacci for double is " << fibonacci(doubleType) << std::endl;
    long double longDoubleType = 1;
    std::cout << "\nMax fibonacci for long double is " << fibonacci(longDoubleType) << std::endl;
    std::cout << std::endl;
    return 0;
}

template <typename T>
T
fibonacci(T number)
{
    assert(number != 0);
    T a = 1;
    T b = 1;
    for (int i = 2; number; ++i) {
        b = a + b;
        a = b - a;
        T c = a + b;
        if (c < b || c == c + b) {
            std::cout << ++i << "th number - ";
            return b;
        }
    }
    return b;
}

