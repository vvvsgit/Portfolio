#include "headers/BinarySearch.hpp"

#include <gtest/gtest.h>

TEST(ClassName, TestName)
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    v.push_back(6);
    v.push_back(8);
    v.push_back(28);

    EXPECT_EQ(binarySearch(v, 1, 0, v.size()), 0);
    EXPECT_EQ(binarySearch(v, 2, 0, v.size()), 1);
    EXPECT_EQ(binarySearch(v, 5, 0, v.size()), 2);
    EXPECT_EQ(binarySearch(v, 6, 0, v.size()), 3);
    EXPECT_EQ(binarySearch(v, 8, 0, v.size()), 4);
    EXPECT_EQ(binarySearch(v, 28, 0, v.size()), 5);
    EXPECT_EQ(binarySearch(v, 29, 0, v.size()), -1);
    EXPECT_EQ(binarySearch(v, -1, 0, v.size()), -1);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

