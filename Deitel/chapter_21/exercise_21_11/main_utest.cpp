#include "headers/functions.hpp"

#include <gtest/gtest.h>

TEST(withStack, isPalindrome)
{
    EXPECT_TRUE(isPalindrome(std::string("qweewq")));
    EXPECT_FALSE(isPalindrome(std::string("qweewa")));

    EXPECT_TRUE(isPalindrome(std::string("qwerewq")));
    EXPECT_FALSE(isPalindrome(std::string("qwerewqa")));

    EXPECT_TRUE(isPalindrome(std::string("A man, a plan, a canal, panamA.")));
    EXPECT_TRUE(isPalindrome(std::string("A man, a plan, a canal, panama.")));
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

