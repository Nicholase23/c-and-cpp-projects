# Bounce Impact Speed and Rebound Height Calculator

**Author:** Nicholas Edwards  
**Course:** ECE 209 – Introduction to Computer Systems  
**Section:** 405  
**Assignment:** Programming Assignment 1

---

## Description

This C program calculates the impact speeds and rebound heights of the first three bounces of a ball dropped from an initial height. The user inputs the gravitational constant (e.g., 9.81 for Earth, 1.67 for the Moon), and the program outputs:

- Impact speed for each bounce
- Rebound height after each bounce

The rebound height decreases by two-thirds with each bounce.

---

## Sample Input/Output

```

Enter the gravitational constant (Enter 9.81 for Earth and 1.67 for the moon).
9.81
The impact speed of bounce 1 is 14.007139 m/s.
The rebound height after bounce 1 is 6.666667 m.
The impact speed of bounce 2 is 11.447004 m/s.
The rebound height after bounce 2 is 4.444444 m.
The impact speed of bounce 3 is 9.339667 m/s.
The rebound height after bounce 3 is 2.962963 m.

````

---

## How to Compile and Run

```bash
gcc -o bounce_calculator bounce_calculator.c -lm
./bounce_calculator
````

> The `-lm` flag links the math library for the `sqrt` function.

---

## Notes

* Initial height is fixed at 10 meters.
* Rebound height after each bounce is two-thirds of the previous height.
* Impact speeds are calculated using the formula:
  `speed = sqrt(2 * gravity * height)`

---

Developed for **ECE 209**, Section 405, as Programming Assignment 1.
