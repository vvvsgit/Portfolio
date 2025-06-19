#include <iostream>

bool mystery3(const char *, const char *);

int
main()
{
    std::cout << std::endl;
    char string1[80], string2[80];

    std::cout << "Enter two strings: ";
    std::cin >> string1 >> string2;
    std::cout << "The result is " << mystery3(string1, string2) << std::endl;

    std::cout << std::endl;
    return 0;
}

bool
mystery3(const char *s1, const char *s2)
{
    for ( ; *s1 != '\0' && *s2 != '\0'; ++s1, ++s2) {
        if (*s1 != *s2) {
            return false;
        }
    }
    return true;
}

