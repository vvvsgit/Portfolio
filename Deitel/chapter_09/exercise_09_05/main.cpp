#include "headers/Complex.hpp"

#include <iostream>

int
main()
{
    std::cout << std::endl;
    
    Complex my1;
    Complex my2;
    Complex my3;

    my1.print();
    my2.print();
    my3.print();

    my3 = my1.adding(my2);
    my3.print();

    my3 = my1.subtracting(my2);
    my3.print();

    std::cout << std::endl;

    return 0;
}

