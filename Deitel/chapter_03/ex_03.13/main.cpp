#include "Invoice.hpp"

#include <iostream>

int
main()
{
    Invoice thing("kl4562164", "unknown", 141, 25);

    std::cout << "\nthing's number: " << thing.getPartNumber()
              << "\nthing's description: " << thing.getPartDescription()
              << "\nthing's quantity: " << thing.getPartQuantity()
              << "\nthing's price: " << thing.getPartPrice()
              << "\nthing's amount: " << thing.getInvoiceAmount() << std::endl;
    return 0;
}

