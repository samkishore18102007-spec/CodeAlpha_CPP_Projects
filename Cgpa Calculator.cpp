#include <iostream>
using namespace std;

int main()
{
    int n, credit;
    float grade, totalPoints = 0, totalCredits = 0, cgpa;

    cout << "===== CGPA CALCULATOR =====\n";
    cout << "Enter number of subjects: ";
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cout << "\nSubject " << i << endl;

        cout << "Enter grade point: ";
        cin >> grade;

        cout << "Enter subject credit: ";
        cin >> credit;

        totalPoints += grade * credit;
        totalCredits += credit;
    }

    cgpa = totalPoints / totalCredits;

    cout << "\nYour CGPA is: " << cgpa;

    return 0;
}
