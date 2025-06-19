#include <iostream>

int strlen(const char *);
char * strtok(char *);
void printReverseTokens(char *);

int
main()
{
    std::cout << std::endl;

    const int SIZE = 50;
    char string[SIZE];
    std::cin.getline(string, SIZE);
    printReverseTokens(string);

    std::cout << std::endl;
    return 0;
}

int
strlen(const char *string)
{
    int i;
    for (i = 0; *(string + i) != '\0'; ++i);
    return i;
}

char *
strtok(char *string)
{
    int length = strlen(string) - 1;
    for (int i = length; *(string + length) != ' '; --length);
    *(string + length) = '\0';
    return string + (length + 1);
}

void
printReverseTokens(char *string)
{
    int i;
    for (i = 0; *(string + i) != ' '; ++i);
    while (*(string + i) != '\0') {
        std::cout << strtok(string) << ' ';
    }
    std::cout << string << std::endl;
}

