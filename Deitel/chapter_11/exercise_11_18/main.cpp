#include "headers/PhoneNumber.hpp"

#include <iostream>

int
main()
{
    PhoneNumber phone;

    std::cout << "Enter phone number in the form (123) 456-7890:" << std::endl;
    std::cin >> phone;
    std::cout << "The phone number entered was: ";
    std::cout << phone << std::endl;

    /// operator>>(std::cin, phone);
    /// operator<<(std::cout, phone); std::cout << std::endl;

    /// phone >> std::cin;
    /// phone << std::cout << std::endl;

    /// phone.operator>>(std::cin);
    /// phone.operator<<(std::cout); std::cout << std::endl;

    return 0;
}

