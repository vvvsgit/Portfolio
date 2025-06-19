#include "headers/functions.hpp"

#include <gtest/gtest.h>

TEST(StackReversePrint, Default)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    std::list<int> intList;
    fill(intList);
    print(intList);

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "83 86 77 15 93 35 86 92 49 21 62 27 90 59 63 26 40 26 72 36 11 68 67 29 82 ");
    EXPECT_EQ(sum(intList), 1395);
    EXPECT_EQ(average(intList), 55.8);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

