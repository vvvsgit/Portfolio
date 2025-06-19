#include <iostream>

int
main()
{
    int n = 0;
    std::cout << "\nN\t10*N\t100*N\t1000*N\n" << std::endl;
    while (n < 100) {
        ++n;
        std::cout << n << '\t' << n * 10 << '\t' << n * 100 << '\t' << n * 1000 << std::endl;
    }
    return 0;
}
