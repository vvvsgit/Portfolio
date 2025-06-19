#include "headers/printArray.hpp"

#include <gtest/gtest.h>

TEST(PrintArray, PrintInt)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    const int countA = 5;
    int a[countA] = { 1, 2, 3, 4, 5 };
    printArray(a, countA);

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "1 2 3 4 5 ");
}

TEST(PrintArray, PrintDouble)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    const int countB = 7;
    double b[countB] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
    printArray(b, countB);

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "1.1 2.2 3.3 4.4 5.5 6.6 7.7 ");
}

TEST(PrintArray, PrintChar)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    const int countC = 26;
    char c[countC] = "HELLOHELLOHELLOHELLOHELLO";
    printArray(c, countC);

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "H E L L O \nH E L L O \nH E L L O \nH E L L O \nH E L L O \n");
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

