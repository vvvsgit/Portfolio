#include <string>

class Employee
{
public:
    Employee(std::string, std::string, int);
    void setFirstName(std::string);
    void setLastName(std::string);
    void setMonthlySalary(int);
    std::string getFirstName();
    std::string getLastName();
    int getMonthlySalary();
    int getYearlySalary();
    void salaryRaiseByTenPercent();
private:
    std::string firstName_;
    std::string lastName_;
    int monthlySalary_;
};

