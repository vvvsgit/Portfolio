#ifndef __STRING_HPP__
#define __STRING_HPP__

#include <iostream>

class String
{
    friend std::ostream& operator<<(std::ostream& output, const String& string);
    friend std::istream& operator>>(std::istream& input, String& string);

public:
    String();
    String(const char* string);
    String(const String& copy);
    ~String();

    const String& operator=(const String& right); /// strcpy
    String operator+(const String& right); /// strcat
    bool operator==(const String& right) const; ///strcmp

    int getLength() const; /// strlen

private:
    int length_;
    char* sPtr_;
};

#endif

