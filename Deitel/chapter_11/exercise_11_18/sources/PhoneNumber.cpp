#include "headers/PhoneNumber.hpp"

#include <iomanip>

std::ostream&
PhoneNumber::operator<<(std::ostream& output)
{
    output << "(" << areaCode_ << ") "
    << exchange_ << "-" << line_;
    return output;
}

std::istream& 
PhoneNumber::operator>>(std::istream& input)
{
    areaCode_ = "";
    exchange_ = "";
    line_ = "";
    const char fill = std::cout.fill(' ');
    input.ignore(); // skip (
    input >> std::setw(3) >> areaCode_;
    input.ignore( 2 ); // skip ) and space
    input >> std::setw(3) >> exchange_;
    input.ignore(); // skip dash (-)
    input >> std::setw(4) >> line_; 
    std::cout << std::setfill(fill);
    return input;
}

std::ostream&
operator<<(std::ostream& output, const PhoneNumber& number)
{
    output << "(" << number.areaCode_ << ") "
    << number.exchange_ << "-" << number.line_;
    return output;
}

std::istream&
operator>>(std::istream& input, PhoneNumber& number)
{
    number.areaCode_ = "";
    number.exchange_ = "";
    number.line_ = "";
    const char fill = std::cout.fill(' ');
    input.ignore(); // skip (
    input >> std::setw(3) >> number.areaCode_;
    input.ignore( 2 ); // skip ) and space
    input >> std::setw(3) >> number.exchange_;
    input.ignore(); // skip dash (-)
    input >> std::setw(4) >> number.line_; 
    std::cout << std::setfill(fill);
    return input;
}

