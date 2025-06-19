#include <iostream>

int
main()
{
    std::cout << std::endl;

    //a.
    const int SIZE = 5;
    unsigned int values[SIZE] {2, 4, 6, 8, 10};
    //b.
    unsigned int* vPtr;
    //c.
    for (int i = 0; i < SIZE; ++i) {
        std::cout << values[i] << ' ';
    }
    std::cout << std::endl;
    //d.
    vPtr = values;
    vPtr = &values[0];
    //e.
    for (int i = 0; i < SIZE; ++i) {
        std::cout << *(vPtr + i) << ' ';
    }
    std::cout << std::endl;
    //f.
    for (int i = 0; i < SIZE; ++i) {
        std::cout << *(values + i) << ' ';
    }
    std::cout << std::endl;
    //g.
    for (int i = 0; i < SIZE; ++i) {
        std::cout << vPtr[i] << ' ';
    }
    std::cout << std::endl;
    //h.
    std::cout << values[4] << ' ' << *(values + 4) << ' ' << *(vPtr + 4) << ' ' << vPtr[4] << std::endl;
    //i.
    std::cout << vPtr + 3 << " - " << vPtr[3] << std::endl;
    //j.
    vPtr = &values[4];
    std::cout << *(vPtr - 4) << std::endl;
    
    std::cout << std::endl;
    return 0;
}

