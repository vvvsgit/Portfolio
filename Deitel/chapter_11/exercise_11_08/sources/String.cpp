#include "headers/String.hpp"

#include <iostream>
#include <cstring>


String::String(const char* string)
    : length_((string != 0) ? strlen(string) : 0)
{
    sPtr_ = new char[length_ + 1];
    if (string != 0) {
        std::strcpy(sPtr_, string);
        return;
    }
    sPtr_[0] = '\0';
}

String::String(const String& copy)
    : length_(copy.length_)
{
    sPtr_ = new char[length_];
    std::strcpy(sPtr_, copy.sPtr_);
}

String::~String()
{
    if (sPtr_ != NULL) {
        delete [] sPtr_;
        sPtr_ = NULL;
    }
}

const String&
String::operator=(const String& right)
{
    if (&right == this) return *this;

    if (length_ != right.length_) {
        delete [] sPtr_;
        length_ = right.length_;
        sPtr_ = new char[length_];
    }
    std::strcpy(sPtr_, right.sPtr_);
    return *this;
}

String
String::operator+(const String& right) const
{
    String result;
    delete [] result.sPtr_;
    result.length_ = length_ + right.length_;
    result.sPtr_ = new char[result.length_ + 1];
    std::strcpy(result.sPtr_, sPtr_);
    std::strcpy(result.sPtr_ + length_, right.sPtr_);
    return result;
}

std::ostream&
operator<<(std::ostream& out, const String& string)
{
    out << string.sPtr_;
    return out; 
}

