class Account
{
public:
    Account(int);
    void setAccountBalance(int);
    int getAccountBalance();
    void credit(int);
    void debit(int);
private:
    int accountBalance_;
};

