#include "headers/printArray.hpp"

#include <gtest/gtest.h>
#include <sstream>

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

    const int countC = 6;
    char c[countC] = "HELLO";
    printArray(c, countC);

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

}

TEST(PrintArray, PrintInt2)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    const int countA = 5;
    int a[countA] = { 1, 2, 3, 4, 5 };
    EXPECT_EQ(printArray(a, countA, 1, 2), 1);

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "2 ");
}

TEST(PrintArray, PrintDouble2)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    const int countB = 7;
    double b[countB] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
    EXPECT_EQ(printArray(b, countB, 0, 5), 5);

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "1.1 2.2 3.3 4.4 5.5 ");
}

TEST(PrintArray, PrintChar2)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    const int countC = 6;
    char c[countC] = "HELLO";
    EXPECT_EQ(printArray(c, countC, 1, 3), 2);

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "E L ");
}

TEST(PrintArray, Invalid)
{
    const int array[3] = { 1, 1, 1 };
    EXPECT_EQ(printArray(array, 3, 2, 1), 0);
    EXPECT_EQ(printArray(array, 3, -1, 1), 0);
    EXPECT_EQ(printArray(array, 3, 1, 4), 0);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

