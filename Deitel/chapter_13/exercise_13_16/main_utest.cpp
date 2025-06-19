#include "headers/Account.hpp"
#include "headers/SavingsAccount.hpp"
#include "headers/CheckingAccount.hpp"

#include <gtest/gtest.h>

TEST(Account, Class)
{
    Account account;
    EXPECT_EQ(account.getBalance(), 0);
    account.credit(100);
    EXPECT_EQ(account.getBalance(), 100);
    account.debit(99);
    EXPECT_EQ(account.getBalance(), 1);
}

TEST(SavingsAccount, Class)
{
    SavingsAccount account;
    EXPECT_EQ(account.getBalance(), 0);
    account.credit(100);
    EXPECT_EQ(account.getBalance(), 100);
    account.debit(99);
    EXPECT_EQ(account.getBalance(), 1);
    EXPECT_EQ(account.calculateInterest(), 1);
}

TEST(CheckingAccount, Class)
{
    CheckingAccount account;
    EXPECT_EQ(account.getBalance(), 0);
    account.credit(100);
    EXPECT_EQ(account.getBalance(), 99);
    account.debit(98);
    EXPECT_EQ(account.getBalance(), 0);
}

int
main(int argc, char** argv)
{
    Account* accounts[] = { new Account(1000.0), new SavingsAccount(2000.0), new CheckingAccount(3000.0) };
    for (size_t i = 0; i < sizeof(accounts) / sizeof(Account); ++i) {
        accounts[i]->debit(13);
        accounts[i]->credit(162);
        std::cout << accounts[i]->getBalance() << std::endl;
        SavingsAccount* savings = dynamic_cast<SavingsAccount*>(accounts[i]);
        if (savings != NULL) {
            savings->credit(savings->calculateInterest());
            std::cout << savings->getBalance() << std::endl;
        }
    }
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

