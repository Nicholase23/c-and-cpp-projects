# Loan Payment and Balance Calculator

**Author:** Nicholas Edwards  
**Course:** ECE 209 – Introduction to Computer Systems  
**Section:** 405  
**Assignment:** Programming Assignment 3

This C program helps users calculate:
- The **periodic payment** required to pay off a loan.
- The **unpaid balance** remaining after a given number of payments.

It uses standard amortization formulas and prompts the user for:
- Loan amount
- Annual interest rate (as a percentage)
- Number of payments per year
- Loan term in years
- Number of payments made

The program repeats as long as the user wants to calculate more loan scenarios.

## How to Compile and Run

```bash
gcc -o loan_calculator main.c -lm
./loan_calculator
````

> The `-lm` flag links the math library needed for calculations.

## Example Use

```
Enter (Y/y) to find the periodic payment and unpaid balance after certain payments: y
Enter the loan amount: 10000
Enter the interest rate per year as a percentage: 5
Enter the number of payments per year: 12
Enter the number of years for the loan: 5
The periodic payment is: $188.71
Enter the number of payments made: 12
The unpaid balance after 12 payment(s) is: $8966.25
```
