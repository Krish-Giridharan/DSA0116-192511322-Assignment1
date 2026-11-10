
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Variables with different data types
    string passengerID;
    int passengerAge;
    double cardBalance;
    char passengerCategory;
    bool isStudent;

    // Get passenger details
    cout << "Enter Passenger ID: ";
    cin >> passengerID;

    cout << "Enter Passenger Age: ";
    cin >> passengerAge;

    cout << "Enter Card Balance: ";
    cin >> cardBalance;

    cout << "Enter Passenger Category (S = Student, G = General): ";
    cin >> passengerCategory;

    cout << "Is the passenger a student? (1 = Yes, 0 = No): ";
    cin >> isStudent;

    // Display passenger details
    cout << "\n--- Smart Card Details ---" << endl;
    cout << "Passenger ID: " << passengerID << endl;
    cout << "Passenger Age: " << passengerAge << endl;
    cout << "Card Balance: Rs. " << cardBalance << endl;
    cout << "Passenger Category: " << passengerCategory << endl;
    cout << "Student Status: " << boolalpha << isStudent << endl;

    return 0;
}
