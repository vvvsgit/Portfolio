#include "DeckOfCards.hpp"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>

DeckOfCards::DeckOfCards()
{
    std::cout << std::endl;
    for (int row = 0, card = 1; row < SUIT; ++row) {
        for (int column = 0;  column < FACE; ++column, ++card) {
            deck_[row][column] = card;
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j <= HAND; ++j) {
            pokerHand1_[i][j] = 0;
            pokerHand2_[i][j] = 0;
        }
    }
    card_ = 1;
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
DeckOfCards::deal(int pokerHand[][HAND + 1])
{
    for (int i = 0; i < HAND; ++i) {
        for (int row = 0; row < SUIT; ++row) {
            for (int column = 0; column < FACE; ++column) {
                if (deck_[row][column] == card_) {
                    pokerHand[0][i] = row;
                    pokerHand[1][i] = column;
                    column = FACE;
                    row = SUIT;
                    ++card_;
                }
            }
        }
    }
    if (card_ > 25) {
        shuffle();
        card_ = 1;
    }
}

void
DeckOfCards::printHand(int pokerHand[][HAND + 1])
{
    for (int i = 0; i < HAND; ++i) {
        printCard(pokerHand[0][i], pokerHand[1][i]);
    }
    if (pokerHand[1][HAND] != 0) {
        printCombination(pokerHand[1][HAND]);
    } else {
        printHighCard(pokerHand[0][HAND]);
    }
    std::cout << std::endl;
}

void
DeckOfCards::printCard(const int row, const int column)
{
    static const char *suit[SUIT] = {"♥ ", "♦ ", "♧ ", "♤ "};
    static const char *face[FACE] = {"A", "2", "3", "4", "5", "6", "7",
                                     "8", "9", "10", "J", "Q", "K"};
    std::cout << suit[row] << face[column] << ' ';
}

void
DeckOfCards::printCombination(int combination)
{
    switch (combination) {
    case 9: std::cout << " - Royal Flush" << std::endl;     break;
    case 8: std::cout << " - Straight Flush" << std::endl;  break;
    case 7: std::cout << " - Four Of A Kind" << std::endl;  break;
    case 6: std::cout << " - Full House" << std::endl;      break;
    case 5: std::cout << " - Flush" << std::endl;           break;
    case 4: std::cout << " - Straight" << std::endl;        break;
    case 3: std::cout << " - Three Of A Kind" << std::endl; break;
    case 2: std::cout << " - Two Pairs" << std::endl;       break;
    case 1: std::cout << " - A Pair" << std::endl;          break;
    default: assert(0);                                     break;
    }
}

void
DeckOfCards::printHighCard(int high)
{
    std::cout << " - High Card ";
    switch (high) {
    case 13: std::cout << 'A' << std::endl;      break;
    case 12: std::cout << 'K' << std::endl;      break;
    case 11: std::cout << 'Q' << std::endl;      break;
    case 10: std::cout << 'J' << std::endl;      break;
    default: std::cout << high + 1 << std::endl; break;
    }
}

void
DeckOfCards::checkCombination(int pokerHand[][HAND + 1])
{
    pokerHand[0][HAND] = highCard(pokerHand);
    if (royalFlush(pokerHand)) {
        pokerHand[1][HAND] = 9;
    } else if (straightFlush(pokerHand)) {
        pokerHand[1][HAND] = 8;
    } else if (fourOfKind(pokerHand)) {
        pokerHand[1][HAND] = 7;
    } else if (fullHouse(pokerHand)) {
        pokerHand[1][HAND] = 6;
    } else if (flush(pokerHand)) {
        pokerHand[1][HAND] = 5;
    } else if (straight(pokerHand)) {
        pokerHand[1][HAND] = 4;
    } else if (threeOfKind(pokerHand)) {
        pokerHand[1][HAND] = 3;
    } else if (twoPairs(pokerHand)) {
        pokerHand[1][HAND] = 2;
    } else if (aPair(pokerHand)) {
        pokerHand[1][HAND] = 1;
    } else {
        pokerHand[1][HAND] = 0;
    }
}

bool
DeckOfCards::royalFlush(int pokerHand[][HAND + 1])
{
    if (flush(pokerHand) && straight(pokerHand)) {
        int array[HAND];
        for (int i = 0; i < HAND; ++i) {
            array[i] = pokerHand[1][i];
        }
        std::sort(array, array + HAND);
        if (array[0] == 0 && array[4] == 12) {
            return true;
        }
    }
    return false;
}

bool
DeckOfCards::straightFlush(int pokerHand[][HAND + 1])
{
    if (flush(pokerHand) && straight(pokerHand) && !royalFlush(pokerHand)) {
        return true;
    }
    return false;
}

bool
DeckOfCards::fourOfKind(int pokerHand[][HAND + 1])
{
    if (6 == getEquals(&pokerHand[1][0])) {
        return true;
    }
    return false;
}

bool
DeckOfCards::fullHouse(int pokerHand[][HAND + 1])
{
    if (4 == getEquals(&pokerHand[1][0])) {
        return true;
    }
    return false;
}

bool
DeckOfCards::flush(int pokerHand[][HAND + 1])
{
    if (10 == getEquals(&pokerHand[0][0])) {
        return true;
    }
    return false;
}

bool
DeckOfCards::straight(int pokerHand[][HAND + 1])
{
    int array[HAND];
    for (int i = 0; i < HAND; ++i) {
        array[i] = pokerHand[1][i];
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
DeckOfCards::threeOfKind(int pokerHand[][HAND + 1])
{
    if (3 == getEquals(&pokerHand[1][0])) {
        return true;
    }
    return false;
}

bool
DeckOfCards::twoPairs(int pokerHand[][HAND + 1])
{
    if (2 == getEquals(&pokerHand[1][0])) {
        return true;
    }
    return false;
}

bool
DeckOfCards::aPair(int pokerHand[][HAND + 1])
{
    if (1 == getEquals(&pokerHand[1][0])) {
        return true;
    }
    return false;
}

int
DeckOfCards::highCard(int pokerHand[][HAND + 1])
{
    int array[HAND];
    for (int i = 0; i < HAND; ++i) {
        array[i] = pokerHand[1][i];
    }
    std::sort(array, array + HAND);
    if (array[0] == 0) {
        return 13;
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

void
DeckOfCards::determineWinner()
{
    if (pokerHand1_[1][HAND] > pokerHand2_[1][HAND]) {
        std::cout << "First hand wins." << std::endl;
    } else if (pokerHand1_[1][HAND] < pokerHand2_[1][HAND]) {
        std::cout << "Second hand wins." << std::endl;
    } else if (pokerHand1_[0][HAND] > pokerHand2_[0][HAND]) {
        std::cout << "First hand wins." << std::endl;
    } else if (pokerHand1_[0][HAND] < pokerHand2_[0][HAND]) {
        std::cout << "Second hand wins." << std::endl;
    } else {
        std::cout << "it is a draw." << std::endl;
    }
    std::cout << std::endl;
}

