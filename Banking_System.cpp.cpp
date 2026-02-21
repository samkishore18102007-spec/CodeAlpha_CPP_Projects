#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string history = "";

struct Account
{
    string name;
    int age;
    string mobile;
    float balance;
};

int main()
{
    Account user;
    int choice;
    float amount;
    bool accountCreated = false;

    cout << "====== DIGITAL BANKING SYSTEM ======\n";

    while(true)
    {
        cout << "\n1. Create Account";
        cout << "\n2. Deposit Money";
        cout << "\n3. Withdraw Money";
        cout << "\n4. Check Balance";
        cout << "\n5. View Account Details";
        cout << "\n6. Transfer Money";
        cout << "\n7. View Transaction History";
        cout << "\n8. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if(choice == 1)
        {
            cin.ignore();
            cout << "\nEnter Full Name: ";
            getline(cin, user.name);

            cout << "Enter Age: ";
            cin >> user.age;

            cout << "Enter Mobile Number: ";
            cin >> user.mobile;

            cout << "Enter Initial Deposit: ";
            cin >> user.balance;

            accountCreated = true;
            history += "Account created with balance: " + to_string((int)user.balance) + "\n";

            cout << "\nAccount created successfully!\n";
        }

        else if(choice == 2 && accountCreated)
        {
            cout << "Enter amount to deposit: ";
            cin >> amount;
            user.balance += amount;
            history += "Deposited: " + to_string((int)amount) + "\n";
            cout << "Deposit successful!\n";
        }

        else if(choice == 3 && accountCreated)
        {
            cout << "Enter amount to withdraw: ";
            cin >> amount;

            if(amount > user.balance)
                cout << "Insufficient balance!\n";
            else
            {
                user.balance -= amount;
                history += "Withdrawn: " + to_string((int)amount) + "\n";
                cout << "Withdrawal successful!\n";
            }
        }

        else if(choice == 4 && accountCreated)
        {
            cout << "Current Balance: " << (int)user.balance << endl;
        }

        else if(choice == 5 && accountCreated)
        {
            cout << "\n--- ACCOUNT DETAILS ---\n";
            cout << "Name: " << user.name << endl;
            cout << "Age: " << user.age << endl;
            cout << "Mobile: " << user.mobile << endl;
            cout << "Balance: " << (int)user.balance << endl;
        }

        else if(choice == 6 && accountCreated)
        {
            string receiver;
            cout << "Enter receiver account number: ";
            cin >> receiver;

            cout << "Enter amount to transfer: ";
            cin >> amount;

            if(amount > user.balance)
                cout << "Insufficient balance!\n";
            else
            {
                user.balance -= amount;
                history += "Transferred " + to_string((int)amount) + " to Acc No: " + receiver + "\n";
                cout << "Transfer successful!\n";
            }
        }

        else if(choice == 7 && accountCreated)
        {
            cout << "\n--- TRANSACTION HISTORY ---\n";
            cout << history;
        }

        else if(choice == 8)
        {
            cout << "Thank you for using our bank!";
            break;
        }

        else
        {
            cout << "Please create account first!\n";
        }
    }

    return 0;
}
