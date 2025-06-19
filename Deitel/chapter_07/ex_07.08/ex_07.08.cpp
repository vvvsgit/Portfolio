#include <iostream>

int
main()
{
    std::cout << std::endl;

    { //a.
        char f[7];
        std::cout << f[6] << std::endl;
    }

    { //b.
        float b[5];
        b[4] = 3.14159;
    }

    { //c.
        int g[5] = {8, 8, 8, 8, 8};
    }

    { //d.
        float c[100];
        float totalC = 0;
        for (int i = 0; i < 100; ++i) {
            totalC += c[i];
        }
        std::cout << "C's total is " << totalC << std::endl;
    }

    { //e.
        double a[11], b[34];
        for (int i = 0; i < 11; ++i) {
            b[i] = a[i];
        }
    }
    
    { //f.
        float w[99];
        float min = w[0];
        float max = w[0];
        for (int i = 1; i < 99; ++i) {
            if (w[i] < min) {
                min = w[i];
            }
            if (w[i] > max) {
                max = w[i];
            }
        }
        std::cout << "Max of w is " << max << "\nMin of w is " << min << std::endl;
    }

    std::cout << std::endl;
    return 0;
}

