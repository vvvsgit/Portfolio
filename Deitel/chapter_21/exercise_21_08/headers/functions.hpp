#ifndef __FUNCTIONS_HPP__
#define __FUNCTIONS_HPP__

#include <list>
#include <cstddef>
#include <cstdlib>

void fill(std::list<int>& list, const size_t size = 25);
int sum(const std::list<int>& list);
double average(const std::list<int>& list);
void print(const std::list<int>& list);

#endif

