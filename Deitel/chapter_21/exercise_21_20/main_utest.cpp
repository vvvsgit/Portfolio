#include "headers/functions.hpp"

#include <gtest/gtest.h>

TEST(ListRecursively, Int)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    std::list<int> numbers;
    for (int i = 0; i < 10; ++i) {
        numbers.push_back(i);
    }
    recursively(numbers);

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "9876543210");
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

