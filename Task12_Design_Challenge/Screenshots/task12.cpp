
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

// 1. System constants
const int ZONE_COUNT = 4;
const long long MIN_BALANCE = 5000;

const int PEAK_SURCHARGE = 20;
const int WEEKEND_DISCOUNT = 10;

// 2. Metro zones
enum class Zone
{
    Inner = 1,
    Middle = 2,
    Outer = 3,
    Airport = 4
};

// 3. Fare table (values in paise)
const long long fareTable[ZONE_COUNT] =
{
    1000,  // Inner: Rs. 10
    2000,  // Middle: Rs. 20
    3000,  // Outer: Rs. 30
    6000   // Airport: Rs. 60
};

// 4. Safe integer input
bool readNumber(string message, int &value)
{
    string line;

    while (true)
    {
        cout << message;

        if (!getline(cin, line))
        {
            return false;
        }

        stringstream input(line);
        char extra;

        if ((input >> value) && !(input >> extra))
        {
            return true;
        }

        cout << "Invalid input! Please enter a valid number.\n";
    }
}

// 5. Check peak hours
bool isPeakHour(int hour)
{
    return ((hour >= 8 && hour < 10) ||
            (hour >= 17 && hour < 20));
}

// 6. Get zone name
string getZoneName(Zone zone)
{
    switch (zone)
    {
        case Zone::Inner:
            return "Inner";

        case Zone::Middle:
            return "Middle";

        case Zone::Outer:
            return "Outer";

        case Zone::Airport:
            return "Airport";

        default:
            return "Unknown";
    }
}

// 7. Calculate fare
long long calculateFare(Zone zone, int hour, bool weekend)
{
    int index = static_cast<int>(zone) - 1;

    if (index < 0 || index >= ZONE_COUNT)
    {
        return -1;
    }

    long long fare = fareTable[index];

    // Weekend discount takes priority.
    // It is NOT combined with peak surcharge.
    if (weekend)
    {
        fare = fare - (fare * WEEKEND_DISCOUNT) / 100;
    }
    else if (isPeakHour(hour))
    {
        fare = fare + (fare * PEAK_SURCHARGE) / 100;
    }

    return fare;
}

// 8. SmartCard class
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

    long long getBalance() const
    {
        return balance;
    }
};

// 9. MonthlyPass class
class MonthlyPass
{
private:
    bool active;
    bool coveredZones[ZONE_COUNT];

public:
    MonthlyPass()
    {
        active = false;

        for (int i = 0; i < ZONE_COUNT; i++)
        {
            coveredZones[i] = false;
        }
    }

    bool activate(int zone1, int zone2)
    {
        if (zone1 < 1 || zone1 > ZONE_COUNT ||
            zone2 < 1 || zone2 > ZONE_COUNT ||
            zone1 == zone2)
        {
            return false;
        }

        for (int i = 0; i < ZONE_COUNT; i++)
        {
            coveredZones[i] = false;
        }

        coveredZones[zone1 - 1] = true;
        coveredZones[zone2 - 1] = true;

        active = true;
        return true;
    }

    bool covers(Zone zone) const
    {
        int index = static_cast<int>(zone) - 1;

        if (!active || index < 0 || index >= ZONE_COUNT)
        {
            return false;
        }

        return coveredZones[index];
    }

    void displayPass() const
    {
        cout << "\nMonthly Pass: Active\n";
        cout << "Covered Zones: ";

        for (int i = 0; i < ZONE_COUNT; i++)
        {
            if (coveredZones[i])
            {
                cout << getZoneName(static_cast<Zone>(i + 1))
                     << " ";
            }
        }

        cout << "\n";
    }
};

// 10. Display money
void displayMoney(long long amount)
{
    cout << "Rs. " << amount / 100 << "."
         << setfill('0') << setw(2)
         << amount % 100 << setfill(' ');
}

// 11. Display fare table
void displayFareTable()
{
    cout << "\n========== METRO FARE TABLE ==========\n";

    for (int i = 0; i < ZONE_COUNT; i++)
    {
        cout << getZoneName(static_cast<Zone>(i + 1))
             << " Zone: ";

        displayMoney(fareTable[i]);
        cout << endl;
    }
}

// 12. Process a journey
bool processJourney(
    SmartCard &card,
    const MonthlyPass &pass,
    int journeyNumber)
{
    cout << "\n========== JOURNEY "
         << journeyNumber << " ==========\n";

    int zoneChoice;
    int hour;
    int weekendChoice;

    // Read and validate zone
    while (true)
    {
        if (!readNumber(
            "Enter Zone (1=Inner, 2=Middle, 3=Outer, 4=Airport): ",
            zoneChoice))
        {
            return false;
        }

        if (zoneChoice >= 1 && zoneChoice <= ZONE_COUNT)
        {
            break;
        }

        cout << "Invalid zone! Select between 1 and 4.\n";
    }

    // Read and validate hour
    while (true)
    {
        if (!readNumber("Enter Hour (0-23): ", hour))
        {
            return false;
        }

        if (hour >= 0 && hour <= 23)
        {
            break;
        }

        cout << "Invalid hour! Enter between 0 and 23.\n";
    }

    // Read weekend status
    while (true)
    {
        if (!readNumber(
            "Is it weekend? (1=Yes, 0=No): ",
            weekendChoice))
        {
            return false;
        }

        if (weekendChoice == 0 || weekendChoice == 1)
        {
            break;
        }

        cout << "Enter only 1 or 0.\n";
    }

    Zone selectedZone = static_cast<Zone>(zoneChoice);
    bool weekend = (weekendChoice == 1);
    bool peak = isPeakHour(hour);

    cout << "\n--- JOURNEY DETAILS ---\n";

    cout << "Zone: " << getZoneName(selectedZone) << endl;
    cout << "Time: " << setw(2) << setfill('0')
         << hour << ":00" << setfill(' ') << endl;

    cout << "Weekend: " << (weekend ? "Yes" : "No") << endl;
    cout << "Peak Hour: " << (peak ? "Yes" : "No") << endl;

    // Check monthly pass first
    if (pass.covers(selectedZone))
    {
        cout << "Monthly Pass: Applied\n";
        cout << "Fare: Rs. 0.00\n";
        cout << "Journey Accepted (Unlimited Pass).\n";
    }
    else
    {
        long long fare = calculateFare(
            selectedZone, hour, weekend);

        cout << "Monthly Pass: Not Applicable\n";

        if (weekend)
        {
            cout << "Discount Applied: 10%\n";
        }
        else if (peak)
        {
            cout << "Peak Surcharge Applied: 20%\n";
        }
        else
        {
            cout << "No Additional Charge\n";
        }

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
    }

    cout << "Remaining Balance: ";
    displayMoney(card.getBalance());
    cout << endl;

    return true;
}

// 13. Main function
int main()
{
    cout << "====================================\n";
    cout << " CITY METRO SMART-CARD SYSTEM\n";
    cout << " REVISED DESIGN - TASK 12\n";
    cout << "====================================\n";

    displayFareTable();

    // Initial balance Rs. 200
    SmartCard card(20000);

    cout << "\nInitial Card Balance: ";
    displayMoney(card.getBalance());
    cout << endl;

    // Create and activate monthly pass
    MonthlyPass pass;

    int zone1;
    int zone2;

    cout << "\n========== MONTHLY PASS ACTIVATION ==========\n";

    while (true)
    {
        if (!readNumber(
            "Choose first pass zone (1-4): ", zone1))
        {
            return 0;
        }

        if (!readNumber(
            "Choose second pass zone (1-4): ", zone2))
        {
            return 0;
        }

        if (pass.activate(zone1, zone2))
        {
            break;
        }

        cout << "Invalid selection! Choose two different zones.\n";
    }

    pass.displayPass();

    // Process four journeys
    for (int i = 1; i <= 4; i++)
    {
        if (!processJourney(card, pass, i))
        {
            cout << "\nInput ended. Program stopped safely.\n";
            return 0;
        }
    }

    cout << "\n========== FINAL RESULT ==========\n";

    cout << "Final Card Balance: ";
    displayMoney(card.getBalance());
    cout << endl;

    cout << "Four-zone fare system implemented.\n";
    cout << "Weekend discount and peak surcharge separated.\n";
    cout << "Monthly pass supports two selected zones.\n";
    cout << "Minimum balance rule maintained.\n";

    return 0;
}
