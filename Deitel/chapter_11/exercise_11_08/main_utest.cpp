#include "headers/String.hpp"

#include <gtest/gtest.h>

TEST(StringTest, OperatorPlus)
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

int
main(int argc, char** argv)
{   
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

