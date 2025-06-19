#ifndef __FUNCTIONS_HPP__
#define __FUNCTIONS_HPP__

#include <stack>

void infixToPostfix(const char* infix, char* postfix);
bool isOperator(const char o);
int precedence(const char one, const char two);

#endif

