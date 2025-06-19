#include "headers/HugeInteger.hpp"

#include <iostream>
#include <unistd.h>
#include <gtest/gtest.h>
#include <sstream>

TEST(HugeIntegerTest, OutputFunction)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    HugeInteger integer = "648465346846316";
    std::cout << integer;

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "648465346846316");
}

TEST(HugeIntegerTest, DefaultConstructor)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    HugeInteger integer;
    std::cout << integer;

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "0");
}

TEST(HugeIntegerTest, Constructor)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    HugeInteger integer("0");
    std::cout << integer;

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);
    
    EXPECT_EQ(lastOutput, "0");
}

TEST(HugeIntegerTest, AddFunction)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    HugeInteger integer1 = "456789123";
    HugeInteger integer2 = "215634567891236845";
    HugeInteger integer3 = integer1 + integer2;
    std::cout << integer3;

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "215634568348025968"); 
}

TEST(HugeIntegerTest, subtractFunction)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    HugeInteger integer1 = "456789123";
    HugeInteger integer2 = "215634567891236845";
    HugeInteger integer3 = integer2 - integer1;
    std::cout << integer3;
    
    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "215634567434447722");

}

TEST(HugeIntegerTest, subtractFunction2)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    HugeInteger integer1 = "10000";
    HugeInteger integer2 = "111";
    HugeInteger integer3 = integer1 - integer2;
    std::cout << integer3;
    
    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "9889");

}

int
main(int argc, char** argv)
{
    std::cout << std::endl;
  
    HugeInteger one("456789123");
    std::cout << "one = ";
    std::cout << one;
    std::cout << std::endl;

    HugeInteger two("465");
    std::cout << "two = ";
    std::cout << two;
    std::cout << std::endl;
    
    std::cout << (one == two ? "one == two" : "one != two") <<std::endl;
    std::cout << (one > two ? "one > two" : "one !> two") <<std::endl;
    std::cout << (one < two ? "one < two" : "one !< two") <<std::endl;
    
    one = one + two;
    std::cout << "one = one + two = ";
    std::cout << one;
    std::cout << std::endl;
    
    one = one - two;
    std::cout << "one = one - two = ";
    std::cout << one;
    std::cout << std::endl;

    HugeInteger a = 13;
    HugeInteger b = 12;
    std::cout << a;
    std::cout << std::endl;
    std::cout << a - b;

    std::cout << std::endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

