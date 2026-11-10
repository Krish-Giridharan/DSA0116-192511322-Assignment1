
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
using namespace std;

int main()
{
    // Representative fare: Rs. 12.34 = 1234 paise
    const double fareInRupees = 12.34;
    const long long fareInPaise = 1234;

    // Number of journeys to test
    long long journeys[] = {20000, 500000, 3000000};

    int totalTests = sizeof(journeys) / sizeof(journeys[0]);

    cout << "METRO FARE PERFORMANCE ANALYSIS\n";
    cout << "Fare per journey: Rs. 12.34\n";

    cout << fixed << setprecision(2);

    cout << "\n32-bit int maximum value: "
         << numeric_limits<int>::max() << " paise\n";

    cout << "\n-------------------------------------------------------------\n";
    cout << left << setw(18) << "Journeys"
         << setw(20) << "Double Total (Rs.)"
         << setw(22) << "Integer Total (Rs.)"
         << "Difference (Rs.)\n";

    cout << "-------------------------------------------------------------\n";

    for (int i = 0; i < totalTests; i++)
    {
        long long count = journeys[i];

        // Method 1: Calculate using double
        double doubleTotal = fareInRupees * count;

        // Method 2: Calculate using integer paise
        long long integerTotalPaise = fareInPaise * count;

        double integerTotalRupees =
            integerTotalPaise / 100.0;

        // Difference between the two displayed totals
        double difference =
            doubleTotal - integerTotalRupees;

        cout << left << setw(18) << count
             << setw(20) << doubleTotal
             << setw(22) << integerTotalRupees
             << difference << endl;

        // Check whether a 32-bit int can store the total paise
        if (integerTotalPaise > numeric_limits<int>::max())
        {
            cout << "   int overflow risk: YES\n";
        }
        else
        {
            cout << "   int overflow risk: NO\n";
        }

        // Compare totals after rounding to the nearest paise
        long long roundedDoublePaise =
            llround(doubleTotal * 100.0);

        long long differenceInPaise =
            llabs(roundedDoublePaise - integerTotalPaise);

        cout << "   Difference after rounding: "
             << differenceInPaise << " paise\n";
        cout << endl;
    }

    cout << "-------------------------------------------------------------\n";

    cout << "\nANALYSIS:\n";
    cout << "1. Double stores money using floating-point representation.\n";
    cout << "2. Integer paise stores exact whole-paise values.\n";
    cout << "3. A 32-bit int cannot store every large network total.\n";
    cout << "4. long long is safer for large network calculations.\n";

    return 0;
}
