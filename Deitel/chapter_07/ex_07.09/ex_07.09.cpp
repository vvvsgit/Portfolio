#include <iostream>

int
main()
{
    //a.
    int t[2][3];

    //b. 2

    //c. 3

    //d. 6

    //e. [1][0], [1][1], [1][2]

    //f. [0][2], [1][2]

    //g. 
    t[1][2] = 0;

    //h. 
    t[0][0] = 0;
    t[0][1] = 0;
    t[0][2] = 0;
    t[1][0] = 0;
    t[1][1] = 0;
    t[1][2] = 0;

    //i. 
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            t[i][j] = 0;
        }
    }

    //j. 
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> t[i][j];
        }
    }

    //k. 
    int smallestT = t[0][0];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (t[i][j] < smallestT) {
                smallestT = t[i][j];
            }
        }
    }
    std::cout << "the smallest of t is " << smallestT << std::endl;

    //l. 
    for (int i = 0; i < 3; ++i) {
        std::cout << t[0][i] << ' ';
    }
    std::cout << std::endl;

    //m.
    int totalT = 0;
    for (int i = 0; i < 2; ++i) {
        totalT += t[i][3];
    }

    //n. 
    for (int i = 0; i < 3; ++i) {
        std::cout << '\t' << i + 1 << '.';
    }
    std::cout << std::endl;
    for (int i = 0; i < 2; ++i) {
        std::cout << i << '.';
        for (int j = 0; j < 3; ++j) {
            std::cout << '\t' << t[i][j];
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    return 0;
}

