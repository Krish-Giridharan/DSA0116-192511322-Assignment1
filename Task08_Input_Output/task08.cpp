
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

const long long MIN_BALANCE = 5000;
const int PEAK_SURCHARGE = 20;

// Function to read input safely
int readNumber(string message)
{
    int value;

    while (true)
    {
        cout << message;

        if (cin >> value)
        {
            return value;
        }

        if (cin.eof())
        {
            cout << "\nInput ended. Program stopped.\n";
            return -1;
        }

        cout << "Invalid input! Please enter a number.\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Function to check peak hours
bool isPeakHour(int hour)
{
    return (hour >= 8 && hour < 10) ||
           (hour >= 17 && hour < 20);
}

// Function to calculate fare using integer paise
long long calculateFare(int zone, bool peak)
{
    long long baseFare = 0;

    switch (zone)
    {
        case 1:
            baseFare = 1000;
            break;

        case 2:
            baseFare = 2000;
            break;

        case 3:
            baseFare = 3000;
            break;

        default:
            return -1;
    }

    if (peak)
    {
        baseFare += (baseFare * PEAK_SURCHARGE) / 100;
    }

    return baseFare;
}

// Function to check minimum balance
bool canTravel(long long balance, long long fare)
{
    return (fare >= 0 &&
            balance >= fare &&
            balance - fare >= MIN_BALANCE);
}

// Function to display money
void displayMoney(long long amount)
{
    cout << "Rs. "
         << fixed << setprecision(2)
         << amount / 100.0;
}

// Main function
int main()
{
    long long balance = 10000;

    cout << "====================================\n";
    cout << "       METRO SMART CARD GATE\n";
    cout << "====================================\n";

    cout << "Initial Balance: ";
    displayMoney(balance);
    cout << "\n";

    // Process three journeys
    for (int i = 1; i <= 3; i++)
    {
        cout << "\n--- Journey "
             << setw(2) << setfill('0') << i
             << setfill(' ') << " ---\n";

        cout << "\nSelect Zone:\n";
        cout << "1. Inner Zone\n";
        cout << "2. Middle Zone\n";
        cout << "3. Outer Zone\n";

        // Read zone safely
        int zone = readNumber("Enter zone choice: ");

        if (zone == -1)
            return 0;

        // Validate zone
        while (zone < 1 || zone > 3)
        {
            cout << "Invalid zone! Enter 1, 2 or 3.\n";

            zone = readNumber("Enter zone choice: ");

            if (zone == -1)
                return 0;
        }

        // Read journey hour safely
        int hour = readNumber("Enter journey hour (0-23): ");

        if (hour == -1)
            return 0;

        // Validate hour
        while (hour < 0 || hour > 23)
        {
            cout << "Invalid hour! Enter 0 to 23.\n";

            hour = readNumber("Enter journey hour (0-23): ");

            if (hour == -1)
                return 0;
        }

        // Check peak-hour status
        bool peak = isPeakHour(hour);

        // Calculate fare
        long long fare = calculateFare(zone, peak);

        // Display journey report
        cout << "\n========== JOURNEY REPORT ==========\n";

        cout << "Zone: ";

        if (zone == 1)
            cout << "Inner";
        else if (zone == 2)
            cout << "Middle";
        else
            cout << "Outer";

        cout << "\nJourney Time: "
             << setw(2) << setfill('0') << hour
             << ":00" << setfill(' ');

        cout << "\nPeak Hour: "
             << (peak ? "Yes" : "No");

        cout << "\nFare: ";
        displayMoney(fare);

        // Check balance and deduct fare
        if (canTravel(balance, fare))
        {
            balance -= fare;

            cout << "\nStatus: Travel Accepted";
        }
        else
        {
            cout << "\nStatus: Travel Denied (Low Balance)";
        }

        cout << "\nRemaining Balance: ";
        displayMoney(balance);

        cout << "\n====================================\n";
    }

    // Display final balance
    cout << "\nFinal Card Balance: ";
    displayMoney(balance);

    cout << "\n";

    return 0;
}
