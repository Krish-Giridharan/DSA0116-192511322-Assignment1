
# TASK 9 – Implement and Test the Fare Logic

## 1. Aim
To implement and test the complete fare calculation logic of a City Metro Smart-Card System using C++.

## 2. Fare Rules
- Inner Zone: Rs. 10
- Middle Zone: Rs. 20
- Outer Zone: Rs. 30
- Peak-hour surcharge: 20%
- Peak hours: 8:00–10:00 AM and 5:00–8:00 PM
- Minimum remaining card balance: Rs. 50

All fare calculations are performed in paise to avoid floating-point calculation errors.

## 3. Program Features
1. Calculates fares for all three zones.
2. Applies a 20% surcharge during peak hours.
3. Checks peak-hour boundaries.
4. Rejects unknown zone selections.
5. Rejects invalid hour input.
6. Rejects negative recharge amounts.
7. Checks the minimum remaining balance.
8. Runs 15 automated test cases.
9. Calculates the total fare for five journeys.

## 4. Test Cases and Results

| Test | Expected Result | Actual Result |
|---|---|---|
| Inner off-peak | Rs. 10.00 | Rs. 10.00 |
| Inner peak | Rs. 12.00 | Rs. 12.00 |
| Middle off-peak | Rs. 20.00 | Rs. 20.00 |
| Middle peak | Rs. 24.00 | Rs. 24.00 |
| Outer off-peak | Rs. 30.00 | Rs. 30.00 |
| Outer peak | Rs. 36.00 | Rs. 36.00 |
| Exactly 8:00 | Rs. 12.00 | Rs. 12.00 |
| Exactly 10:00 | Rs. 10.00 | Rs. 10.00 |
| Exactly 17:00 | Rs. 36.00 | Rs. 36.00 |
| Exactly 20:00 | Rs. 30.00 | Rs. 30.00 |
| Unknown zone | Rejected | Rejected |
| Letters for hour | Rejected | Rejected |
| Negative recharge | Rejected | Rejected |
| Balance leaves Rs. 50 | Allowed | Allowed |
| Balance leaves less than Rs. 50 | Denied | Denied |

## 5. Five-Journey Calculation

Initial balance = Rs. 200

| Journey | Zone | Time | Fare |
|---|---|---|---|
| 1 | Inner | 12:00 | Rs. 10 |
| 2 | Outer | 18:00 | Rs. 36 |
| 3 | Middle | 12:00 | Rs. 20 |
| 4 | Inner | 08:00 | Rs. 12 |
| 5 | Outer | 20:00 | Rs. 30 |

Total fare = Rs. 108

Final balance = Rs. 200 - Rs. 108 = Rs. 92

All five journeys are accepted.

## 6. Complexity Analysis

- One fare calculation: O(1)
- One test case: O(1)
- Processing t test cases: O(t)
- Test table storage: O(t)

A new boundary test can be added easily by inserting another entry into the test-case table.

## 7. Result

The metro smart-card fare logic was implemented and tested successfully. All 15 test cases passed, including normal journeys, peak-hour boundaries, invalid inputs, negative recharge, and minimum-balance validation.
