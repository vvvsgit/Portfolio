#include <iostream>

int tripleByValue(int);
void tripleByReference(int&);

int
main()
{

    int count = 5;
    std::cout << "\nInitial value = " << count << std::endl;
    count = tripleByValue(count);
    std::cout << "\nBy value = " << count << std::endl;
    std::cout << "Value after is " << count << std::endl;
    tripleByReference(count);
    std::cout << "\nBy reference = " << count << std::endl;
    std::cout << "Value after is " << count << std::endl;
    std::cout << std::endl;
    return 0;
}

int
tripleByValue(int c)
{
    return c * c * c;
}

void
tripleByReference(int& c)
{
    c = c * c * c;
}

