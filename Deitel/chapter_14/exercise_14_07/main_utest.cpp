#include "headers/Array.hpp"

#include <gtest/gtest.h>

TEST(Array, DefaultConstructor)
{
    Array<> one;
    EXPECT_EQ(one.getSize(), 10);
    for (size_t i = 0; i < one.getSize(); ++i) {
        EXPECT_EQ(one[i], 0);
    }
}

TEST(IntArray, Constructor)
{
    Array<int, 3> one;
    EXPECT_EQ(one.getSize(), 3);
    one[0] = 1;
    one[1] = 2;
    one[2] = 3;
    for (size_t i = 0; i < one.getSize(); ++i) {
        EXPECT_EQ(one[i], i + 1);
    }
}

TEST(CharArray, Constructor)
{
    Array<char, 3> one;
    EXPECT_EQ(one.getSize(), 3);
    one[0] = '1';
    one[1] = '2';
    one[2] = '3';
    for (size_t i = 0; i < one.getSize(); ++i) {
        EXPECT_EQ(one[i], '0' + i + 1);
    }
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

