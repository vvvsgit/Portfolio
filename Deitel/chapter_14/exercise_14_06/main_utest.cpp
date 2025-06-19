#include "headers/isEqualTo.hpp"

#include <gtest/gtest.h>

TEST(IsEqualTo, Int)
{
    const int one = 1;
    const int two = 2;
    EXPECT_FALSE(isEqualTo(one, two));
    const int otherOne = 1;
    EXPECT_TRUE(isEqualTo(one, otherOne));
}

TEST(IsEqualTo, Char)
{
    const char A = 'A';
    const char B = 'B';
    EXPECT_FALSE(isEqualTo(A, B));
    const char otherA = 'A';
    EXPECT_TRUE(isEqualTo(A, otherA));
}

TEST(IsEqualTo, Double)
{
    const double onePointOne = 1.1;
    const double twoPointTwo = 2.2;
    EXPECT_FALSE(isEqualTo(onePointOne, twoPointTwo));
    const double otherOnePointOne = 1.1;
    EXPECT_TRUE(isEqualTo(onePointOne, otherOnePointOne));
}

TEST(IsEqualTo, Object)
{
    const Class x;
    const Class y(1);
    EXPECT_FALSE(isEqualTo(x, y));
    const Class z;
    EXPECT_TRUE(isEqualTo(x, z));
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

