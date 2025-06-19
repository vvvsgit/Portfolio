#include "headers/BasePlusCommissionEmployee.hpp"

#include <iostream>
#include <iomanip>

int
main()
{
    BasePlusCommissionEmployee employee("Bob", "Lewis", "333-33-3333", 5000, .04, 300);
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Employee information obtained by get functions: \n"
    << "\nFirst name is " << employee.getEmployee().getFirstName()
    << "\nLast name is " << employee.getEmployee().getLastName()
    << "\nSocial security number is "
    << employee.getEmployee().getSocialSecurityNumber()
    << "\nGross sales is " << employee.getEmployee().getGrossSales()
    << "\nCommission rate is " << employee.getEmployee().getCommissionRate()
    << "\nBase salary is " << employee.getBaseSalary() << std::endl;
    employee.setBaseSalary(1000);
    std::cout << "\nUpdated employee information output by print function: \n"
    << std::endl;
    employee.print();
    std::cout << "\n\nEmployee's earnings: $" << employee.earnings() << std::endl;

    return 0;
} 

