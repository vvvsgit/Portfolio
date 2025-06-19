#include <iostream>

int mystery2(const char *);

int
main()
{
    std::cout << std::endl;

    char string1[80];

    std::cout << "Enter a string: ";
    std::cin >> string1;
    std::cout << mystery2(string1) << std::endl;

    std::cout << std::endl;
    return 0;
}

int
mystery2(const char *s)
{
    int x;
    for (x = 0; *s != '\0'; ++s) {
        ++x;
    }

    return x;
}

