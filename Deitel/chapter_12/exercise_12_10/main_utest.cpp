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
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

