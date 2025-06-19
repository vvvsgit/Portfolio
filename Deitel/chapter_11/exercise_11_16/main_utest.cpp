#include "headers/String.hpp"

#include <gtest/gtest.h>

TEST(StringTest, strcat)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    String s1("happy");
    String s2(" birthday");
    String s3;
    s3 = s1 + s2;
    std::cout << s3 << std::endl;

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "happy birthday\n");
}

TEST(StringTest, strcpy)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    String s1("happy");
    String s2(" birthday");
    s1 = s2;
    std::cout << s1 << std::endl;

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, " birthday\n");
}

TEST(StringTest, strcmp)
{
    String s1("happy");
    String s2(" birthday");

    EXPECT_FALSE(s2 == s1);

    s2 = s1;
    
    EXPECT_TRUE(s2 == s1);
}

TEST(StringTest, strlen)
{
    String s1("happy");

    EXPECT_EQ(s1.getLength(), 5);
}
int
main(int argc, char** argv)
{   
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

