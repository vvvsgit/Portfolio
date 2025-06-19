#include <iostream>

int
main()
{
    std::cout << "\nA = " << static_cast<int>('A') << std::endl;
    std::cout << "a = " << static_cast<int>('a') << std::endl;
    std::cout << "r = " << static_cast<int>('r') << std::endl;
    std::cout << "  = " << static_cast<int>(' ') << std::endl;
    std::cout << "\\n = " << static_cast<int>('\n') << std::endl;
    std::cout << "; = " << static_cast<int>(';') << std::endl;
    std::cout << "/ = " << static_cast<int>('/') << std::endl;
    std::cout << "= = " << static_cast<int>('=') << std::endl;
    std::cout << "\\t = " << static_cast<int>('\t') << std::endl;
    std::cout << "5 = " << static_cast<int>('5') << std::endl;
    std::cout << "0 = " << static_cast<int>('0') << std::endl;

    return 0;
}

