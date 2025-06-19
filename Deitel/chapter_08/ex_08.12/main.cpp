#include "DeckOfCards.hpp"

int
main()
{
    DeckOfCards deckOfCards;

    int shuffleTimes = 10;
    for (int i = 0; i < shuffleTimes; ++i) {
        deckOfCards.shuffle();
    }
    deckOfCards.deal();
    deckOfCards.printHand();
    deckOfCards.checkCombination();
    return 0;
}

