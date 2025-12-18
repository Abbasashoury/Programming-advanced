#include "..\include\BankSystem.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    BankSystem centralBank;
    vector<Account *> bankAccounts;
    int choice;

    while (true)
    {
        cout << "=================================================\n";
        cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. Transfer\n5. Show All Balances\n6. Global Report\n7. Exit\n";
        cout << "Select: ";
        cin >> choice;

        if (choice == 7)
            break;

        switch (choice)
        {
        case 1:
        {
            int id;
            string owner;
            double initial;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Owner Name: ";
            cin >> owner;
            cout << "Initial Balance: ";
            cin >> initial;

            Account *newAcc = new Account(id, owner, initial, AccountType::SAVINGS);
            bankAccounts.push_back(newAcc);
            BankSystem::incrementAccounts();
            cout << "Account created successfully.\n";
            break;
        }

        case 2:
        {
            int id;
            double amt;
            cout << "Enter Account ID: ";
            cin >> id;
            cout << "Enter Amount: ";
            cin >> amt;

            for (int i = 0; i < bankAccounts.size(); i++)
            {
                if (bankAccounts[i]->getId() == id)
                {
                    centralBank.processDeposit(*bankAccounts[i], amt);
                    cout << "Deposit done.\n";
                }
            }
            break;
        }

        case 3:
        {
            int id;
            double amt;
            cout << "Enter Account ID: ";
            cin >> id;
            cout << "Enter Amount: ";
            cin >> amt;

            for (int i = 0; i < bankAccounts.size(); i++)
            {
                if (bankAccounts[i]->getId() == id)
                {
                    centralBank.processWithdraw(*bankAccounts[i], amt);
                    cout << "Action processed.\n";
                }
            }
            break;
        }

        case 4:
        {
            int Fromid, Toid;
            double amt;
            cout << "From ID: ";
            cin >> Fromid;
            cout << "To ID: ";
            cin >> Toid;
            cout << "Amount: ";
            cin >> amt;

            Account *from = nullptr, *to = nullptr;
            for (int i = 0; i < bankAccounts.size(); i++)
            {
                if (bankAccounts[i]->getId() == Fromid)
                    from = bankAccounts[i];
                if (bankAccounts[i]->getId() == Toid)
                    to = bankAccounts[i];
            }

            if (from && to)
            {
                if (centralBank.transfer(*from, *to, amt))
                    cout << "Transfer Success.\n";
                else
                    cout << "Transfer Failed.\n";
            }
            break;
        }

        case 5:
        {
            for (int i = 0; i < bankAccounts.size(); i++)
            {
                bankAccounts[i]->printBalance();
            }
            break;
        }

        case 6:
        {
            centralBank.showGlobalReport();
            break;
        }

        default:
            cout << "Invalid Option.\n";
        }
    }

    for (int i = 0; i < bankAccounts.size(); i++)
    {
        delete bankAccounts[i];
    }

    return 0;
}