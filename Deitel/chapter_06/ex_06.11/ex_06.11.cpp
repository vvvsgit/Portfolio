#include <iostream>
#include <cmath>

int
main()
{
    std::cout << std::endl;

    std::cout << "fabs(7.5) = " << fabs(7.5) << std::endl;
    std::cout << "floor(7.5) = " << floor(7.5) << std::endl;
    std::cout << "fabs(0.0) = " << fabs(0.0) << std::endl;
    std::cout << "ceil(0.0) = " << ceil(0.0) << std::endl;
    std::cout << "fabs(-6.4) = " << fabs(-6.4) << std::endl;
    std::cout << "ceil(-6.4) = " << ceil(-6.4) << std::endl;
    std::cout << "ceil(-fabs(-8 + floor(-5.5))) = " << ceil(-fabs(-8 + floor(-5.5))) << std::endl;

    std::cout << std::endl;
    return 0;
}

