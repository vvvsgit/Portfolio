#ifndef __CITIZEN_HPP__
#define __CITIZEN_HPP__

#include <string>

class Citizen
{
public:
    Citizen(const std::string& name, const std::string& address, const std::string& city, 
            const std::string& state, const size_t zip);

    void setName(const std::string& name);
    void setAddress(const std::string& address);
    void setCity(const std::string& city);
    void setState(const std::string& state);
    void setZip(const size_t zip);

    std::string getName() const;
    std::string getAddress() const;
    std::string getCity() const;
    std::string getState() const;
    size_t getZip() const;

private:
    std::string name_;
    std::string address_;
    std::string city_;
    std::string state_;
    size_t zip_;
};

#endif


