#include "CompanyPays.hpp"

#include <iostream>

CompanyPays::CompanyPays()
{
    setSalary(0);
}

void
CompanyPays::setSalary(double salary)
{
    if (salary < 0) {
        salary_ = 0;
        return;
    }
    salary_ = salary;
}

double
CompanyPays::getSalary()
{
    return salary_;
}

void
CompanyPays::concludeSalary()
{
    std::cout << "\nEnter employee's pay code (1 - 4): ";
    int payCode;
    std::cin >> payCode;
    switch (payCode) {
    case 1: manager();          break;
    case 2: hourlyWorker();       break;
    case 3: commissionWorker(); break;
    case 4: pieceWorker();      break;
    default: std::cerr << "\nError 1: Wrong paycode.\n"; ::exit(1); break;
    }
}

void
CompanyPays::manager()
{
    int salary = 1000;
    setSalary(salary);
}

void
CompanyPays::hourlyWorker()
{
    int salary = 10;
    std::cout << "\nHow many hours did you worked? ";
    int hours;
    std::cin >> hours;
    if (hours < 0) {
        std::cerr << "\nError 2: Wrong hours." << std::endl;
        ::exit(2);
    }
    setSalary(hours < 40 ? hours * salary : hours * salary + (hours - 40) * 0.5 * salary);
}

void
CompanyPays::commissionWorker()
{
    int salary = 250;
    std::cout << "\nFor How much you sold? ";
    int sold;
    std::cin >> sold;
    if (sold < 0) {
        std::cerr << "\nError 3: Wrong sold." << std::endl;
        ::exit(3);
    }
    setSalary(salary + sold * 0.057);
}

void
CompanyPays::pieceWorker()
{
    int salary = 70;
    std::cout << "\nHow many items you produced? ";
    int item;
    std::cin >> item;
    if (item < 0) {
        std::cerr << "\nError 4: Wrong item." << std::endl;
        ::exit(4);
    }
    setSalary(salary * item);
}

void
CompanyPays::displaySalary()
{
    std::cout << "Your salary is " << getSalary() << std::endl;
}

