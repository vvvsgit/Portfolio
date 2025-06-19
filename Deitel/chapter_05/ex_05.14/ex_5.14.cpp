#include <iostream>

int
main()
{
    double total = 0;
    int product1 = 0, product2 = 0, product3 = 0, product4 = 0, product5 = 0;
    std::cout << "\nEnter product number (0 to end): ";
    int number;
    std::cin >> number;
    if (number < 0 || number > 5) {
        std::cerr << "\nError 1: Wrong." << std::endl;
        return 1;
    }

    while (number != 0) {
        std::cout << "Enter sold quantity: ";
        int quantity;
        std::cin >> quantity;
        if (quantity < 0) {
            std::cerr << "\nError 1: Wrong." << std::endl;
            return 1;
        }
        
        switch (number) {
        case 1: total += 2.98 * quantity; break;
        case 2: total += 4.50 * quantity; break;
        case 3: total += 9.98 * quantity; break;
        case 4: total += 4.49 * quantity; break;
        case 5: total += 6.87 * quantity; break;
        default: return 1;            break;
        }
        std::cout << "\nEnter product number (0 to end): ";
        std::cin >> number;
        if (number < 0 || number > 5) {
            std::cerr << "\nError 1: Wrong." << std::endl;
            return 1;
        }
    }

    //std::cout << "\nTotal solds is $" << product1 * 2.98 + product2 * 4.50 + product3 * 9.98 + product4 * 4.49 + product5 * 6.87 << std::endl;
    std::cout << "\nTotal solds is $" << total << std::endl;

    return 0;
}

