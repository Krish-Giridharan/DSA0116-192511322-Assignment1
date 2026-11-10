
# TASK 5 – WRITE CORRECT EXPRESSIONS WITH THE RIGHT PRECEDENCE

## 1. Aim

To evaluate C++ operator precedence and associativity, write correct expressions for metro fare calculations, predict program output, and analyse an alternative peak-hour checking method.

## 2. Peak-Hour Check Expression

The metro peak hours are 8 AM to 10 AM and 5 PM to 8 PM.

Correct expression:

```cpp
bool isPeak = (hour >= 8 && hour < 10) ||
              (hour >= 17 && hour < 20);
```

Explanation:

- `>=` and `<` are relational operators.
- `&&` checks whether both conditions in a time range are true.
- `||` checks whether either time range is true.
- Parentheses group the morning and evening conditions.

The expression without parentheses is also equivalent:

```cpp
hour >= 8 && hour < 10 || hour >= 17 && hour < 20
```

This is because `&&` has higher precedence than `||`. However, the parenthesized expression is easier to read and understand.

## 3. Surcharge Expression

The peak-hour surcharge is 20%.

```cpp
if (isPeak)
{
    fare += (fare * 20) / 100;
}
```

Explanation:

- Multiplication is performed before division.
- The percentage is calculated using `(fare * 20) / 100`.
- The `+=` operator adds the surcharge to the original fare.
- The surcharge is applied only during peak hours.

Example:

Base fare = Rs. 30

Surcharge = (30 * 20) / 100 = Rs. 6

Final fare = Rs. 36

## 4. Concession Expression

The concession percentage is not specified in the assignment. Therefore, it is represented using a variable.

```cpp
if (isEligible)
{
    fare -= (fare * concessionPercent) / 100;
}
```

Explanation:

- `isEligible` checks passenger eligibility.
- The concession amount is calculated using multiplication and division.
- The `-=` operator deducts the concession from the fare.

## 5. Conditional Operator

The conditional operator is represented by `?:`.

Example:

```cpp
int finalFare = isPeak ? fare + (fare * 20) / 100 : fare;
```

If the condition is true, the surcharge is added. Otherwise, the original fare is retained.

The conditional operator has lower precedence than arithmetic and relational operators and has right-to-left associativity.

## 6. Compound Assignment

Example:

```cpp
balance += fare;
```

This is equivalent to:

```cpp
balance = balance + fare;
```

Compound assignment operators include `+=`, `-=`, `*=`, and `/=`.

Assignment operators have right-to-left associativity.

## 7. Difference Between x++ and ++x

- `x++` is post-increment. It uses the original value and then increments it.
- `++x` is pre-increment. It increments the value first and then uses it.

Example:

```cpp
int x = 5;
cout << x++ << endl;
cout << ++x << endl;
```

Output:

```text
5
7
```

### Why is i = i++ a mistake?

In C++11, `i = i++` causes undefined behavior because the variable is modified without the required sequencing between the modifications.

It should be avoided.

Use `i++` or `i = i + 1` instead.

## 8. Division and Modulus With Negative Operands

C++ integer division truncates the result toward zero.

| Expression | Result |
|---|---:|
| 10 / 3 | 3 |
| 10 % 3 | 1 |
| -10 / 3 | -3 |
| -10 % 3 | -1 |

The remainder has the sign of the dividend when the remainder is non-zero.

Example:

-10 = (-3 * 3) + (-1)

Therefore, -10 % 3 = -1.

## 9. Program Output Prediction

The following output is predicted before executing the supplied program.

```text
11 16
9 6 4
6 4
3 1 -3 -1
18
```

### Explanation of Each Line

**Line 1:**
- Multiplication has higher precedence than addition.
- 5 + 3 * 2 = 11.
- Parentheses are evaluated first in (5 + 3) * 2 = 16.

**Line 2:**
- x++ uses the original value 5 and then increments x to 6.
- ++y increments y from 3 to 4 before using it.
- z = 5 + 4 = 9.
- Output: 9 6 4.

**Line 3:**
- x > y is true because 6 > 4.
- The conditional operator selects x, giving 6.
- x % 4 * 2 is evaluated from left to right because % and * have equal precedence.
- 6 % 4 * 2 = 2 * 2 = 4.

**Line 4:**
- 10 / 3 = 3.
- 10 % 3 = 1.
- -10 / 3 = -3.
- -10 % 3 = -1.
- Integer division truncates toward zero.

**Line 5:**
The loop uses i values 0, 3, 6, and 9.

k = 0 + 3 + 6 + 9 = 18.

## 10. Operator Precedence and Associativity

| Operators | Associativity |
|---|---|
| Postfix increment x++ | Left to right |
| Prefix increment ++x | Right to left |
| *, /, % | Left to right |
| +, - | Left to right |
| Relational operators | Left to right |
| && | Left to right |
| || | Left to right |
| ?: | Right to left |
| =, +=, -= | Right to left |

Precedence determines which operator is grouped first. Associativity determines the grouping direction when operators have equal precedence.

## 11. Alternative Concept – Boolean Lookup Table

Instead of using a combined logical expression, a Boolean lookup table can be used.

```cpp
bool peak[24] = {};

peak[8] = true;
peak[9] = true;
peak[17] = true;
peak[18] = true;
peak[19] = true;

bool isPeak = peak[hour];
```

The table stores the peak-hour status for all 24 hours.

### Complexity Analysis

| Method | Time Complexity | Extra Space |
|---|---|---|
| Logical expression | O(1) | O(1) |
| Boolean lookup table | O(1) | 24 Boolean entries |

Assuming one byte per Boolean value, the lookup table requires 24 bytes.

Both methods have constant-time checking. The lookup table uses an array index, while the logical expression evaluates relational and logical operators.

## 12. Result

Thus, the task demonstrates correct C++ expressions, operator precedence, associativity, conditional and compound assignment operators, increment and decrement operations, negative integer division and modulus, output prediction, and alternative peak-hour checking using a Boolean lookup table.
