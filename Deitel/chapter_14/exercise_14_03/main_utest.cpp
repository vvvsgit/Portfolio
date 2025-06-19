#include "headers/sort.hpp"

#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>

TEST(TemplateSort, Int)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    const int arraySize = 10;
    int array[arraySize] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };

    std::cout << "Data items in original order\n";
    for (int i = 0; i < arraySize; ++i) {
        std::cout << std::setw(4) << array[i];
    }

    selectionSort(array, arraySize);

    std::cout << "\nData items in ascending order\n";
    for (int j = 0; j < arraySize; ++j) {
        std::cout << std::setw(4) << array[j];
    }
    std::cout << std::endl;

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "Data items in original order\n   2   6   4   8  10  12  89  68  45  37\nData items in ascending order\n   2   4   6   8  10  12  37  45  68  89\n");
}

TEST(TemplateSort, Float)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    const int arraySize = 10;
    float array[arraySize] = { 2.3, 6.45, 4.23, 8.56, 10.1, 12.0, 89.54, 68.02, 45.11, 37.99 };

    std::cout << "Data items in original order\n";
    for (int i = 0; i < arraySize; ++i) {
        std::cout << std::setw(6) << array[i];
    }

    selectionSort(array, arraySize);

    std::cout << "\nData items in ascending order\n";
    for (int j = 0; j < arraySize; ++j) {
        std::cout << std::setw(6) << array[j];
    }
    std::cout << std::endl;

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "Data items in original order\n   2.3  6.45  4.23  8.56  10.1    12 89.54 68.02 45.11 37.99\nData items in ascending order\n   2.3  4.23  6.45  8.56  10.1    12 37.99 45.11 68.02 89.54\n");
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

