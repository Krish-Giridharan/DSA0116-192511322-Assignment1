
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

// All money values are stored in paise.
const long long MIN_BALANCE = 5000;

// Test categories
enum TestType
{
    FARE_TEST,
    ZONE_TEST,
    HOUR_TEST,
    RECHARGE_TEST,
    TRAVEL_TEST
};

// Structure for storing test cases
struct TestCase
{
    string description;
    TestType type;
    int zone;
    string hour;
    long long amount;
    long long expectedValue;
    bool expectedResult;
};

// Check whether the entered hour is a valid number from 0 to 23.
bool parseHour(string input, int &hour)
{
    stringstream ss(input);

    if (!(ss >> hour))
    {
        return false;
    }

    ss >> ws;

    if (!ss.eof())
    {
        return false;
    }

    return hour >= 0 && hour <= 23;
}

// Check whether the hour falls within peak hours.
bool isPeakHour(int hour)
{
    return ((hour >= 8 && hour < 10) ||
            (hour >= 17 && hour < 20));
}

// Calculate fare using the selected zone and hour.
long long calculateFare(int zone, int hour)
{
    long long fare;

    switch (zone)
    {
        case 1:
            fare = 1000;   // Inner Zone: Rs. 10
            break;

        case 2:
            fare = 2000;   // Middle Zone: Rs. 20
            break;

        case 3:
            fare = 3000;   // Outer Zone: Rs. 30
            break;

        default:
            return -1;     // Invalid zone
    }

    if (isPeakHour(hour))
    {
        fare = fare + (fare * 20) / 100;
    }

    return fare;
}

// Check whether the passenger can travel.
bool canTravel(long long balance, long long fare)
{
    return (fare >= 0 &&
            balance >= fare &&
            balance - fare >= MIN_BALANCE);
}

// Reject negative recharge amounts.
bool recharge(long long &balance, long long amount)
{
    if (amount < 0)
    {
        return false;
    }

    balance = balance + amount;
    return true;
}

// Display money in rupees and paise.
void displayMoney(long long amount)
{
    cout << "Rs. " << amount / 100 << "."
         << setfill('0') << setw(2) << amount % 100
         << setfill(' ');
}

// Run all test cases from the test table.
void runTests()
{
    TestCase tests[] =
    {
        {"Inner Zone - Off Peak", FARE_TEST, 1, "12", 0, 1000, true},
        {"Inner Zone - Peak", FARE_TEST, 1, "8", 0, 1200, true},

        {"Middle Zone - Off Peak", FARE_TEST, 2, "12", 0, 2000, true},
        {"Middle Zone - Peak", FARE_TEST, 2, "18", 0, 2400, true},

        {"Outer Zone - Off Peak", FARE_TEST, 3, "12", 0, 3000, true},
        {"Outer Zone - Peak", FARE_TEST, 3, "17", 0, 3600, true},

        {"Boundary - Exactly 8:00", FARE_TEST, 1, "8", 0, 1200, true},
        {"Boundary - Exactly 10:00", FARE_TEST, 1, "10", 0, 1000, true},
        {"Boundary - Exactly 17:00", FARE_TEST, 3, "17", 0, 3600, true},
        {"Boundary - Exactly 20:00", FARE_TEST, 3, "20", 0, 3000, true},

        {"Unknown Zone", ZONE_TEST, 4, "12", 0, 0, false},
        {"Letters Entered for Hour", HOUR_TEST, 1, "abc", 0, 0, false},
        {"Negative Recharge", RECHARGE_TEST, 0, "", -500, 0, false},

        // Balance Rs. 60 minus fare Rs. 10 leaves exactly Rs. 50.
        {"Balance Leaves Exactly Rs. 50", TRAVEL_TEST, 1, "12", 6000, 0, true},

        // Balance Rs. 59.99 minus fare Rs. 10 leaves less than Rs. 50.
        {"Balance Leaves Less Than Rs. 50", TRAVEL_TEST, 1, "12", 5999, 0, false}
    };

    int totalTests = sizeof(tests) / sizeof(tests[0]);
    int passed = 0;

    cout << "\n========== FARE LOGIC TEST RESULTS ==========\n";

    for (int i = 0; i < totalTests; i++)
    {
        string expected;
        string actual;
        bool testPassed = false;

        switch (tests[i].type)
        {
            case FARE_TEST:
            {
                int hour;

                if (parseHour(tests[i].hour, hour))
                {
                    long long fare =
                        calculateFare(tests[i].zone, hour);

                    actual = (fare == -1)
                           ? "Invalid"
                           : "Rs. " + to_string(fare / 100) + "." +
                             (fare % 100 < 10 ? "0" : "") +
                             to_string(fare % 100);

                    expected = "Rs. " +
                               to_string(tests[i].expectedValue / 100) +
                               "." +
                               (tests[i].expectedValue % 100 < 10 ? "0" : "") +
                               to_string(tests[i].expectedValue % 100);

                    testPassed = (fare == tests[i].expectedValue);
                }
                else
                {
                    actual = "Invalid hour";
                    expected = "Valid fare";
                    testPassed = false;
                }

                break;
            }

            case ZONE_TEST:
            {
                long long fare =
                    calculateFare(tests[i].zone, 12);

                actual = (fare == -1) ? "Rejected" : "Accepted";
                expected = "Rejected";
                testPassed = (fare == -1);

                break;
            }

            case HOUR_TEST:
            {
                int hour;
                bool valid = parseHour(tests[i].hour, hour);

                actual = valid ? "Accepted" : "Rejected";
                expected = "Rejected";
                testPassed = !valid;

                break;
            }

            case RECHARGE_TEST:
            {
                long long balance = 10000;
                bool result = recharge(balance, tests[i].amount);

                actual = result ? "Accepted" : "Rejected";
                expected = "Rejected";
                testPassed = !result && balance == 10000;

                break;
            }

            case TRAVEL_TEST:
            {
                int hour;
                parseHour(tests[i].hour, hour);

                long long fare =
                    calculateFare(tests[i].zone, hour);

                bool result = canTravel(tests[i].amount, fare);

                actual = result ? "Allowed" : "Denied";
                expected = tests[i].expectedResult
                         ? "Allowed" : "Denied";

                testPassed = (result == tests[i].expectedResult);

                break;
            }
        }

        if (testPassed)
        {
            passed++;
        }

        cout << "\n" << i + 1 << ". " << tests[i].description;
        cout << "\n   Expected: " << expected;
        cout << "\n   Actual:   " << actual;
        cout << "\n   Status:   " << (testPassed ? "PASS" : "FAIL")
             << endl;
    }

    cout << "\n========== TEST SUMMARY ==========\n";
    cout << "Total Tests: " << totalTests << endl;
    cout << "Passed: " << passed << endl;
    cout << "Failed: " << totalTests - passed << endl;
}

// Calculate a sequence of five journeys.
void fiveJourneyTest()
{
    int zones[5] = {1, 3, 2, 1, 3};
    int hours[5] = {12, 18, 12, 8, 20};

    long long balance = 20000;
    long long totalFare = 0;

    cout << "\n========== FIVE JOURNEY TEST ==========\n";

    for (int i = 0; i < 5; i++)
    {
        long long fare = calculateFare(zones[i], hours[i]);

        cout << "\nJourney " << i + 1 << ": ";

        if (canTravel(balance, fare))
        {
            balance = balance - fare;
            totalFare = totalFare + fare;

            cout << "Fare ";
            displayMoney(fare);
            cout << " - Accepted";
        }
        else
        {
            cout << "Denied";
        }

        cout << "\nRemaining Balance: ";
        displayMoney(balance);
        cout << endl;
    }

    cout << "\nTotal Fare Deducted: ";
    displayMoney(totalFare);

    cout << "\nFinal Balance: ";
    displayMoney(balance);
    cout << endl;
}

int main()
{
    cout << "CITY METRO SMART-CARD FARE TESTING SYSTEM\n";

    runTests();

    fiveJourneyTest();

    return 0;
}
