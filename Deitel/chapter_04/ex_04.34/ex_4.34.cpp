#include <iostream>

int
main()
{
    std::cout << "\nEnter positive four digit integer: ";
    int integer;
    std::cin >> integer;
    if (integer < 1000) {
        std::cerr << "\nError 1: not fout digit." << std::endl;
        return 1;
    }
    if (integer > 9999) {
        std::cerr << "\nError 1: not fout digit." << std::endl;
        return 1;
    }
    //std::cout <<  ((integer / 1000 + 7) % 10) * 10 << std::endl; 
    //std::cout <<  ((integer / 100 % 10 + 7) % 10) * 1 << std::endl; 
    //std::cout <<  ((integer / 10 % 10 + 7) % 10) * 1000 << std::endl; 
    //std::cout <<  ((integer % 10 + 7) % 10) * 100 << std::endl;
    int encrypt = ((integer / 1000 + 7) % 10) * 10 + 
                  ((integer / 100 % 10 + 7) % 10) * 1 + 
                  ((integer / 10 % 10 + 7) % 10) * 1000 + 
                  ((integer % 10 + 7) % 10) * 100;
    std::cout << "\nEncrypted integer is " << encrypt << std::endl;

    std::cout << "\nEnter encrypted code: ";
    std::cin >> integer;
    if (integer < 0) {
        std::cerr << "\nError 2: Wrong code." << std::endl;
        return 2;
    }
    if (integer > 9999) {
        std::cerr << "\nError 2: Wrong code." << std::endl;
        return 2;
    }
    int decrypt = ((integer / 1000 + 3) % 10) * 10 +
                  ((integer / 100 % 10 + 3) % 10) * 1 +
                  ((integer / 10 % 10 + 3) % 10) * 1000 +
                  ((integer % 10 + 3) % 10) * 100;
    std::cout << "\nDecrypted integer is " << decrypt << std::endl;
    return 0;
}

