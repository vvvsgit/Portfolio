#include <iostream>
#include <cassert>

void economyClass(bool [], const int);
void firstClass(bool [], const int);

int
main()
{
    std::cout << std::endl;

    const int seats = 10;
    bool chart[seats] = {false};
    for (int i = 0; i < seats; ++i) {
        std::cout << "Please type 1 for first class and 2 for economy class: ";
        int classType;
        std::cin >> classType;
        if (classType != 1 && classType != 2) {
            std::cerr << "\nError 1: No such class." << std::endl;
            return 1;
        }
        if (classType == 1) {
            economyClass(chart, seats);
        } else {
            firstClass(chart, seats);
        }
    }

    std::cout << std::endl;
    return 0;
}

void
economyClass(bool seats[], const int size)
{
    for (static int economy = 0; economy < size / 2; ++economy) {
        if (seats[economy] == false) {
            seats[economy] = true;
            std::cout << "Your ticket is reserved in economy class seat number " << economy + 1 << std::endl;
            return;
        }
    }
    std::cout << "Economy class section is full. Do you want first class seat (y or n)? ";
    char yesOrNo;
    std::cin >> yesOrNo;
    switch (yesOrNo) {
    case 'y': case 'Y': firstClass(seats, size);                                    break;
    case 'n': case 'N': std::cout << "Next flight leaves in 3 hours." << std::endl; break;
    default: std::cout << "You shouldn't have seen this." << std::endl; assert(0);  break;
    }
}

void
firstClass(bool seats[], const int size)
{
    for (static int first = size / 2; first < size; ++first) {
        if (seats[first] == false) {
            seats[first] = true;
            std::cout << "Your ticket is reserved in first class seat number " << first + 1 << std::endl;
            return;
        }
    }
    std::cout << "First class section is full. Do you want economy class seat (y or n)? ";
    char yesOrNo;
    std::cin >> yesOrNo;
    switch (yesOrNo) {
    case 'y': case 'Y': economyClass(seats, size);                                  break;
    case 'n': case 'N': std::cout << "Next flight leaves in 3 hours." << std::endl; break;
    default: std::cout << "You shouldn't have seen this." << std::endl; assert(0);  break;
    }
}

