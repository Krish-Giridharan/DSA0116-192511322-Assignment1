
# TASK 2 – TOKENS, KEYWORDS, IDENTIFIERS AND CONSTANTS

## 1. Aim

To identify and understand tokens, keywords, identifiers, and constants in a C++ program developed for the City Metro Smart-Card System.

## 2. Description

The program accepts the Passenger ID, Passenger Age, and Metro Zone from the user. Based on the selected zone, the program calculates and displays the corresponding metro fare.

The three metro zones and their basic fares are:

- Inner Zone – Rs. 10
- Middle Zone – Rs. 20
- Outer Zone – Rs. 30

The program uses constants to store fixed fare values and variables to store the information entered by the user.

## 3. C++ Program

```cpp
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
```

## 4. Identification of Tokens

Tokens are the smallest individual elements of a C++ program.

### A. Keywords

Keywords are reserved words that have predefined meanings in C++.

Examples used in this program:

- `int`
- `const`
- `using`
- `namespace`
- `if`
- `else`
- `return`

### B. Identifiers

Identifiers are names given to variables, constants, and functions.

Identifiers used in this program:

- `main`
- `passengerID`
- `passengerAge`
- `selectedZone`
- `fare`
- `INNER_FARE`
- `MIDDLE_FARE`
- `OUTER_FARE`

### C. Constants

Constants are fixed values that cannot be changed during program execution.

Constants used:

| Constant | Value |
|---|---:|
| INNER_FARE | 10 |
| MIDDLE_FARE | 20 |
| OUTER_FARE | 30 |

The `const` keyword ensures that these fare values remain unchanged.

### D. Variables

Variables are named memory locations used to store values that may change during program execution.

| Variable | Data Type | Purpose |
|---|---|---|
| passengerID | int | Stores the passenger ID entered by the user |
| passengerAge | int | Stores the passenger age |
| selectedZone | int | Stores the selected metro zone |
| fare | int | Stores the calculated fare |

### E. Operators

Operators are symbols used to perform operations.

Examples used in this program:

- `=` – Assignment operator
- `==` – Equality operator
- `<<` – Output insertion operator
- `>>` – Input extraction operator

## 5. Sample Input

```text
Enter Passenger ID: 192511322
Enter Passenger Age: 21

Select Metro Zone:
1. Inner Zone
2. Middle Zone
3. Outer Zone
Enter your choice: 2
```

## 6. Expected Output

```text
--- Passenger Details ---
Passenger ID: 192511322
Passenger Age: 21
Selected Zone: 2
Fare: Rs. 20
```

## 7. Explanation

1. The program declares three constant values for the metro fares.
2. It declares variables to store the passenger ID, age, selected zone, and fare.
3. The `cin` statement accepts passenger details from the user.
4. The user selects one of the three metro zones.
5. The `if-else` statements identify the selected zone.
6. The corresponding fare is assigned to the `fare` variable.
7. The program displays the passenger details and calculated fare.
8. If the user enters an invalid zone, an error message is displayed.

## 8. Result

Thus, the C++ program successfully demonstrates the use of tokens, keywords, identifiers, constants, variables, and operators in the City Metro Smart-Card System. It accepts passenger details dynamically and calculates the fare according to the selected metro zone.
