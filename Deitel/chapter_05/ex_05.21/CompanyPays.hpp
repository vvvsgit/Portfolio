class CompanyPays
{
public:
    CompanyPays();
    void setSalary(double);
    double getSalary();
    void concludeSalary();
    void manager();
    void hourlyWorker();
    void commissionWorker();
    void pieceWorker();
    void displaySalary();
private:
    double salary_;
};

