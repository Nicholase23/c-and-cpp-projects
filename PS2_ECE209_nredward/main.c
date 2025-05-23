/*
 * Edwards, Nicholas
 * ECE 209
 * 405
 * Problem Session 2
 */

// Problem Session 2 - Part 1
// Part 1
#include <stdio.h>
#define BASEPAY         10      // $10 per hour
#define BASEHRS         40      // hours at basepay
#define OVERTIME        1.5     // 1.5 time
#define AMT1            300     // 1st rate tier
#define AMT2            150     // 2nd rate tier
#define RATE1           0.15    // rate for 1st tier
#define RATE2           0.20    // rate for 2nd tier
#define RATE3           0.25    // rate for 3rd tier

int main() {

    double hours, gross, net, taxes;

    printf("Enter the number of hours worked this week: ");

    scanf("%lf", &hours);

    //gross pay = hours * base
    //OVR time = gross + (hours - 40)*1.5*base
    //Net Pay = gross - gross * tax

    if (hours <= 40) {
        gross = hours * BASEPAY;
    }
    else {
        gross = (BASEHRS * BASEPAY) + (hours - 40) * OVERTIME * BASEPAY;
    }

    if (gross <= AMT1) {
        taxes = gross * RATE1;
        net = gross - taxes;
    }
    else if (gross <= (AMT1 + AMT2)) {
        taxes = (gross - AMT1) * RATE2 + (AMT1 * RATE1);
        net = gross - taxes;
    }
    else {
        taxes = (gross - (AMT1 + AMT2)) * RATE3 + (AMT2 * RATE2) + (AMT1 * RATE1);
        net = gross - taxes;
    }

    printf("gross: $%.2f; taxes: $%.2f; net: $%.2f\n", gross, taxes, net);

    return 0;
}
