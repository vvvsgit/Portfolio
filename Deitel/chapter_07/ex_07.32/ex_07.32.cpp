#include <iostream>

bool testPalindrome(char [], const int, const int = 0);
int getChars(char []);

int
main()
{
    std::cout << std::endl;

    const int LENGTH = 28;
    char string[LENGTH];
    std::cout << "Enter a string to check for palindrome(max " << LENGTH - 1 
              << ", if it will be more it will be shorten without telling you about): ";
    std::cin.getline(string, LENGTH);
    int chars = getChars(string) - 1;
    std::cout << "The string " << (testPalindrome(string, chars) ? "is" : "isn't") << " a palindrome" << std::endl;

    std::cout << std::endl;
    return 0;
}

int
getChars(char array[])
{
    int i;
    for (i = 0; array[i] != '\0'; ++i);
    return i;
}

bool
testPalindrome(char string[], const int length, const int first)
{
    if (first >= length) { return true; }
    int i;
    for (i = first; i <= length; ++i) {
        if (string[i] != ' ') { break; }
    }
    int j;
    for (j = length; j >= first; --j) {
        if (string[j] != ' ') { break; }
    }
    if (string[i] != string[j]) {
        return false;
    }
    return testPalindrome(string, j - 1, i + 1);
}

