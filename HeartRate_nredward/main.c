/*
 Edwards, Nicholas
 Program 1 - Heart-Rate
 Lab section: 405
*/
#include <stdio.h>
/*function main begins program execution*/
int main ( void )
{
    int age;
    int month;
    int day;
    int year;

    int currentMonth;
    int currentDay;
    int currentYear;

    float maxHeartRate;
    float maxTargetRate;
    float minTargetRate;

    printf( "Please enter month, day, and year of birth separated by spaces" );
    printf( " (use numbers):\n" );

    //Create a program that reads the user’s birthday and the current day (each consisting of the month, day and year).
    scanf("%d %d %d", &month, &day, &year);

    /* today's date */
    printf( "Please enter today's month, day, and year separated by spaces" );
    printf( " (use numbers):\n" );

    scanf("%d %d %d", &currentMonth, &currentDay, &currentYear);

    printf("Date of Birth: %d/%d/%d\n", month, day, year);

    //Calculate and display the person’s age (in years), the person’s maximum heart rate and the person’s target-heart-rate range.
    if (currentMonth == month && currentDay == day)
        printf("Age: %d\n", age = currentYear - year);
    else
        printf("Age: %d\n", age = currentYear - year - 1);

    maxHeartRate = 220 - age;

    maxTargetRate = .85 * maxHeartRate;
    minTargetRate = .50 * maxHeartRate;

    printf("Maximum Heart Rate: %.2f\n", maxHeartRate);

    printf("Target Heart Rate Range: %.2f - %.2f", minTargetRate, maxTargetRate);

    return 0;
}
