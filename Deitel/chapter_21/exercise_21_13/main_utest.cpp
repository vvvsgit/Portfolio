#include "headers/functions.hpp"

#include <gtest/gtest.h>

TEST(InfixToPostfix, BookCase)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    char expression[] = "(6+2)*5-8/4"; /// = 38
    char infix[strlen(expression + 2)];
    int i;
    for (i = 0; expression[i] != '\0'; ++i) {
        infix[i] = expression[i];
    }
    infix[i] = ')';
    infix[++i] = '\0';
    char postfix[strlen(infix)];

    infixToPostfix(infix, postfix);
    std::cout << postfix;

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput,"62+5*84/-"); 
    EXPECT_EQ(evaluatePostfixExpression(postfix), 38);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

