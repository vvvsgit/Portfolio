#include <iostream>
#include <vector>

int
main()
{
    const int amount = 9;
    std::vector<int> salaryArray(amount);
    int salary;
    do {
        std::cout << "\nEnter salary minimum 200 (0 to end): ";
        std::cin >> salary;
        if (salary == 0) { break; }
        if (salary < 200) {
            std::cerr << "\nError 1: You are not working here maybe." << std::endl;
            return 1;
        }
        if (salary / 100 >= 10) {
            ++salaryArray[8];
        } else {
            ++salaryArray[salary / 100 - 2];
        }
    } while (true);

    for (int i = 0; i < salaryArray.size(); ++i) {
        if (i == 8) {
        std::cout << '$' << "1000 and over - " << salaryArray[i] << std::endl;
        } else {
            std::cout << '$' << (2 + i) * 100 << "-$" << (2 + i) * 100 + 99 << " - " << salaryArray[i] << std::endl;
        }
    }

    return 0;
}

