
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

// 1. System constants
const long long MIN_BALANCE = 5000;  // Rs. 50 in paise
const int ZONE_COUNT = 3;

// 2. Zone enumeration
enum class Zone
{
    Inner = 1,
    Middle = 2,
    Outer = 3
};

// 3. Fare table stored directly in the program
// All values are in paise.
const long long fareTable[ZONE_COUNT] =
{
    1000,  // Inner Zone: Rs. 10
    2000,  // Middle Zone: Rs. 20
    3000   // Outer Zone: Rs. 30
};

// 4. Check peak hours
bool isPeakHour(int hour)
{
    return ((hour >= 8 && hour < 10) ||
            (hour >= 17 && hour < 20));
}

// 5. Calculate journey fare
long long calculateFare(Zone zone, int hour)
{
    int index = static_cast<int>(zone) - 1;

    if (index < 0 || index >= ZONE_COUNT)
    {
        return -1;
    }

    long long fare = fareTable[index];

    if (isPeakHour(hour))
    {
        fare = fare + (fare * 20) / 100;
    }

    return fare;
}

// 6. SmartCard class
class SmartCard
{
private:
    long long balance;

public:
    SmartCard(long long initialBalance)
    {
        balance = initialBalance;
    }

    bool canTravel(long long fare) const
    {
        return (fare >= 0 &&
                balance >= fare &&
                balance - fare >= MIN_BALANCE);
    }

    bool deduct(long long fare)
    {
        if (!canTravel(fare))
        {
            return false;
        }

        balance = balance - fare;
        return true;
    }

    bool recharge(long long amount)
    {
        if (amount < 0)
        {
            return false;
        }

        if (amount > numeric_limits<long long>::max() - balance)
        {
            return false;
        }

        balance = balance + amount;
        return true;
    }

    long long getBalance() const
    {
        return balance;
    }
};

// 7. Display money
void displayMoney(long long amount)
{
    cout << "Rs. " << amount / 100 << "."
         << setfill('0') << setw(2)
         << amount % 100 << setfill(' ');
}

// 8. Safe integer input
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
            return -1;
        }

        cout << "Invalid input! Enter a number.\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// 9. Display fare table
void displayFareTable()
{
    cout << "\n========== METRO FARE TABLE ==========\n";

    for (int i = 0; i < ZONE_COUNT; i++)
    {
        cout << "Zone " << i + 1 << ": ";
        displayMoney(fareTable[i]);
        cout << endl;
    }
}

// 10. Process a journey
void processJourney(SmartCard &card, int journeyNumber)
{
    cout << "\n========== JOURNEY "
         << journeyNumber << " ==========\n";

    int zoneChoice = readNumber(
        "Enter Zone (1=Inner, 2=Middle, 3=Outer): ");

    if (zoneChoice == -1)
        return;

    if (zoneChoice < 1 || zoneChoice > 3)
    {
        cout << "Invalid zone selection!\n";
        return;
    }

    int hour = readNumber("Enter hour (0-23): ");

    if (hour == -1)
        return;

    if (hour < 0 || hour > 23)
    {
        cout << "Invalid hour!\n";
        return;
    }

    Zone selectedZone = static_cast<Zone>(zoneChoice);

    long long fare = calculateFare(selectedZone, hour);

    cout << "\nPeak Hour: "
         << (isPeakHour(hour) ? "Yes" : "No") << endl;

    cout << "Fare: ";
    displayMoney(fare);
    cout << endl;

    if (card.deduct(fare))
    {
        cout << "Journey Accepted.\n";
    }
    else
    {
        cout << "Journey Denied (Minimum Balance Rule).\n";
    }

    cout << "Remaining Balance: ";
    displayMoney(card.getBalance());
    cout << endl;
}

// 11. Demonstrate fare revision
void demonstrateFareRevision()
{
    cout << "\n========== FARE REVISION ==========\n";

    cout << "Current fares are stored in the fareTable array.\n";

    cout << "To revise fares, change the array values:\n";

    cout << "Inner Zone: Rs. 12.00\n";
    cout << "Middle Zone: Rs. 22.00\n";
    cout << "Outer Zone: Rs. 35.00\n";

    cout << "After changing the array, recompile the program.\n";
}

// 12. Main function
int main()
{
    cout << "CITY METRO SMART-CARD SYSTEM\n";
    cout << "FINAL DESIGN DEMONSTRATION\n";

    displayFareTable();

    SmartCard card(10000);  // Initial balance Rs. 100

    cout << "\nInitial Balance: ";
    displayMoney(card.getBalance());
    cout << endl;

    for (int i = 1; i <= 3; i++)
    {
        processJourney(card, i);
    }

    // Test negative recharge
    cout << "\n========== RECHARGE TEST ==========\n";

    if (card.recharge(-500))
    {
        cout << "Recharge Successful.\n";
    }
    else
    {
        cout << "Negative Recharge Rejected.\n";
    }

    cout << "\nFinal Card Balance: ";
    displayMoney(card.getBalance());
    cout << endl;

    demonstrateFareRevision();

    cout << "\n========== FINAL DESIGN RESULT ==========\n";
    cout << "Integer-paise calculation is used.\n";
    cout << "SmartCard balance is protected using private access.\n";
    cout << "Fare table is maintained using an array.\n";
    cout << "Peak-hour and minimum-balance rules are applied.\n";

    return 0;
}
