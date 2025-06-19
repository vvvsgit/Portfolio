#include <iostream>

int strlen(const char *);
void strcatSubscripting(char *, const char *);
void strcatArithmetic(char *, const char *);
void strcpySubscripting(char *, const char *);
void strcpyArithmetic(char *, const char *);

int
main()
{
    std::cout << std::endl;

    std::cout << "Enter two stings:" << std::endl;
    const int SIZE = 50;
    char string1[SIZE];
    char string2[SIZE];
    std::cin >> string1 >> string2;
    
    std::cout << "strcatSubscription - ";
    strcatSubscripting(string1, string2);
    std::cout << string1 << std::endl;

    std::cout << "strcpySubscription - ";
    strcpySubscripting(string2, string1);
    std::cout << string2 << std::endl;

    std::cout << "strcatArithmetic - ";
    strcatArithmetic(string2, string1);
    std::cout << string2 << std::endl;

    std::cout << "strcpyArithmetic - ";
    strcpyArithmetic(string1, string2);
    std::cout << string1 << std::endl;

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

void
strcatArithmetic(char *string1, const char *string2)
{
    int i = strlen(string1);
    int j;
    for (j = 0; *(string2 + j) != '\0'; ++j) {
        *(string1 + i) = *(string2 + j);
        ++i;
    }
    *(string1 + i) = *(string2 + j);
}

void
strcatSubscripting(char *string1, const char *string2)
{
    int i = strlen(string1);
    int j;
    for (j = 0; string2[j] != '\0'; ++j) {
        string1[i] = string2[j];
        ++i;
    }
    string1[i] = string2[j];
}

void
strcpyArithmetic(char *string1, const char *string2)
{
    int i;
    for (i = 0; *(string2 + i) != '\0'; ++i) {
        *(string1 + i) = *(string2 + i);
    }
    *(string1 + i) = *(string2 + i);
}

void
strcpySubscripting(char *string1, const char *string2)
{
    int i;
    for (i = 0; string2[i] != '\0'; ++i) {
        string1[i] = string2[i];
    }
    string1[i] = string2[i];
}

