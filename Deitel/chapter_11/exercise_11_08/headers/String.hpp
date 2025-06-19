#ifndef __STRING_HPP__
#define __STRING_HPP__

#include <iostream>

class String
{
    friend std::ostream& operator<<(std::ostream& out, const String& string);

public:
    String(const char* string = ""); 
    String(const String& copy);
    ~String();

    const String& operator=(const String& right);
    String operator+(const String& right) const;

private:
    int length_;
    char* sPtr_; 
};

#endif
