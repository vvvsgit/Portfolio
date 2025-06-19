#include "DeckOfCards.hpp"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

DeckOfCards::DeckOfCards()
{
    for (int row = 0; row < SUIT; ++row) {
        for (int column = 0;  column < FACE; ++column) {
            deck_[row][column] = 0;
        }
    }
    std::srand(std::time(0));
}

void
DeckOfCards::shuffleAndDeal()
{
    int newRow;
    int newColumn;
    for (int card = 1; card <= CARDS; ++card) {
        do {
            newRow = rand() % SUIT;
            newColumn = rand() % FACE;
        } while (deck_[newRow][newColumn] != 0);
        deck_[newRow][newColumn] = card;
        printCard(newRow, newColumn);
        std::cout << (card % 2 == 0 ? '\n' : '\t');
    }
}

void
DeckOfCards::printCard(const int row, const int column)
{
    static const char *suit[SUIT] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    static const char *face[FACE] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven",
                                   "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    std::cout << std::setw(5) << std::right << face[column] << " of "
              << std::setw(8) << std::left << suit[row];
}

