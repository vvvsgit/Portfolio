#include "headers/BubbleSort.hpp"

#include <gtest/gtest.h>

TEST(ClassName, TestName)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    std::vector<int> toSort;
    bubbleSort(toSort);
    toSort.push_back(2);
    toSort.push_back(1);
    toSort.push_back(5);
    toSort.push_back(28);
    toSort.push_back(8);
    toSort.push_back(6);
    toSort.push_back(2);
    print(toSort);

    bubbleSort(toSort);
    print(toSort);

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "2 1 5 28 8 6 2 \n1 2 2 5 6 8 28 \n");
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

