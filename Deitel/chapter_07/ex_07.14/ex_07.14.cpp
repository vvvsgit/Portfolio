#include <iostream>

int
main()
{
    std::cout << std::endl;

    char str[5];
    std::cin >> str;

    int a[3];
    std::cout << a[0] << ' ' << a[1] << ' ' << a[2] << std::endl;

    double f[4] = {1.1, 10.01, 100.001, 1000.0001};

    double d[2][10];
    d[1][9] = 2.345;

    std::cout << std::endl;
    return 0;
}

