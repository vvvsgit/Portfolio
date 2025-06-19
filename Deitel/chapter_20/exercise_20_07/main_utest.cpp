#include "headers/BucketSort.hpp"

#include <gtest/gtest.h>

TEST(ClassName, TestName)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    std::vector<int> toSort;
    toSort.push_back(3342);
    toSort.push_back(0);
    toSort.push_back(55);
    toSort.push_back(28);
    toSort.push_back(348);
    toSort.push_back(54546);
    toSort.push_back(2);
    print(toSort);

    bucketSort(toSort);
    print(toSort);

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "3342 0 55 28 348 54546 2 \n0 2 28 55 348 3342 54546 \n");
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

