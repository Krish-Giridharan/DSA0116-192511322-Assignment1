
# TASK 12 – Re-evaluate and Adapt the Design

## 1. Objective

To evaluate and modify the existing City Metro Smart-Card System to support an Airport zone, weekend discounts and monthly passes.

## 2. Impact Analysis

The original system supported three zones. The revised system supports four zones by adding Airport with a fare of Rs. 60.

The ZONE_COUNT constant was changed from 3 to 4. The Zone enumeration was extended with Airport = 4. The fare table was modified to include 6000 paise for the Airport zone.

A weekend discount constant of 10% was introduced. The existing peak surcharge of 20% was retained.

## 3. Evaluation of Original Design

The original switch-based fare calculation can support the Airport zone by adding another case. However, a fare table is easier to extend when more zones are introduced.

The existing SmartCard class was retained because it protects the card balance and enforces the minimum Rs. 50 balance rule.

A separate MonthlyPass class was introduced to manage the two selected zones.

## 4. Revised Design

The revised design contains:

- Four-zone fare table.
- Peak-hour surcharge of 20%.
- Weekend discount of 10%.
- Monthly pass for two selected zones.
- SmartCard class for balance management.
- Minimum remaining balance of Rs. 50.
- Integer-paise fare calculations.

The weekend discount takes priority over the peak surcharge. Both are never applied together.

## 5. Worked Examples

| Condition | Fare |
|---|---:|
| Airport weekday off-peak | Rs. 60 |
| Airport weekday peak | Rs. 72 |
| Airport weekend off-peak | Rs. 54 |
| Airport weekend peak | Rs. 54 |
| Monthly pass covered zone | Rs. 0 |

## 6. Test Results

The revised program was tested for:

1. Normal weekday journeys.
2. Peak-hour surcharge.
3. Weekend discount.
4. Airport zone fare.
5. Weekend peak-hour combination.
6. Monthly pass journeys.
7. Invalid zone and hour inputs.
8. Minimum balance validation.

The program correctly applied the revised fare rules and protected the minimum card balance.

## 7. Complexity Analysis

- Fare lookup: O(1)
- Peak-hour validation: O(1)
- Weekend discount: O(1)
- Monthly pass validation: O(1)
- Pass activation: O(z)
- Fare table storage: O(z)

## 8. Limitations

The monthly pass is assumed to be already purchased. Pass price, expiry date, renewal and payment processing are not implemented because these details were not specified in the requirement.

## 9. Final Recommendation

The modified design is recommended because it retains the existing SmartCard class and integer-paise calculations while introducing a separate MonthlyPass class and a flexible fare table. The revised design satisfies the changed requirements without requiring a complete redesign.
