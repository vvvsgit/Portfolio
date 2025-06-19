#include "headers/QuickSort.hpp"

#include <gtest/gtest.h>

TEST(QuickSort, NotBook)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    std::vector<int> toSort;
    toSort.push_back(2);
    toSort.push_back(1);
    toSort.push_back(5);
    toSort.push_back(28);
    toSort.push_back(8);
    toSort.push_back(6);
    toSort.push_back(2);
    print(toSort);

    quickSort(toSort);
    print(toSort);

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "2 1 5 28 8 6 2 \n1 2 2 5 6 8 28 \n");
}

TEST(QuickSort, Book)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    std::vector<int> toSort;
    toSort.push_back(37);
    toSort.push_back(2);
    toSort.push_back(6);
    toSort.push_back(4);
    toSort.push_back(89);
    toSort.push_back(8);
    toSort.push_back(10);
    toSort.push_back(12);
    toSort.push_back(68);
    toSort.push_back(45);
    print(toSort);

    quickSort(toSort);
    print(toSort);

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "37 2 6 4 89 8 10 12 68 45 \n2 4 6 8 10 12 37 45 68 89 \n");
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

