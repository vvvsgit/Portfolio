#include <iostream>
#include <cassert>

int strcmp(const char *, const char *);

int
main()
{
    std::cout << std::endl;

    std::cout << "Enter two strings:" << std::endl;
    const int SIZE = 50;
    char string1[SIZE];
    char string2[SIZE];
    std::cin >> string1 >> string2;

    std::cout << "String 1 is ";
    switch (strcmp(string1, string2)) {
    case -1: std::cout << "less than string2." << std::endl;     break;
    case 0:  std::cout << "equal to string2." << std::endl;      break;
    case 1:  std::cout << "greater than string2." << std::endl;  break;
    default: assert(0);                                          break;
    }

    std::cout << std::endl;
    return 0;
}

int
strcmp(const char *string1, const char *string2)
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

