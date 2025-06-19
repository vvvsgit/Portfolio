#include "headers/functions.hpp"

#include <gtest/gtest.h>

TEST(StackReversePrint, Default)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    printLineReversed();

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "desreveReniLtnirp\n");
}

TEST(StackReversePrint, Argument)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    printLineReversed("My name is Harry Potter. Hello, Harry Potter. My name is Tom Riddle.");

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, ".elddiR moT si eman yM .rettoP yrraH ,olleH .rettoP yrraH si eman yM\n");
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

