#include "DeckOfCards.hpp"

int
main()
{
    DeckOfCards deckOfCards;

    deckOfCards.shuffle();
    deckOfCards.shuffle();
    deckOfCards.shuffle();
    deckOfCards.shuffle();

    deckOfCards.deal();
    return 0;
}

