 # Task 1 – OOP Problem Analysis

## 1. Problem Description
The City Metro Smart-Card System is designed to manage passenger journeys and calculate metro fares based on the zones travelled. Passengers use a stored-value smart card to pay for their journeys. The system checks the card balance, calculates the fare, applies peak-hour surcharges and passenger concessions where applicable, and deducts the fare if sufficient balance remains.

The system is designed using Object-Oriented Programming (OOP) to organize data and operations into separate classes.

## 2. Identification of Objects
The main objects identified in the system are:

1. **SmartCard:** Stores the card number and available balance.
2. **Passenger:** Stores passenger details and passenger category.
3. **Journey:** Stores journey details, including source zone, destination zone and travel time.
4. **Zone:** Represents the metro zones and their base fares.
5. **FareTable:** Maintains fare information and calculates the applicable fare.

## 3. Attributes and Behaviours

### A. SmartCard
**Attributes:**

- Card ID
- Available balance
- Minimum required remaining balance

**Methods:**

- checkBalance()
- rechargeCard()
- deductFare()
- validateBalance()

### B. Passenger
**Attributes:**

- Passenger ID
- Passenger name
- Passenger category

**Methods:**

- registerPassenger()
- viewPassengerDetails()
- identifyPassengerCategory()

### C. Journey
**Attributes:**

- Journey ID
- Source zone
- Destination zone
- Journey date
- Journey time

**Methods:**

- startJourney()
- endJourney()
- calculateJourneyDuration()

### D. Zone
**Attributes:**

- Zone ID
- Zone name
- Base fare

**Methods:**

- getZoneDetails()
- getBaseFare()

### E. FareTable
**Attributes:**

- Base fare details
- Peak-hour surcharge percentage
- Passenger concession rules

**Methods:**

- calculateBaseFare()
- applyPeakSurcharge()
- applyConcession()
- calculateFinalFare()

## 4. Application of OOP Principles

### Encapsulation
Encapsulation protects important data such as the smart-card balance by keeping it private and allowing access through public methods.

### Abstraction
Abstraction hides internal fare calculation details and provides simple operations such as calculateFare() to the user.

### Inheritance
Inheritance can be used to create different passenger categories, such as StudentPassenger and SeniorPassenger, from a common Passenger class when their behaviour requires specialization.

### Polymorphism
Polymorphism allows different passenger categories to implement their own concession calculation through an overridden method.

## 5. System Constraints and Validation

- The smart card must have sufficient balance before a journey is approved.
- At least ₹50 must remain after fare deduction.
- Peak-hour surcharge is 20% during 8–10 AM and 5–8 PM.
- Inner Zone fare is ₹10.
- Middle Zone fare is ₹20.
- Outer Zone fare is ₹30.
- Student and senior concessions must follow the concession percentage specified or approved by the assignment.
- Fare calculations should use accurate monetary representation, preferably integer paise.

## 6. Conclusion
The Object-Oriented Programming approach provides a structured and modular design for the City Metro Smart-Card System. By dividing the system into classes such as SmartCard, Passenger, Journey, Zone and FareTable, the system becomes easier to understand, maintain, test and extend.
