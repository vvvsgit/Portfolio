#include "DeckOfCards.hpp"
#include <iostream>

int
main()
{
    DeckOfCards deckOfCards;

    int shuffleTimes = 10;
    for (int i = 0; i < shuffleTimes; ++i) {
        deckOfCards.shuffle();
    }

    deckOfCards.deal(deckOfCards.pokerHand1_);
    deckOfCards.deal(deckOfCards.pokerHand2_);

    deckOfCards.checkCombination(deckOfCards.pokerHand1_);
    deckOfCards.checkCombination(deckOfCards.pokerHand2_);

    deckOfCards.printHand(deckOfCards.pokerHand1_);
    deckOfCards.printHand(deckOfCards.pokerHand2_);

    deckOfCards.determineWinner();

    return 0;
}

