
# TASK 11 – Recommend and Defend the Final Design

## 1. Aim
To recommend a reliable and scalable design for the City Metro Smart-Card System based on the results of previous implementation and testing tasks.

## 2. Recommended Data Types and Classes

| Component | Recommended Type |
|---|---|
| Passenger ID | string |
| Passenger age | int |
| Card balance | long long |
| Fare | long long |
| Peak-hour status | bool |
| Zone | enum class |
| Minimum balance | const long long |
| Smart card | SmartCard class |
| Fare table | Array of long long |

Integer paise is recommended for accurate monetary calculations. The SmartCard class uses private data members to protect the card balance.

## 3. Fare Revision

The fare table is stored in a configuration file named fare_config.txt.

Example:

1000
2000
3000

The values represent Inner, Middle and Outer Zone fares in paise.

When fares change, the administrator updates the configuration file. The system loads the new fares when it restarts. Recompilation is not required.

## 4. Limitations

1. Configuration files require validation.
2. All metro gates need consistent fare updates.
3. Authentication and authorization are not implemented.
4. Database and transaction management are not included.
5. Concession percentages need to be defined.
6. Real-time network performance requires further testing.

## 5. Whole Network Correctness

Previous experiments demonstrated:
- Correct peak-hour boundary handling.
- Minimum balance protection through the SmartCard class.
- Safe input validation.
- Successful testing of 15 fare test cases.
- Accurate integer-paise calculations for different journey counts.
- The need for long long because 32-bit int cannot hold the largest network total.

The system is correct for the tested fare rules, but full network scalability requires further performance and integration testing.

## 6. Complexity Analysis

Let z represent the number of zones.

- Loading z fares: O(z).
- Accessing a loaded fare: O(1).
- Fare table storage: O(z).
- Configuration-file storage: O(z) for fixed-size fare entries.

A configuration file makes fare revisions easier because the program does not need to be recompiled for each change.

## 7. Final Recommendation

The recommended design uses C++11, integer paise, long long, enum class, constants, and a SmartCard class with private balance management.

Fare values should be loaded from a validated configuration file. This improves accuracy, maintainability and flexibility when fare rates change.

## 8. Result

A technically justified final design was recommended using the results of previous experiments. The configuration-file approach provides easier fare revisions, while integer-paise calculations and long long improve monetary accuracy and large-network reliability.
