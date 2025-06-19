#include <iostream>

bool even(int);

int
main()
{
    std::cout << "\nEnter integers to determine if they even or odd." << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << "Enter: ";
        int number;
        std::cin >> number;
        std::cout << (even(number) ? "true: even\n" : "false: odd\n");
    }
    std::cout << std::endl;
    return 0;
}

bool
even(int number) 
{
    return (0 == number % 2);
}

