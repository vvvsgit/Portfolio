#include "DeckOfCards.hpp"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

DeckOfCards::DeckOfCards()
{
    for (int row = 0, card = 1; row < SUIT; ++row) {
        for (int column = 0;  column < FACE; ++column, ++card) {
            deck_[row][column] = card;
        }
    }
    std::srand(std::time(0));
}

void
DeckOfCards::shuffle()
{
    for (int row = 0; row < SUIT; ++row) {
        for (int column = 0; column < FACE; ++column) {
            int newRow = rand() % SUIT;
            int newColumn = rand() % FACE;
            std::swap(deck_[row][column], deck_[newRow][newColumn]);
        }
    }
}

void
DeckOfCards::deal()
{
    for (int card = 1; card <= CARDS; ++card) {
        for (int row = 0; row < SUIT; ++row) {
            for (int column = 0; column < FACE; ++column) {
                if (deck_[row][column] == card) {
                    printCard(row, column);
                    std::cout << (card % 2 == 0 ? '\n' : '\t');
                    column = FACE;
                    row = SUIT;
                }
            }
        }
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

