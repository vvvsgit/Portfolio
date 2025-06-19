#include <iostream>
#include <iomanip>

int
main()
{
    std::cout << "\nDecimal" << std::setw(8) << "Binary" << std::setw(7) << "Octal" << std::setw(13) << "Hexadecimal" << std::endl;
    for (int i = 0; i <= 256; ++i) {
        std::cout << std::setw(4) << i;

        int decimal = i;
        int binary = 0;
        for (int j = 1; decimal / 1 != 0; j *= 10) {
            binary += decimal % 2 * j;
            decimal /= 2;
        }
        std::cout << std::setw(10) << binary;

        decimal = i;
        int octal = 0;
        for (int j = 1; decimal / 1 != 0; j *= 10) {
            octal += decimal % 8 * j;
            decimal /= 8;
        }
        std::cout << std::setw(6) << octal;

        decimal = i;
        std::string hexadecimal;
        for (int j = 0; j < 2; ++j) {
            if (256 == decimal) {std::cout << std::setw(10) << "100"; break;}
            switch (decimal / 16) {
            case 10: hexadecimal += 'A'; break;
            case 11: hexadecimal += 'B'; break;
            case 12: hexadecimal += 'C'; break;
            case 13: hexadecimal += 'D'; break;
            case 14: hexadecimal += 'E'; break;
            case 15: hexadecimal += 'F'; break;
            default: hexadecimal += static_cast<char>(48 + decimal / 16); break;
            }
            decimal = decimal % 16 * 16;
        }
        std::cout << std::setw(10) << hexadecimal;

        std::cout << std::endl;
    }
    return 0;
}

