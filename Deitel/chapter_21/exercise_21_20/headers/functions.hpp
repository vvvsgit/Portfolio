#ifndef __FUNCTIONS_HPP__
#define __FUNCTIONS_HPP__

#include <list>

void recursively(const std::list<int>& list);
void recursively(const std::list<int>& list, typename std::list<int>::const_iterator it);

#endif

