#include "headers/Rectangle.hpp"
#include "headers/Point.hpp"

#include <iostream>

int
main()
{
    std::cout << std::boolalpha << std::endl;

    Point a(8.0, 9.0);
    Point b(6.0, 11.0);
    Point c(11.0, 12.0);
    Point d(9.0, 14.0);

    Rectangle my(a, b, c, d);

    std::cout << "Length is " << my.length() << std::endl;
    std::cout << "Width is " << my.width() << std::endl;
    std::cout << "Perimeter is " << my.perimeter() << std::endl;
    std::cout << "Area is " << my.area() << std::endl;
    std::cout << "Is square? " << my.isSquare() << std::endl;
    std::cout << std::endl;
    
    Point a2(6.0, 7.0);
    Point b2(8.0, 5.0);
    Point c2(3.0, 4.0);
    Point d2(5.0, 2.0);

    Rectangle my2(a2, b2, c2, d2);

    std::cout << "Length is " << my2.length() << std::endl;
    std::cout << "Width is " << my2.width() << std::endl;
    std::cout << "Perimeter is " << my2.perimeter() << std::endl;
    std::cout << "Area is " << my2.area() << std::endl;
    std::cout << "Is square? " << my2.isSquare() << std::endl;
    std::cout << std::endl;
    
    Point a3(5.0, 6.0);
    Point b3(7.0, 4.0);
    Point c3(3.0, 4.0);
    Point d3(5.0, 2.0);

    Rectangle my3(a3, b3, c3, d3);

    std::cout << "Length is " << my3.length() << std::endl;
    std::cout << "Width is " << my3.width() << std::endl;
    std::cout << "Perimeter is " << my3.perimeter() << std::endl;
    std::cout << "Area is " << my3.area() << std::endl;
    std::cout << "Is square? " << my3.isSquare() << std::endl;
    std::cout << std::endl;

    Point a4(0.0, 0.0);
    Point b4(20.0, 0.0);
    Point c4(20.0, 20.0);
    Point d4(0.0, 20.0);

    Rectangle my4(a4, b4, c4, d4);

    std::cout << "Length is " << my4.length() << std::endl;
    std::cout << "Width is " << my4.width() << std::endl;
    std::cout << "Perimeter is " << my4.perimeter() << std::endl;
    std::cout << "Area is " << my4.area() << std::endl;
    std::cout << "Is square? " << my4.isSquare() << std::endl;
    std::cout << std::endl;

    std::cout << std::noboolalpha << std::endl;
    
    my.draw();
    my2.draw();
    my3.draw();
    my4.draw();

    return 0;
}

