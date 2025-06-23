# ECE 309 - Homework 3: Electronic Device and Television Classes

**Author:** Nicholas Edwards
**Course:** ECE 309 - Data Structures and Object-Oriented Programming for ECE (NC State University)

---

## Overview

This homework demonstrates basic principles of **object-oriented programming (OOP)** in C++ through the implementation of a simple class hierarchy involving electronic devices. The program defines a base class `ElectronicDevice` and a derived class `Television`, showcasing inheritance, encapsulation, and method overriding.

---

## Features

- **Base Class: ElectronicDevice**  
  - Stores common attributes like brand, model, and power state  
  - Methods to turn the device on and off  

- **Derived Class: Television**  
  - Extends `ElectronicDevice` by adding attributes specific to televisions such as screen size and resolution  
  - Method to display detailed information about the television including power state  

- **Demonstration in `main()`**  
  - Instantiates a `Television` object  
  - Turns the television on and off  
  - Displays information before and after power state changes

---

## Usage

Compile the program with a C++ compiler, for example:

```bash
g++ -o homework3 homework3.cpp
./homework3
````

---

## Expected Output

```
Television Information:
Brand: Samsung
Model: Smart TV
Power State: On
Screen Size: 55 inches
Resolution: 4K

Television Information:
Brand: Samsung
Model: Smart TV
Power State: Off
Screen Size: 55 inches
Resolution: 4K
```

---

## Implementation Details

* **Classes:**

  * `ElectronicDevice`: Base class with protected members and power control methods.
  * `Television`: Derived class adding specific properties and a method to display information.

* **Key Concepts:**

  * Inheritance
  * Method definition and use
  * Access specifiers (`protected`, `public`)

---

## Dependencies

* Standard C++ library
* Compatible with any standard C++ compiler (e.g., g++, clang++)

---

## Notes

* This homework is focused on practicing class design, inheritance, and simple I/O in C++.
* The current implementation uses fixed sample data for the television object.
