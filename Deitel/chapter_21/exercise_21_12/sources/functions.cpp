#include "headers/functions.hpp"

#include <iostream>

void
infixToPostfix(const char* infix, char* postfix)
{
    std::stack<char> tool;
    tool.push('(');

    int infixIndex = 0;
    int postfixIndex = 0;
    while (!tool.empty()) {
        if (infix[infixIndex] >= '0' && infix[infixIndex] <= '9') {
            postfix[postfixIndex] = infix[infixIndex];
            ++postfixIndex;
            ++infixIndex;
            continue;
        }
        if (infix[infixIndex] == '(') {
            tool.push(infix[infixIndex]);
            ++infixIndex;
            continue;
        }
        if (isOperator(infix[infixIndex])) {
            while (isOperator(tool.top())) {
                if (precedence(infix[infixIndex], tool.top()) <= 0) {
                    postfix[postfixIndex] = tool.top();
                    tool.pop();
                    ++postfixIndex;
                } else { break; }
            }
            tool.push(infix[infixIndex]);
            ++infixIndex;
            continue;
        }
        if (infix[infixIndex] == ')') {
            ++infixIndex;
            while (tool.top() != '(') {
                postfix[postfixIndex] = tool.top();
                ++postfixIndex;
                tool.pop();
            }
            tool.pop();
        }
    }
    postfix[postfixIndex] = '\0';
}

bool
isOperator(const char o)
{
    return o == '+' || o == '-' || o == '*' || o == '/' || o == '%';
}

int
precedence(const char one, const char two)
{
    if ((one == '+' || one == '-') && (two == '+' || two == '-')) {
        return 0;
    }
    if ((one == '+' || one == '-') && (two != '+' || two != '-')) {
        return -1;
    }
    return 1;
}

