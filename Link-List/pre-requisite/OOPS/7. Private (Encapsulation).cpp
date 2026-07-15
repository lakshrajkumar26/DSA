#include <iostream>
using namespace std;

class Bank
{

private:

    int balance;

public:

    Bank()
    {
        balance = 0;
    }

    void deposit(int money)
    {
        balance += money;
    }

    void showBalance()
    {
        cout<<balance;
    }

};

int main()
{

    Bank b;

    // Not Allowed

    // b.balance = 10000;

    b.deposit(500);

    b.deposit(200);

    b.showBalance();

}