#include "headers/SortedArray.hpp"

#include <gtest/gtest.h>
#include <iostream>

TEST(SortedArray, Constructor)
{
    SortedArray array;
    for (int i = 1; i <= array.getSize(); ++i) { 
        EXPECT_EQ(array(i), 0);
    }
}

TEST(SortedArray, SubscriptOperator)
{
    SortedArray array(0);
    array.insert(3);
    array.insert(19);
    array.insert(-13);
    EXPECT_EQ(array(1), -13);
    EXPECT_EQ(array(2), 3);
    EXPECT_EQ(array(3), 19);
}

TEST(SortedArray, Predicates)
{
    SortedArray array1;
    SortedArray array2;
    EXPECT_TRUE(array1 == array2);
    EXPECT_FALSE(array1 != array2);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

