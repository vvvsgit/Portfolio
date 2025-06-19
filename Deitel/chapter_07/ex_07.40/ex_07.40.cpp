#include <iostream>
#include <vector>

int recursiveMinimum(std::vector<int>, const int = 0, int = 2147483647);

int
main()
{
    std::cout << std::endl;

    const int SIZE = 10;
    std::vector<int> array(SIZE);
    std::cout << "Enter " << array.size() << " numbers to find the smallest: ";
    for (int i = 0; i < array.size(); ++i) {
        std::cin >> array[i];
    }
    std::cout << "The smallest is " << recursiveMinimum(array) << std::endl;

    std::cout << std::endl;
    return 0;
}

int
recursiveMinimum(std::vector<int> array, const int first, int smallest)
{
    if (array.size() == first) {
        return smallest;
    }
    if (smallest > array[first]) {
        smallest = array[first];
    }
    return recursiveMinimum(array, first + 1, smallest);
}

