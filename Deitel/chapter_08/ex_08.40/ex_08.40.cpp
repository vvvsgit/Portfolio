#include <iostream>

int strlenArithmetic(const char *);
int strlenSubscripting(const char *);

int
main()
{
    std::cout << std::endl;

    const int SIZE = 50;
    char string[SIZE];
    std::cin >> string;
    std::cout << "strlen subscripting = " << strlenSubscripting(string) << std::endl;
    std::cout << "strlen arithmetic = " << strlenArithmetic(string) << std::endl;

    std::cout << std::endl;
    return 0;
}

int
strlenArithmetic(const char *string)
{
    int i;
    for (i = 0; *(string + i) != '\0'; ++i);
    return i;
}

int
strlenSubscripting(const char *string)
{
    int i;
    for (i = 0; string[i] != '\0'; ++i);
    return i;
}

