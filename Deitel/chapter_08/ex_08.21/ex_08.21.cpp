#include <iostream>

void mystery1(char *, const char *);

int
main()
{
    std::cout << std::endl;

    char string1[80];
    char string2[80];

    std::cout << "Enter two strings: ";
    std::cin >> string1 >> string2;
    mystery1(string1, string2);
    std::cout << string1 << std::endl;

    std::cout << std::endl;
    return 0;
}

void
mystery1(char *s1, const char *s2)
{
    while (*s1 != '\0') {
        ++s1;
    }
    for (; *s1 = *s2; ++s1, ++s2);
}

