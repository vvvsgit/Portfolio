#include "headers/functions.hpp"

#include <gtest/gtest.h>

TEST(StackReversePrint, Argument)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    std::list<int> a;
    a.push_back(9);
    a.push_back(2);
    a.push_back(3);
    a.push_back(8);

    std::list<int> b;
    b.push_back(4);
    b.push_back(7);
    b.push_back(9);

    std::list<int> c;

    merge(a, b, c);
    print(c);

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "2 3 4 7 8 9 9 ");
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

