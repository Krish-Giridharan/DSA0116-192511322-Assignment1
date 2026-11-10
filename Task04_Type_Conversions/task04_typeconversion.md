
# TASK 4 – IMPLICIT TYPE CONVERSIONS

## 1. Aim

To understand implicit type conversion in C++ and observe how values are automatically converted from one data type to another.

## 2. Description

Implicit type conversion occurs when the C++ compiler automatically converts a value from one data type to another during program execution.

It is commonly used in arithmetic operations, character conversions, Boolean assignments, and comparisons.

## 3. Types of Conversions Demonstrated

### A. Integer to Double

An integer is automatically converted into a double when used in an arithmetic expression involving a decimal value.

Example:
```cpp
int wholeNumber = 3;
double decimalNumber = wholeNumber + 0.5;
```

Result: 3.5

### B. Character to Integer

A character can be automatically converted into its corresponding character-code value.

Example:
```cpp
char letter = 'C';
int asciiValue = letter;
```

Result: 67

### C. Integer to Boolean

An integer value can be automatically converted into a Boolean value.

- Zero becomes false.
- Any non-zero value becomes true.

Example:
```cpp
int number = 1;
bool status = number;
```

Result: true

### D. Character Comparison

Characters can be compared using relational operators such as >=.

Example:
```cpp
char firstCharacter = 's';
char secondCharacter = 'u';

bool comparison = (firstCharacter >= secondCharacter);
```

Result: false

## 4. Expected Output

```text
3 3.5
C 67
1 true
s >= u : false
```

## 5. Explanation

1. An integer value is automatically converted into a double during arithmetic operations.
2. A character is converted into its corresponding integer character-code value.
3. A non-zero integer is converted into true when assigned to a Boolean variable.
4. Characters are compared using their character-code values.
5. The boolalpha manipulator displays Boolean values as true or false.

## 6. Result

Thus, the program successfully demonstrates implicit type conversions in C++, including integer-to-double, character-to-integer, integer-to-Boolean conversions, and character comparison.
