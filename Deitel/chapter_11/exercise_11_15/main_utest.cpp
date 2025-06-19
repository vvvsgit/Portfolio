#include "headers/Rational.hpp"

#include <gtest/gtest.h>

TEST(RationalTest, DefaultConstructorValue)
{
    Rational number;
    EXPECT_EQ(number.getNumerator(), 1);
    EXPECT_EQ(number.getDenominator(), 1);
}

TEST(RationalTest, ConstructorValue)
{
    Rational number(3, 2);
    EXPECT_EQ(number.getNumerator(), 3);
    EXPECT_EQ(number.getDenominator(), 2);
}

TEST(RationalTest, RationalAdding)
{
    Rational number1(3, 2);
    Rational number2(1, 2);
    Rational number3 = number1 + number2;

    EXPECT_EQ(number3.getNumerator(), 2);
    EXPECT_EQ(number3.getDenominator(), 1);
}

TEST(RationalTest, RationalSubtracting)
{
    Rational number1(3, 2);
    Rational number2(1, 2);
    Rational number3 = number1 - number2;

    EXPECT_EQ(number3.getNumerator(), 1);
    EXPECT_EQ(number3.getDenominator(), 1);
}

TEST(RationalTest, RationalMultiply)
{
    Rational number1(3, 2);
    Rational number2(1, 2);
    Rational number3 = number1 * number2;

    EXPECT_EQ(number3.getNumerator(), 3);
    EXPECT_EQ(number3.getDenominator(), 4);
}

TEST(RationalTest, RationalDividing)
{
    Rational number1(3, 2);
    Rational number2(1, 2);
    Rational number3 = number1 / number2;

    EXPECT_EQ(number3.getNumerator(), 3);
    EXPECT_EQ(number3.getDenominator(), 1);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

