#include "headers/LinearSearch.hpp"

#include <gtest/gtest.h>

TEST(ClassName, TestName)
{
    std::vector<int> toSort;
    toSort.push_back(2);
    toSort.push_back(1);
    toSort.push_back(5);
    toSort.push_back(28);
    toSort.push_back(8);
    toSort.push_back(6);

    EXPECT_EQ(linearSearch(toSort, 1), 1);
    EXPECT_EQ(linearSearch(toSort, 2), 0);
    EXPECT_EQ(linearSearch(toSort, 5), 2);
    EXPECT_EQ(linearSearch(toSort, 6), 5);
    EXPECT_EQ(linearSearch(toSort, 8), 4);
    EXPECT_EQ(linearSearch(toSort, 28), 3);

    EXPECT_EQ(linearSearch(toSort, -1), -1);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

