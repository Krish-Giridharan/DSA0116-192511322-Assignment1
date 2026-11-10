
# TASK 6 - DESIGN THE CONTROL STRUCTURES

## 1. Aim
To design and implement metro fare computation using decision-making and looping control structures in C++.

## 2. Description
The system calculates fares according to the selected metro zone and peak-hour status. It uses integer paise to maintain accurate fare calculations and ensures that at least Rs. 50 remains in the smart card after a journey.

## 3. Decision-Making Structures
- if-else: Used for peak-hour checking and minimum balance verification.
- switch: Used to select the base fare for Inner, Middle and Outer zones.
- Conditional operator: Used to select between two values based on a condition.

## 4. Looping Structures
- for loop: Processes a known number of journeys.
- Range-based for loop: Processes every journey in an array without using an index.
- while loop: Suitable when the number of journeys is unknown.

A range-based for loop is selected because the journeys are stored in an array.

## 5. Break and Continue
- break exits a switch case or loop.
- continue skips the current iteration and moves to the next journey.
- Invalid journeys can be skipped using continue.
- A default case handles an unmatched switch value.

## 6. Algorithmic Pseudocode

ALGORITHM CalculateFare

BEGIN
    INPUT zone
    INPUT peak

    SWITCH zone
        CASE Inner:
            baseFare = 1000
            BREAK
        CASE Middle:
            baseFare = 2000
            BREAK
        CASE Outer:
            baseFare = 3000
            BREAK
        DEFAULT:
            RETURN Invalid Fare
    END SWITCH

    IF peak = TRUE THEN
        surcharge = (baseFare * 20) / 100
        baseFare = baseFare + surcharge
    END IF

    RETURN baseFare
END

ALGORITHM CheckBalance

BEGIN
    INPUT balance
    INPUT fare

    IF fare >= 0 AND balance >= fare AND
       balance - fare >= 5000 THEN
        RETURN TRUE
    ELSE
        RETURN FALSE
    END IF
END

ALGORITHM ProcessJourneys

BEGIN
    balance = 10000

    FOR EACH trip IN trips DO
        fare = CalculateFare(trip.zone, trip.peak)

        IF fare is invalid THEN
            CONTINUE
        END IF

        IF CheckBalance(balance, fare) = TRUE THEN
            balance = balance - fare
            DISPLAY fare
            DISPLAY balance
        ELSE
            DISPLAY "Denied (low balance)"
            DISPLAY balance
        END IF
    END FOR
END

## 7. Implementation
The program uses a switch statement to select the base fare and integer arithmetic to calculate the peak surcharge. It checks the remaining card balance before accepting each journey.

## 8. Expected Output

Fare Rs 10.00 balance Rs 90
Fare Rs 36.00 balance Rs 54
Denied (low balance) balance Rs 54

--- Peak Hour Boundary Tests ---
10:00 - Peak: No, Fare: Rs 10.00
20:00 - Peak: No, Fare: Rs 10.00

## 9. Alternative Concept
An array can replace the switch statement for base-fare lookup. Both approaches provide O(1) lookup time. An array of three long long values requires 24 bytes when each value occupies 8 bytes.

For a fourth zone, the switch requires a new case, while the array requires a new entry and a valid corresponding zone index.

## 10. Conclusion
The program successfully calculates metro fares using switch statements, conditional checks and range-based for loops. Integer paise ensures accurate fare calculations. The minimum balance rule prevents journeys that would leave less than Rs. 50 on the smart card. Boundary testing confirms that exactly 10 AM and 8 PM are not peak hours.