#ifndef __FUNCTIONS_HPP__
#define __FUNCTIONS_HPP__

#include <stack>

void infixToPostfix(const char* infix, char* postfix);
bool isOperator(const char o);
int precedence(const char one, const char two);

int evaluatePostfixExpression(const char* postfix);
int calculate(const int op1, const char op, const int op2);

#endif

