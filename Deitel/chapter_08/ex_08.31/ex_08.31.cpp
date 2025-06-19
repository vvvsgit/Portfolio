#include <iostream>
#include <cassert>

int strcmp(const char *, const char *, int);

int
main()
{
    std::cout << std::endl;

    std::cout << "Enter two strings:" << std::endl;
    const int SIZE = 50;
    char string1[SIZE];
    char string2[SIZE];
    std::cin >> string1 >> string2;
    std::cout << "Enter number of characters to compare: ";
    int number;
    std::cin >> number;
    if (number < 0) {
        std::cerr << "\nError 1: negative number." << std::endl;
        return 1;
    }
    //std::cout << "string1[2] = " << string1[2] << std::endl;
    int stringLength = 0;
    for (int i = 0; string1[i] != '\0' && string2[i] != '\0'; ++i) {
        ++stringLength;
    }
    if (number > stringLength) {
        std::cout << "Warning 1: The written number is bigger than one of string's length. Set to " << stringLength << std::endl;
        number = stringLength;
    }

    std::cout << "String 1 is ";
    switch (strcmp(string1, string2, number)) {
    case -1: std::cout << "less than string2." << std::endl;     break;
    case 0:  std::cout << "equal to string2." << std::endl;      break;
    case 1:  std::cout << "greater than string2." << std::endl;  break;
    default: assert(0);                                          break;
    }

    std::cout << std::endl;
    return 0;
}

int
strcmp(const char *string1, const char *string2, int number)
{
    assert(number > 0);
    for (int i = 0; i < number; ++i) {
        if (*string1 > *string2) {
            return 1;
        }
        if (*string1 < *string2) {
            return -1;
        }
        ++string1;
        ++string2;
    }
    return 0;
}

