#include <iostream>

int
main()
{
    std::cout << std::endl;
    for (int i = 0; i < 12; ++i) {
        std::cout << "On The ";
        switch (i) {
        case 0:  std::cout << "first";    break;
        case 1:  std::cout << "second";   break;
        case 2:  std::cout << "third";    break;
        case 3:  std::cout << "fourth";   break;
        case 4:  std::cout << "fifth";    break;
        case 5:  std::cout << "sixth";    break;
        case 6:  std::cout << "seventh";  break;
        case 7:  std::cout << "eight";    break;
        case 8:  std::cout << "ninth";    break;
        case 9:  std::cout << "tenth";    break;
        case 10: std::cout << "eleventh"; break;
        case 11: std::cout << "twelfth";  break;
        default: std::cout << "Error 1: EasterEgg\n"; return 1;
        }
        std::cout << " day of Christmas" << std::endl;
        std::cout << "my true love sent to me:" << std::endl;
        switch (i) {
        case 0: std::cout << "A Partridge in a Pear Tree" << std::endl; break;
        case 11: std::cout << "12 Drummers Drumming" << std::endl;
        case 10: std::cout << "Eleven Pipers Piping" << std::endl;
        case 9: std::cout << "Ten Lords a Leaping" << std::endl;
        case 8: std::cout << "Nine Ladies Dancing" << std::endl;
        case 7: std::cout << "Eight Maids a Milking" << std::endl;
        case 6: std::cout << "Seven Swans a Swimming" << std::endl;
        case 5: std::cout << "Six Geese a Laying" << std::endl;
        case 4: std::cout << "Five Golden Rings" << std::endl;
        case 3: std::cout << "Four Calling Birds" << std::endl;
        case 2: std::cout << "Three French Hens" << std::endl;
        case 1: std::cout << "Two Turtle Doves" << std::endl;
        default: std::cout << "and a Partridge in a Pear Tree" << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}

