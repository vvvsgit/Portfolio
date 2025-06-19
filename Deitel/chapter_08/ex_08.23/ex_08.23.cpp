#include <iostream>

int
main()
{
    std::cout << std::endl;

    int *number = NULL;
    std::cout << number << std::endl;

    double *realPtr;
    double *integerPtr;
    integerPtr = realPtr;

    int *x, *y;
    x = y;

    char s[] = "this is a character array";
    for (int i = 0; *(s + i) != '\0'; ++i) {
        std::cout << *(s + i) << ' ';
    }
    std::cout << std::endl;

    short *numPtr, result;
    short *genericPtr = numPtr;
    result = *genericPtr + 7;

    double z = 19.34;
    double *zPtr = &z;
    std::cout << zPtr << std::endl;

    char *str = s;
    std::cout << str << std::endl;

    std::cout << std::endl;
    return 0;
}

