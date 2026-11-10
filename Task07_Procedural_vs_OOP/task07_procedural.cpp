
#include <iostream>
using namespace std;

const int MIN_BALANCE = 5000;

// Checks whether the passenger can travel
bool canTravel(long long balance, long long fare)
{
    return (fare >= 0 &&
            balance >= fare &&
            balance - fare >= MIN_BALANCE);
}

// Deducts the fare from the balance
void deduct(long long &balance, long long fare)
{
    if (canTravel(balance, fare))
    {
        balance = balance - fare;
        cout << "Fare deducted successfully." << endl;
    }
    else
    {
        cout << "Travel denied (low balance)." << endl;
    }
}

int main()
{
    long long balance = 10000;

    long long innerFare = 1000;
    long long outerPeakFare = 3600;
    long long middleFare = 2000;

    cout << "Initial Balance: Rs. "
         << balance / 100 << endl;

    deduct(balance, innerFare);
    cout << "Remaining Balance: Rs. "
         << balance / 100 << endl;

    deduct(balance, outerPeakFare);
    cout << "Remaining Balance: Rs. "
         << balance / 100 << endl;

    deduct(balance, middleFare);
    cout << "Remaining Balance: Rs. "
         << balance / 100 << endl;

    return 0;
}