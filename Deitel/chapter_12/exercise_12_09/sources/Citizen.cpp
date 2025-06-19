#include "headers/Citizen.hpp"

#include <cassert>

Citizen::Citizen(const std::string& name, const std::string& address, const std::string& city, 
                 const std::string& state, const size_t zip)
{
    setName(name);
    setAddress(address);
    setCity(city);
    setState(state);
    setZip(zip);
}

void
Citizen::setName(const std::string& name)
{
    assert(name != "");
    name_ = name;
}

void
Citizen::setAddress(const std::string& address)
{
    assert(address != "");
    address_ = address;
}

void
Citizen::setCity(const std::string& city)
{
    assert(city != "");
    city_ = city;
}

void
Citizen::setState(const std::string& state)
{
    assert(state != "");
    state_ = state;
}

void
Citizen::setZip(const size_t zip)
{
    zip_ = zip;
}

std::string
Citizen::getName() const
{
    return name_;
}

std::string
Citizen::getAddress() const
{
    return address_;
}

std::string
Citizen::getCity() const
{
    return city_;
}

std::string
Citizen::getState() const
{
    return state_;
}

size_t
Citizen::getZip() const
{
    return zip_;
}

