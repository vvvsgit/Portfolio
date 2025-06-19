#ifndef PHONENUMBER_H
#define PHONENUMBER_H

#include <iostream>
#include <string>

class PhoneNumber
{
    friend std::ostream& operator<<(std::ostream& output, const PhoneNumber& number);
    friend std::istream& operator>>(std::istream& input, PhoneNumber& number);

public:
    std::ostream& operator<<(std::ostream& output);
    std::istream& operator>>(std::istream& input);

private:
    std::string areaCode_; // 3-digit area code
    std::string exchange_; // 3-digit exchange
    std::string line_; // 4-digit line
};

#endif

