# Hospital Management System Project

**Overview:**  
This project implements a simple Hospital Management System in C++ using Object-Oriented Programming (OOP) principles. The system allows for the registration of patients and doctors, assignment of doctors to patients based on specialization, and the creation of bills for treatments and room fees. 

**Knowledge Used:**  
- **Object-Oriented Programming (OOP):** Classes, Inheritance, and Polymorphism.
- **C++ Basics:** Arrays, Pointers, Functions, Conditionals, Loops.
- **String Manipulation:** `strcpy`, `strcmp`, handling character arrays.


**Start Date:** 30 Dec 2024  
**End Date:** 31 Dec 2024  
**Email:** chongkaiying578@gmail.com

## Classes:
1. **Person (Base Class)**: Holds common attributes for both Patient and Doctor (name, age, gender, address).
2. **Patient (Derived from Person)**: Includes illness, doctor assigned, and room number with registration functionality.
3. **Doctor (Derived from Person)**: Includes specialization and availability status with registration functionality.
4. **Hospital**: Manages multiple patients and doctors, assigning doctors to patients based on illness specialization.
5. **Bill**: Calculates and displays the total bill based on treatment and room costs.

## Functionality:
- **Patient Registration:** Add new patients with details like name, age, illness, etc.
- **Doctor Registration:** Add doctors with details like name, age, specialization.
- **Doctor-Patient Assignment:** Automatically assign available doctors to unassigned patients based on specialization.
- **Billing System:** Update and display treatment and room fees for patients.
