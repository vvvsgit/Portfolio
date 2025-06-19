#include <iostream>

int
main()
{
    int x = 1, y = 1;
    std::cout << (!(x < 5) && !(y >= 7)) << " = " << !(x < 5 || y >= 7) << std::endl;
    int a = 1, b = 1, g = 1;
    std::cout << (!(a == b) || !(g != 5)) << " = " << !(a == b && g != 5) << std::endl;
    std::cout << !(x <= 8 && y > 4) << " = " << (!(x <= 8) || !(y > 4)) << std::endl;
    int i = 1, j = 1;
    std::cout << !(i > 4 || j <= 6) << " = " << (!(i > 4) && !(j <= 6)) << std::endl;
    return 0;
}

