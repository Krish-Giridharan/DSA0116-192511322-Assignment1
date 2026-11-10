
# TASK 3 – DATA TYPES AND COMPATIBILITY

## 1. Aim

To understand different C++ data types and their compatibility by using passenger and smart-card information in the City Metro Smart-Card System.

## 2. Description

The metro smart-card system stores different types of passenger information. Different data types are used depending on the nature of the information.

The program accepts passenger details such as Passenger ID, Age, Card Balance, Passenger Category, and Student Status from the user.

## 3. Data Types Used

| Data Type | Variable | Purpose |
|---|---|---|
| string | passengerID | Stores passenger ID |
| int | passengerAge | Stores passenger age |
| double | cardBalance | Stores card balance |
| char | passengerCategory | Stores passenger category |
| bool | isStudent | Stores student status |

## 4. Data Type Compatibility

Data type compatibility refers to using suitable data types for storing and processing different kinds of values.

Examples:

- int is used for whole numbers.
- double is used for decimal numbers.
- char is used for a single character.
- bool is used for true or false values.
- string is used for text and identification values.

Selecting appropriate data types helps prevent incorrect storage and unnecessary data conversion.

## 5. Program Input

The program accepts the following information from the user:

- Passenger ID: 192511322
- Passenger Age: 21
- Card Balance: 150.50
- Passenger Category: S
- Student Status: 1

## 6. Expected Output

```text
--- Smart Card Details ---
Passenger ID: 192511322
Passenger Age: 21
Card Balance: Rs. 150.5
Passenger Category: S
Student Status: true
```

## 7. Explanation

1. The program declares variables using different C++ data types.
2. The string data type stores the passenger ID.
3. The int data type stores the passenger age.
4. The double data type stores the card balance.
5. The char data type stores the passenger category.
6. The bool data type stores the student status.
7. The cin statement accepts information from the user.
8. The cout statement displays the entered information.
9. The boolalpha manipulator displays Boolean values as true or false.

## 8. Result

Thus, the program successfully demonstrates the use of different C++ data types and their compatibility in the City Metro Smart-Card System.
