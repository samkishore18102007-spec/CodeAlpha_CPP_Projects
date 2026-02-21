#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int choice;
    string username, password;
    string user, pass;
    bool found = false;

    while(true)
    {
        cout << "\n====== LOGIN SYSTEM ======\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1)
        {
            cout << "\n--- Register ---\n";
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            ofstream file("users.txt", ios::app);
            file << username << " " << password << endl;
            file.close();

            cout << "Registration successful!\n";
        }

        else if(choice == 2)
        {
            cout << "\n--- Login ---\n";
            cout << "Enter username: ";
            cin >> user;
            cout << "Enter password: ";
            cin >> pass;

            ifstream file("users.txt");
            string storedUser, storedPass;
            found = false;

            while(file >> storedUser >> storedPass)
            {
                if(user == storedUser && pass == storedPass)
                {
                    found = true;
                    break;
                }
            }
            file.close();

            if(found)
                cout << "Login successful! Welcome " << user << " 😊\n";
            else
                cout << "Invalid username or password!\n";
        }

        else if(choice == 3)
        {
            cout << "Thank you! Exiting program.";
            break;
        }

        else
        {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
