/*
 Edwards, Nicholas
 Programming Assignment 3
 Section 405
*/

#include <stdio.h>
#include <math.h>

double periodicPayment(double L, double r, int m, int t);
double unpaidBalance(double R, double r, int m, int t, int k);

int main()
{
    double loanAmount;
    double interestRate;
    int numOfPayPerYear;
    int loanYears;
    int numOfPaymentsMade;
    char response;
    printf( "Enter (Y/y) to find the periodic payment and unpaid ");
    printf( "balance after certain payments: ");
    scanf( " %c", &response );
    while (response == 'Y' || response == 'y')
    {
        printf( "\nEnter the loan amount: ");
        scanf( "%lf", &loanAmount );
        printf( "Loan amount $%.2f\n", loanAmount );

        printf( "\nEnter the interest rate per year as a percentage: ");
        scanf( "%lf", &interestRate );
        printf( "interest rate per year as a percentage %.2f\n",
                interestRate );

        printf( "\nEnter the number of payments per year: ");
        scanf( "%d", &numOfPayPerYear );
        printf( "The number of payments per year %d\n", numOfPayPerYear );

        printf( "\nEnter the number of years for the loan: ");
        scanf( "%d", & loanYears );
        printf( "The number of years for the loan: is %d\n", loanYears );

        printf("The periodic payment is: $%.2lf", periodicPayment(loanAmount,interestRate,numOfPayPerYear,loanYears));

        printf( "\nEnter the number of payments made: ");
        scanf( "%d", & numOfPaymentsMade );

        printf("The unpaid balance after %d payment(s) is: $%.2lf\n", numOfPaymentsMade, unpaidBalance(periodicPayment(loanAmount,interestRate,numOfPayPerYear,loanYears), interestRate, numOfPayPerYear, loanYears, numOfPaymentsMade));

        printf( "\nEnter (Y/y) to find the periodic payment and unpaid ");
        printf( "balance after certain payments: ");

        scanf( " %c", &response );
    }
    return 0;
}

double periodicPayment(double L, double r, int m, int t) {
    return (L * (r / m / 100)) / (1 - pow(1 + (r / m / 100),(-m * t)));
}
double unpaidBalance(double R, double r, int m, int t, int k) {
    return (R * ((1 - pow(1 + (r / m / 100), -((m * t) - k)))/(r / m / 100)));
}