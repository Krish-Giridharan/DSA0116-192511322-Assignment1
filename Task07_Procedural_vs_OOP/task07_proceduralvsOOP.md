
# TASK 7 - FROM PROCEDURAL TO OBJECT-ORIENTED

## 1. Aim
To implement metro fare deduction using procedural and object-oriented programming and compare their advantages.

## 2. Description
The smart-card system maintains a balance and deducts the journey fare only when sufficient balance is available. At least Rs. 50 must remain after every successful journey.

## 3. Procedural Programming
The procedural approach uses separate variables and free functions.

- Balance is stored in a normal variable.
- canTravel() checks whether the journey is allowed.
- deduct() deducts the fare when sufficient balance is available.
- Functions operate on data passed to them.

## 4. Object-Oriented Programming
The object-oriented approach uses a SmartCard class.

- Balance is stored as a private data member.
- Constructor initializes the balance.
- canTravel() checks the minimum balance condition.
- deduct() deducts the fare only when the journey is allowed.
- displayBalance() displays the current balance.

## 5. Expected Output

Initial Balance: Rs. 100
Fare deducted successfully.
Remaining Balance: Rs. 90
Fare deducted successfully.
Remaining Balance: Rs. 54
Travel denied (low balance).
Remaining Balance: Rs. 54

## 6. Comparison

| Feature | Procedural | Object-Oriented |
|---|---|---|
| Structure | Functions and variables | Classes and objects |
| Data protection | Less protection | Encapsulation |
| Reusability | Function-based | Class-based |
| Maintenance | Can become difficult in large programs | Easier to organize |
| Balance access | Direct access is possible | Private balance |

## 7. How the Class Prevents Invalid Deduction
The canTravel() method checks whether the fare is valid, whether the balance is sufficient and whether at least Rs. 50 remains after deduction.

The deduct() method changes the balance only when all conditions are satisfied. This prevents the balance from falling below the required minimum through the class interface.

## 8. Changing the Minimum Balance
The minimum balance is maintained in one constant inside the SmartCard class. If the minimum balance changes, its value can be updated in one place.

## 9. Alternative Public Data Member
If balance is declared public, any part of the program with access to the object can directly modify it. This can bypass the fare deduction checks and allow the balance to fall below Rs. 50 or become negative.

## 10. Complexity Analysis
Both private and public balance designs require O(1) time for balance checking and deduction and O(1) space per card.

There is no change in time or space complexity. The main difference is data protection and control.

## 11. Conclusion
Both procedural and object-oriented programs successfully calculate and deduct metro fares. However, the object-oriented approach is preferable because encapsulation protects the smart-card balance and ensures that fare deductions follow the minimum-balance rule.
