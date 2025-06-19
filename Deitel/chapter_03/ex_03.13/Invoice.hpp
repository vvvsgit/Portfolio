#include <string>

class Invoice
{
public:
    Invoice(std::string, std::string, int, int);
    void setPartNumber(std::string);
    void setPartDescription(std::string);
    void setPartQuantity(int);
    void setPartPrice(int);
    std::string getPartNumber();
    std::string getPartDescription();
    int getPartQuantity();
    int getPartPrice();
    int getInvoiceAmount();
private:
    std::string partNumber_;
    std::string partDescription_;
    int partQuantity_;
    int partPrice_;
};

