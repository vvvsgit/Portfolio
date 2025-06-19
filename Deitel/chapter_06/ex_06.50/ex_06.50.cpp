#include <iostream>

int mystery(int, int);

int
main()
{
    int x, y;
    std::cout << "Enter two integers: ";
    std::cin >> x >> y;
    std::cout << "The result is " << mystery(x, y) << std::endl;
    return 0;
}

int
mystery(int a, int b)
{
    if (b == 1) {
        return a;
    } else {
       return a + mystery(a, b - 1);
    }
}

