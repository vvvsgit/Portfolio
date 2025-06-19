#include <iostream>
#include <cassert>

int strcmpSubscripting(const char *, const char *);
int strcmpArithmetic(const char *, const char *);

int
main()
{
    std::cout << std::endl;

    std::cout << "Enter two strings:" << std::endl;
    const int SIZE = 50;
    char string1[SIZE];
    char string2[SIZE];
    std::cin >> string1 >> string2;

    std::cout << "strcmprSubscripting - ";
    std::cout << "String 1 is ";
    switch (strcmpSubscripting(string1, string2)) {
    case -1: std::cout << "less than string2." << std::endl; break;
    case 0:  std::cout << "equal to string2." << std::endl;     break;
    case 1:  std::cout << "greater than string2." << std::endl;  break;
    default: assert(0);                                          break;
    }
    std::cout << "strcmprArithmetic - ";
    std::cout << "String 1 is ";
    switch (strcmpArithmetic(string1, string2)) {
    case -1: std::cout << "less than string2." << std::endl; break;
    case 0:  std::cout << "equal to string2." << std::endl;     break;
    case 1:  std::cout << "greater than string2." << std::endl;  break;
    default: assert(0);                                          break;
    }

    std::cout << std::endl;
    return 0;
}

int
strcmpArithmetic(const char *string1, const char *string2)
{
    while (*string1 != '\0' || *string2 != '\0') {
        if (*string1 > *string2) {
            return 1;
        }
        if (*string1 < *string2) {
            return -1;
        }
        ++string1;
        ++string2;
    }
    if (*string1 != '\0') {
        return 1;
    }
    if (*string2 != '\0') {
        return -1;
    }
    return 0;
}

int
strcmpSubscripting(const char *string1, const char *string2)
{
    int i;
    for (i = 0; string1[i] != '\0' || string2[i] != '\0'; ++i) {
        if (string1[i] > string2[i]) {
            return 1;
        }
        if (string1[i] < string2[i]) {
            return -1;
        }
    }
    if (string1[i] != '\0') {
        return 1;
    }
    if (string2[i] != '\0') {
        return -1;
    }
    return 0;
}

