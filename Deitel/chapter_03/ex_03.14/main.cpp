#include "Employee.hpp"

#include <iostream>

int
main()
{
    Employee employee1("Alexandria", "Dadario", 2300);
    Employee employee2("Zak", "Galifianakis", 5240);

    std::cout << "employee1: " << employee1.getFirstName() << ' ' << employee1.getLastName() << std::endl;
    std::cout << "Yearly salary: " << employee1.getYearlySalary() << std::endl;
    std::cout << "employee2: " << employee2.getFirstName() << ' ' << employee2.getLastName() << std::endl;
    std::cout << "Yearly salary: " << employee2.getYearlySalary() << std::endl;

    employee1.salaryRaiseByTenPercent();
    employee2.salaryRaiseByTenPercent();

    std::cout << "employee1: " << employee1.getFirstName() << ' ' << employee1.getLastName() << std::endl;
    std::cout << "Yearly salary after 10 percent raise: " << employee1.getYearlySalary() << std::endl;
    std::cout << "employee2: " << employee2.getFirstName() << ' ' << employee2.getLastName() << std::endl;
    std::cout << "Yearly salary after 10 percent raise: " << employee2.getYearlySalary() << std::endl;

    return 0;
}

