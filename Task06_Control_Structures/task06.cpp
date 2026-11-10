
#include <iomanip>
#include <iostream>

enum class Zone { Inner, Middle, Outer };

constexpr int BASE_PAISE[] = {1000, 2000, 3000};
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

// Checks whether a given hour is a peak hour
bool isPeakHour(int hour)
{
    return (hour >= 8 && hour < 10) ||
           (hour >= 17 && hour < 20);
}

// TODO 1: Calculate the fare using switch
long long fare(Zone z, bool peak)
{
    long long baseFare = 0;

    switch (z)
    {
        case Zone::Inner:
            baseFare = BASE_PAISE[0];
            break;

        case Zone::Middle:
            baseFare = BASE_PAISE[1];
            break;

        case Zone::Outer:
            baseFare = BASE_PAISE[2];
            break;

        default:
            return -1;
    }

    if (peak)
    {
        baseFare +=
            (baseFare * PEAK_SURCHARGE_PERCENT) / 100;
    }

    return baseFare;
}

// TODO 2: Check whether sufficient balance remains
bool canTravel(long long balance, long long f)
{
    return (f >= 0 &&
            balance >= f &&
            balance - f >= MIN_BALANCE_PAISE);
}

int main()
{
    long long balance = 10000;

    struct Trip
    {
        Zone zone;
        bool peak;
    };

    // Original three journeys
    Trip trips[] = {
        {Zone::Inner, false},
        {Zone::Outer, true},
        {Zone::Middle, false}
    };

    // Process the journeys
    for (const Trip& t : trips)
    {
        long long f = fare(t.zone, t.peak);

        if (canTravel(balance, f))
        {
            balance -= f;

            std::cout << "Fare Rs "
                      << f / 100 << '.'
                      << std::setw(2) << std::setfill('0')
                      << f % 100 << std::setfill(' ');
        }
        else
        {
            std::cout << "Denied (low balance)";
        }

        std::cout << " balance Rs "
                  << balance / 100 << '\n';
    }

    // Test journeys at exactly 10 AM and exactly 8 PM
    int testHours[] = {10, 20};

    std::cout << "\n--- Peak Hour Boundary Tests ---\n";

    for (int hour : testHours)
    {
        bool peak = isPeakHour(hour);
        long long testFare = fare(Zone::Inner, peak);

        std::cout << hour << ":00 - Peak: "
                  << (peak ? "Yes" : "No")
                  << ", Fare: Rs "
                  << testFare / 100 << '.'
                  << std::setw(2) << std::setfill('0')
                  << testFare % 100 << std::setfill(' ')
                  << '\n';
    }

    return 0;
}