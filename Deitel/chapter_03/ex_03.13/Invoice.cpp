#include "Invoice.hpp"

#include <iostream>

Invoice::Invoice(std::string number, std::string description, int quantity, int price)
{
    setPartNumber(number);
    setPartDescription(description);
    setPartQuantity(quantity);
    setPartPrice(price);
}

void
Invoice::setPartNumber(std::string number)
{
    if (number.length() > 11) {
        partNumber_ = number.substr(0, 10);
        std::cout << "Part number " << number << "exceeds maximum length." << std::endl;
        return;
    }
    partNumber_ = number;
}

void
Invoice::setPartDescription(std::string description)
{
    if (description.length() > 11) {
        partDescription_ = description.substr(0, 10);
        std::cout << "Part description " << description << "exceeds maximum length." << std::endl;
        return;
    }
    partDescription_ = description;
}

void
Invoice::setPartQuantity(int quantity)
{
    if (quantity < 0) {
        partQuantity_ = 0;
        return;
    }
    partQuantity_ = quantity;
}

void
Invoice::setPartPrice(int price)
{
    if (price < 0) {
        partPrice_ = 0;
        return;
    }
    partPrice_ = price;
}

std::string
Invoice::getPartNumber()
{
    return partNumber_;
}

std::string
Invoice::getPartDescription()
{
    return partDescription_;
}

int
Invoice::getPartQuantity()
{
    return partQuantity_;
}

int
Invoice::getPartPrice()
{
    return partPrice_;
}

int
Invoice::getInvoiceAmount()
{
    return getPartQuantity() * getPartPrice();
}

