#include "..\include\BankSystem.h"
#include <iostream>

using namespace std;

int main()
{
    BankSystem centralBank;

    Account acc1(101, "Ali", 5000.0, AccountType::SAVINGS);
    BankSystem::incrementAccounts();

    Account acc2(102, "Abbas", 2000.0, AccountType::CHECKING);
    BankSystem::incrementAccounts();

    Customer c1(1, "Ali Mousavi");
    c1.addAccount(acc1);
    centralBank.addCustomer(c1);

    cout << "Transferring 1500 from Ali to Abbas" << endl;
    if (centralBank.transfer(acc1, acc2, 1500.0))
    {
        cout << "Transfer Successful!" << endl;
    }

    acc1.printBalance();
    acc2.printBalance();
    centralBank.showGlobalReport();

    return 0;
}