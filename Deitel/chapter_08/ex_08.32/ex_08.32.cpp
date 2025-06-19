#include <iostream>

int getRandomNumber(const int);
int strlen(const char *);
void strcat(char *, const char *);

int
main()
{
    std::cout << std::endl;

    std::srand(time(0));
    const int SIZE = 5;
    static const char *article[SIZE] = {"the", "a", "one", "some", "any"};
    static const char *noun[SIZE] = {"boy", "girl", "dog", "town", "car"};
    static const char *verb[SIZE] = {"drove", "jumped", "ran", "walked", "skipped"};
    static const char *preposition[SIZE] = {"to", "from", "over", "under", "on"};

    int sentenceQuantity = 20;
    for (int i = 0; i < sentenceQuantity; ++i) {
        const int sentenceLength = 36;
        char sentence[sentenceLength];
        int firstWordsNumber = getRandomNumber(SIZE);
        int firstWordsLength = strlen(article[firstWordsNumber]);
        for (int i = 0; i <= firstWordsLength; ++i) {
            sentence[i] = *(article[firstWordsNumber] + i);
        }
        sentence[0] -= 32;
        strcat(sentence, noun[getRandomNumber(SIZE)]);
        strcat(sentence, verb[getRandomNumber(SIZE)]);
        strcat(sentence, preposition[getRandomNumber(SIZE)]);
        strcat(sentence, article[getRandomNumber(SIZE)]);
        strcat(sentence, noun[getRandomNumber(SIZE)]);
        int length = strlen(sentence);
        sentence[length] = '.';
        sentence[length + 1] = '\0';

        std::cout << sentence << std::endl;
    }

    std::cout << std::endl;
    return 0;
}

int
getRandomNumber(const int size)
{
    return std::rand() % size;
}

int
strlen(const char *string)
{
    int i;
    for (i = 0; *(string + i) != '\0'; ++i);
    return i;
}

void
strcat(char *sentence, const char *string)
{
    int i = strlen(sentence);
    *(sentence + i) = ' ';
    for (++i; *string != '\0'; ++string, ++i) {
        *(sentence + i) = *string;
    }
    *(sentence + i) = *string;
}

