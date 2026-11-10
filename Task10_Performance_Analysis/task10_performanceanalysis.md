
# TASK 10 – Compare Expectations with Execution

## 1. Aim
To compare expected and actual fare calculations for different numbers of metro journeys and evaluate floating-point accuracy, integer overflow, and compiler warnings.

## 2. Experimental Assumption
Fare per journey = Rs. 12.34 (1234 paise).

Journey counts:
- 20,000
- 500,000
- 3,000,000

## 3. Calculation Methods

### Double Method
The total fare is calculated by multiplying the fare in rupees by the number of journeys.

### Integer-Paise Method
The fare is converted into paise and multiplied by the number of journeys using long long.

## 4. Expected and Actual Results

| Journeys | Double Total | Integer Total | Difference |
|---|---|---|---|
| 20,000 | Rs. 246800.00 | Rs. 246800.00 | Rs. 0.00 |
| 500,000 | Rs. 6170000.00 | Rs. 6170000.00 | Rs. 0.00 |
| 3,000,000 | Rs. 37020000.00 | Rs. 37020000.00 | Rs. 0.00 |

The totals agree after rounding to two decimal places.

## 5. Integer Overflow Analysis

A 32-bit signed int has a maximum value of 2,147,483,647.

| Journeys | Total Paise | Overflow Risk |
|---|---:|---|
| 20,000 | 24,680,000 | No |
| 500,000 | 617,000,000 | No |
| 3,000,000 | 3,702,000,000 | Yes |

The total for 3,000,000 journeys exceeds the maximum value of a 32-bit int.

Therefore, long long is recommended for large network fare calculations.

## 6. Compiler Warning Analysis

The program is compiled using:

g++ -std=c++11 -Wall -Wextra -pedantic task10_performance_analysis.cpp -o task10

- -Wall enables common compiler warnings.
- -Wextra enables additional warnings.
- -pedantic checks strict C++ standard compliance.
- -std=c++11 selects the C++11 standard.

Expected result: The supplied program should compile without warnings on a compatible compiler.

Any warnings displayed by the actual compiler should be recorded and explained separately.

## 7. Reasons for Differences

1. Floating-point numbers may not represent decimal fractions exactly.
2. Rounding may hide small differences in displayed results.
3. A 32-bit int can overflow when storing large network totals.
4. long long provides a larger storage range.
5. Incorrect data-type conversion can affect the final calculation.

## 8. Result

The double and integer-paise totals agreed after rounding for all three journey counts. However, a 32-bit int was insufficient for the total paise at 3,000,000 journeys. Therefore, long long is recommended for large-scale fare calculations, while integer paise is preferred for accurate monetary calculations.
