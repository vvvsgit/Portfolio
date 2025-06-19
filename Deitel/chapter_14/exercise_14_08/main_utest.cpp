#include "headers/Array.hpp"

#include <gtest/gtest.h>

TEST(Array, TemplateInt)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    Array<int> withNotFloat;

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "default\n");
}

TEST(Array, TemplateDouble)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    Array<double> withNotFloat;

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "default\n");
}

TEST(Array, Float)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    Array<float> withFloat;

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "float\n");
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

