#include "headers/Employee.hpp"
#include "headers/SalariedEmployee.hpp"
#include "headers/HourlyEmployee.hpp"
#include "headers/CommissionEmployee.hpp"
#include "headers/BasePlusCommissionEmployee.hpp"
#include "headers/Date.hpp"

#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <vector>

/*
TEST(ClassName, TestName)
{
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(1);
    EXPECT_FALSE(0);
}
*/

void virtualViaPointer(const Employee* const baseClassRef);
void virtualViaReference(const Employee& baseClassPtr);

int
main()
//main(int argc, char** argv)
{
    Date date;
    std::cout << std::fixed << std::setprecision( 2 );

    Date date1(10, 17, 1997);
    Date date2(12, 27, 1992);
    Date date3(2, 28, 1980);
    Date date4(7, 13, 2002);

    SalariedEmployee salariedEmployee("John", "Smith", "111-11-1111", date1, 800);
    HourlyEmployee hourlyEmployee("Karen", "Price", "222-22-2222", date2, 16.75, 40);
    CommissionEmployee commissionEmployee("Sue", "Jones", "333-33-3333", date3, 10000, 0.06);
    BasePlusCommissionEmployee basePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", date4, 5000, 0.04, 300);

    std::cout << "Employees processed individually using static binding:\n\n";
    // output each Employee's information and earnings using static binding
    salariedEmployee.print();
    std::cout << "\nearned $" << salariedEmployee.earnings() << "\n\n";
    hourlyEmployee.print();
    std::cout << "\nearned $" << hourlyEmployee.earnings() << "\n\n";
    commissionEmployee.print();
    std::cout << "\nearned $" << commissionEmployee.earnings() << "\n\n";
    basePlusCommissionEmployee.print();
    std::cout << "\nearned $" << basePlusCommissionEmployee.earnings() << "\n\n";

    // create vector of four base-class pointers
    std::vector <Employee*> employees(4);
    employees[0] = &salariedEmployee;
    employees[1] = &hourlyEmployee;
    employees[2] = &commissionEmployee;
    employees[3] = &basePlusCommissionEmployee;

    std::cout << "Employees processed polymorphically via dynamic binding:\n\n";
    // call virtualViaPointer to print each Employee's information
    // and earnings using dynamic binding
    std::cout << "Virtual function calls made off base-class pointers:\n\n";
    for (size_t i = 0; i < employees.size(); i++) {
        virtualViaPointer(employees[i]);
    }

    // call virtualViaReference to print each Employee's information
    // and earnings using dynamic binding
    std::cout << "Virtual function calls made off base-class references:\n\n";
    for (size_t i = 0; i < employees.size(); i++) {
        virtualViaReference(*employees[i]);
    }

    return 0;
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
}

void
virtualViaPointer(const Employee*const baseClassPtr)
{
    baseClassPtr->print();
    std::cout << "\nearned $" << baseClassPtr->earnings() << "\n\n" << std::endl;
}

void
virtualViaReference(const Employee& baseClassRef)
{
    baseClassRef.print();
    std::cout << "\nearned $" << baseClassRef.earnings() << "\n\n" << std::endl;
}

