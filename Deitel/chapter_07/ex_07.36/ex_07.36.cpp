#include <iostream>

void stringReverse(char [], int = 0);

int
main()
{
    std::cout << std::endl;

    const int LENGTH = 28;
    char string[LENGTH];
    std::cout << "Enter some string to reverse: ";
    std::cin.getline(string, LENGTH);

    stringReverse(string);
    std::cout << std::endl;

    std::cout << std::endl;
    return 0;
}

void
stringReverse(char string[], int first)
{
    if (string[first] == '\0' ) { return; }
    stringReverse(string, first + 1);
    std::cout << string[first];
}

