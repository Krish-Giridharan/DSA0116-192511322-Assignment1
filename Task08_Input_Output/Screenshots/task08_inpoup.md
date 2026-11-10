
# TASK 8 - READ AND PRINT DATA SAFELY

## 1. Aim
To implement safe input and formatted output for a metro smart-card gate system using C++ input validation and formatting functions.

## 2. Description
The program accepts the passenger's selected metro zone and journey hour. It calculates the fare, checks the available balance and displays a journey report.

The initial balance is Rs. 100, and at least Rs. 50 must remain after a successful journey.

## 3. Safe Input Handling
The program uses cin to read numeric values.

- cin.fail() checks whether an input operation has failed.
- cin.clear() resets the input error state.
- cin.ignore() discards the remaining invalid characters.
- The program asks the operator to enter the value again.

This prevents incorrect alphabetic input from stopping the program.

## 4. Money Formatting
The <iomanip> header provides formatting functions.

- setw() sets the output field width.
- setfill() specifies the character used to fill unused positions.
- fixed displays floating-point values in fixed decimal notation.
- setprecision(2) displays two digits after the decimal point.

The fare is calculated using integer paise and converted to rupees only for display.

## 5. Program Logic
1. Initialize the smart-card balance to Rs. 100.
2. Read the zone from the operator.
3. Validate the zone.
4. Read and validate the journey hour.
5. Check whether the journey is during peak hours.
6. Calculate the base fare.
7. Add the peak surcharge when applicable.
8. Check whether at least Rs. 50 remains after deduction.
9. Deduct the fare if the journey is accepted.
10. Display the journey report and remaining balance.
11. Repeat for three journeys.

## 6. Expected Output

Initial Balance: Rs. 100.00

Journey 1:
Zone: Inner
Journey Time: 10:00
Peak Hour: No
Fare: Rs. 10.00
Status: Travel Accepted
Remaining Balance: Rs. 90.00

Journey 2:
Zone: Outer
Journey Time: 18:00
Peak Hour: Yes
Fare: Rs. 36.00
Status: Travel Accepted
Remaining Balance: Rs. 54.00

Journey 3:
Zone: Middle
Journey Time: 12:00
Peak Hour: No
Fare: Rs. 20.00
Status: Travel Denied (Low Balance)
Remaining Balance: Rs. 54.00

Final Card Balance: Rs. 54.00

## 7. Invalid Input Recovery
When the operator enters letters instead of a number, cin.fail() detects the error.

The program uses cin.clear() to reset the error state and cin.ignore() to discard the invalid input. It then requests the value again.

## 8. Alternative Concept: getline() and stoi()
An alternative method is to read an entire line using getline() and convert it using stoi() inside a try-catch block.

This approach can detect invalid numeric conversions and additional characters.

## 9. Complexity Analysis
For an input line of length L:

- cin-based input processing: O(L) in the general case.
- getline() and stoi(): O(L).
- cin uses stream buffering and stores the converted integer.
- getline() stores the input line in a string, requiring O(L) buffer space.

Both methods can recover from invalid input, but they use different error-handling mechanisms.

## 10. Conclusion
The program successfully reads and validates metro journey information, recovers from invalid numeric input, calculates fares and displays a formatted journey report. Safe input handling prevents incorrect entries from interrupting the program, while formatted output makes the journey details easy to understand.
