#include "headers/DoubleSubscriptedArray.hpp"

#include <gtest/gtest.h>
#include <iostream>

TEST(DoubleSubscriptedArray, DefaultConstructor)
{
    DoubleSubscriptedArray array;
    EXPECT_EQ(array.getSize(), 1);
    EXPECT_EQ(array.getRow(), 1);
    EXPECT_EQ(array.getColumn(), 1);
}

TEST(DoubleSubscriptedArray, ValueConstructor)
{
    DoubleSubscriptedArray array(3, 5);
    EXPECT_EQ(array.getSize(), 15);
    EXPECT_EQ(array.getRow(), 3);
    EXPECT_EQ(array.getColumn(), 5);
}

TEST(DoubleSubscriptedArray, CopyConstructor)
{
    DoubleSubscriptedArray array1(3, 5);
    DoubleSubscriptedArray array2(array1);
    DoubleSubscriptedArray array3;

    EXPECT_TRUE(array1 == array2);
    EXPECT_FALSE(array1 == array3);
    EXPECT_TRUE(array1 != array3);
    EXPECT_FALSE(array1 != array2);
}

TEST(DoubleSubscriptedArray, SubscriptOperator)
{
    DoubleSubscriptedArray array(3, 5);
    EXPECT_EQ(array(0, 0), 0);
    array(0, 0) = 1;
    EXPECT_EQ(array(0, 0), 1);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

