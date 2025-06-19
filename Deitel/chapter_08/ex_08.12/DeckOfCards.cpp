#include "DeckOfCards.hpp"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>

DeckOfCards::DeckOfCards()
{
    for (int row = 0, card = 1; row < SUIT; ++row) {
        for (int column = 0;  column < FACE; ++column, ++card) {
            deck_[row][column] = card;
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 5; ++j) {
            pokerHand_[i][j] = 0;
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
    std::cout << std::endl;
    for (int card = 1; card <= 5; ++card) {
        for (int row = 0; row < SUIT; ++row) {
            for (int column = 0; column < FACE; ++column) {
                if (deck_[row][column] == card) {
                    pokerHand_[0][card - 1] = row;
                    pokerHand_[1][card - 1] = column;
                    column = FACE;
                    row = SUIT;
                }
            }
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void
DeckOfCards::printHand()
{
    for (int i = 0; i < HAND; ++ i) {
        printCard(pokerHand_[0][i], pokerHand_[1][i]);
    }
}

void
DeckOfCards::printCard(const int row, const int column)
{
    static const char *suit[SUIT] = {"♥ ", "♦ ", "♧ ", "♤ "};
    static const char *face[FACE] = {"A", "2", "3", "4", "5", "6", "7",
                                     "8", "9", "10", "J", "Q", "K"};
    std::cout << face[column] << suit[row] << ' ';
}

void
DeckOfCards::checkCombination()
{
    if (royalFlush()) {
        std::cout << " - Royal Flush" << std::endl;
    } else if (straightFlush()) {
        std::cout << " - Straight Flush" << std::endl;
    } else if (fourOfKind()) {
        std::cout << " - Four Of A Kind" << std::endl;
    } else if (fullHouse()) {
        std::cout << " - Full House" << std::endl;
    } else if (flush()) {
        std::cout << " - Flush" << std::endl;
    } else if (straight()) {
        std::cout << " - Straight" << std::endl;
    } else if (threeOfKind()) {
        std::cout << " - Three Of A Kind" << std::endl;
    } else if (twoPairs()) {
        std::cout << " - Two Pairs" << std::endl;
    } else if (aPair()) {
        std::cout << " - A Pair" << std::endl;
    } else {
        std::cout << " - High Card ";
        int high = highCard();
        switch (high) {
        case 0:  std::cout << 'A' << std::endl;      break;
        case 12: std::cout << 'K' << std::endl;      break;
        case 11: std::cout << 'Q' << std::endl;      break;
        case 10: std::cout << 'J' << std::endl;      break;
        default: std::cout << high + 1 << std::endl; break;
        }
    }
}

bool
DeckOfCards::royalFlush()
{
    if (flush() && straight()) {
        int array[HAND];
        for (int i = 0; i < HAND; ++i) {
            array[i] = pokerHand_[1][i];
        }
        std::sort(array, array + HAND);
        if (array[0] == 0 && array[4] == 12) {
            return true;
        }
    }
    return false;
}

bool
DeckOfCards::straightFlush()
{
    if (flush() && straight() && !royalFlush()) {
        return true;
    }
    return false;
}

bool
DeckOfCards::fourOfKind()
{
    if (6 == getEquals(&pokerHand_[1][0])) {
        return true;
    }
    return false;
}

bool
DeckOfCards::fullHouse()
{
    if (4 == getEquals(&pokerHand_[1][0])) {
        return true;
    }
    return false;
}

bool
DeckOfCards::flush()
{
    if (10 == getEquals(&pokerHand_[0][0])) {
        return true;
    }
    return false;
}

bool
DeckOfCards::straight()
{
    int array[HAND];
    for (int i = 0; i < HAND; ++i) {
        array[i] = pokerHand_[1][i];
    }
    std::sort(array, array + HAND);
    if (array[0] == 0 && array[1] == 9) {
        array[0] = 8;
    }
    for (int i = 1; i < HAND; ++i) {
        if (array[i] - array[i - 1] != 1) {
            return false;
        }
    }
    return true;
}

bool
DeckOfCards::threeOfKind()
{
    if (3 == getEquals(&pokerHand_[1][0])) {
        return true;
    }
    return false;
}

bool
DeckOfCards::twoPairs()
{
    if (2 == getEquals(&pokerHand_[1][0])) {
        return true;
    }
    return false;
}

bool
DeckOfCards::aPair()
{
    if (1 == getEquals(&pokerHand_[1][0])) {
        return true;
    }
    return false;
}

int
DeckOfCards::highCard()
{
    int array[HAND];
    for (int i = 0; i < HAND; ++i) {
        array[i] = pokerHand_[1][i];
    }
    std::sort(array, array + HAND);
    if (array[0] == 0) {
        return 0;
    }
    return array[4];
}

int
DeckOfCards::getEquals(int *array)
{
    int equals = 0;
    for (int i = 0; i < HAND - 1; ++i) {
        for (int j = i + 1; j < HAND; ++j) {
            if (array[i] == array[j]) {
                ++equals;
            }
        }
    }
    return equals;
}

