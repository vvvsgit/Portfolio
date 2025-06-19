#include "headers/Palindrome.hpp"

#include <gtest/gtest.h>

TEST(IntPalindrome, TestTrue)
{
    std::vector<int> v;
    v.push_back(37);
    v.push_back(89);
    v.push_back(2);
    v.push_back(6);
    v.push_back(2);
    v.push_back(89);
    v.push_back(37);

    EXPECT_TRUE(palindrome(v));
}

TEST(IntPalindrome, TestFalse)
{
    std::vector<int> v;
    v.push_back(37);
    v.push_back(37);
    v.push_back(89);
    v.push_back(2);
    v.push_back(6);
    v.push_back(2);
    v.push_back(89);
    v.push_back(37);

    EXPECT_FALSE(palindrome(v));
}

TEST(CharPalindrome, TestTrue)
{
    std::vector<char> v;
    v.push_back('a');
    v.push_back('2');
    v.push_back('\'');
    v.push_back(' ');
    v.push_back(' ');
    v.push_back('\'');
    v.push_back('2');
    v.push_back('a');

    EXPECT_TRUE(palindrome(v));
}

TEST(CharPalindrome, TestFalse)
{
    std::vector<char> v;
    v.push_back('a');
    v.push_back('2');
    v.push_back('\n');
    v.push_back(' ');
    v.push_back('\n');
    v.push_back('2');
    v.push_back('a');
    v.push_back('a');

    EXPECT_FALSE(palindrome(v));
}
int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

