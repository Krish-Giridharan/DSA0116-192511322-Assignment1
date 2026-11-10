
#include <iostream>
using namespace std;

class SmartCard
{
private:
    long long balance;
    const long long MIN_BALANCE = 5000;

public:
    // Constructor
    SmartCard()
    {
        balance = 10000;
    }

    // Checks whether the passenger can travel
    bool canTravel(long long fare) const
    {
        return (fare >= 0 &&
                balance >= fare &&
                balance - fare >= MIN_BALANCE);
    }

    // Deducts the fare if sufficient balance is available
    void deduct(long long fare)
    {
        if (canTravel(fare))
        {
            balance = balance - fare;
            cout << "Fare deducted successfully." << endl;
        }
        else
        {
            cout << "Travel denied (low balance)." << endl;
        }
    }

    // Displays the current balance
    void displayBalance() const
    {
        cout << "Remaining Balance: Rs. "
             << balance / 100 << endl;
    }
};

int main()
{
    SmartCard card;

    cout << "Initial Balance: Rs. 100" << endl;

    card.deduct(1000);
    card.displayBalance();

    card.deduct(3600);
    card.displayBalance();

    card.deduct(2000);
    card.displayBalance();

    return 0;
}