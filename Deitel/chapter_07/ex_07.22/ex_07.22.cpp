#include <iostream>

const int PRODUCT = 5;
const int PERSON = 4;

void printTabular(int [][PERSON]);
int sumRow(int [][PERSON], int);
int sumColumn(int [][PERSON], int);

int
main()
{
    std::cout << std::endl;

    int sales[PRODUCT][PERSON] = {0};

    for (int i = 0; i < PRODUCT; ++i) {
        for (int j = 0; j < PERSON; ++j) {
            std::cout << "How many products of type " <<  i + 1 << " sold the " << j + 1 << "th salesperson? ";
            int number;
            std::cin >> number;
            if (number < 0) {
                std::cerr << "\nError 1: Wrong quantitiy." << std::endl;
                return 1;
            }
            sales[i][j] += number;
        }
    }
    printTabular(sales);

    std::cout << std::endl;
    return 0;
}

void
printTabular(int sales[][PERSON])
{
    std::cout << std::endl;
    for (int i = 1; i <= PERSON; ++i) {
        std::cout << '\t' << i;
    }
    std::cout << std::endl;
    for (int i = 0; i < PRODUCT; ++i) {
        std::cout << i + 1;
        for (int j = 0; j < PERSON; ++j) {
            std::cout << '\t' << sales[i][j];
        }
        std::cout << '\t' << sumRow(sales, i);
        std::cout << std::endl;
    }
    for (int i = 0; i < PERSON; ++i) {
        std::cout << '\t' << sumColumn(sales, i);
    }
    std::cout << std::endl;
}

int
sumRow(int total[][PERSON], int row)
{
    int totalRow = 0;
    for (int i = 0; i < PERSON; ++i) {
        totalRow += total[row][i];
    }
    return totalRow;
}

int
sumColumn(int total[][PERSON], int column)
{
    int totalColumn = 0;
    for (int i = 0; i < PRODUCT; ++i) {
        totalColumn += total[i][column];
    }
    return totalColumn;
}

