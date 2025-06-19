#include "headers/Array.hpp"

#include <iostream> 

template<typename Type>
Array<Type>::Array()
{
    std::cout << "default" << std::endl;
}

Array<float>::Array()
{
    std::cout << "float" << std::endl;
}

