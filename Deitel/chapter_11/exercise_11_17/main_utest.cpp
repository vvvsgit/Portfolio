#include "headers/Polynomial.hpp"
#include "headers/Term.hpp"

#include <gtest/gtest.h>

TEST(PolynomialTest, OperatorPlus)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());
    Term a(-2, 1);
    Polynomial b(a);
    Term c(2, 6);
    Term d(4, 0);
    Term e[3] = {a, c, d};
    Polynomial f(e, 3);
    b.insert(c);
    b.insert(d);

    Polynomial fb = f + b;
    std::cout << fb;

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, " -4^1 +4^6 +8^0");
}

TEST(PolynomialTest, OperatorMius)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    Term a1(-2, 1);
    Polynomial b1(a1);
    Term c1(2, 6);
    Term d1(4, 0);
    Term e1[3] = {a1, c1, d1};
    Polynomial f1(e1, 3);
    b1.insert(c1);
    b1.insert(d1);

    Polynomial fb1 = f1 - b1;
    std::cout << fb1 << std::endl;

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, " +0^1 +0^6 +0^0\n");
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

