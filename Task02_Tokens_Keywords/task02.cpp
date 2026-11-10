
#include <iostream>
using namespace std;

int main()
{
    // Constants
    const int INNER_FARE = 10;
    const int MIDDLE_FARE = 20;
    const int OUTER_FARE = 30;

    // Variables
    int passengerID;
    int passengerAge;
    int selectedZone;
    int fare;

    // Get input from user
    cout << "Enter Passenger ID: ";
    cin >> passengerID;

    cout << "Enter Passenger Age: ";
    cin >> passengerAge;

    cout << "\nSelect Metro Zone:" << endl;
    cout << "1. Inner Zone" << endl;
    cout << "2. Middle Zone" << endl;
    cout << "3. Outer Zone" << endl;
    cout << "Enter your choice: ";
    cin >> selectedZone;

    // Determine fare
    if (selectedZone == 1)
    {
        fare = INNER_FARE;
    }
    else if (selectedZone == 2)
    {
        fare = MIDDLE_FARE;
    }
    else if (selectedZone == 3)
    {
        fare = OUTER_FARE;
    }
    else
    {
        cout << "Invalid zone selection!" << endl;
        return 0;
    }

    // Display passenger details
    cout << "\n--- Passenger Details ---" << endl;
    cout << "Passenger ID: " << passengerID << endl;
    cout << "Passenger Age: " << passengerAge << endl;
    cout << "Selected Zone: " << selectedZone << endl;
    cout << "Fare: Rs. " << fare << endl;

    return 0;
}
