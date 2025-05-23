/*
 * Edwards, Nicholas
 * ECE 209
 * Sec 405
 * Programming Assignment 1
 *
 */
#include <stdio.h>
#include <math.h>

int main() {

    const float initial_hgt = 10.0;

    //Declare the rebound height (in meters)
    float rhgt01, rhgt02, rhgt03;

    // impact speed (in meters/second)
    float speed01, speed02, speed03, gravity;

    //Prompt user to input gravity
    printf("Enter the gravitational constant (Enter 9.81 for Earth and 1.67 for the moon).\n");
    scanf("%f", &gravity);

    //rebound height of each bounce
    rhgt01 = initial_hgt * 2 / 3;
    rhgt02 = rhgt01 * 2 / 3;
    rhgt03 = rhgt02 * 2 / 3;

    // impact speed of the first three bounces

    //printf("This code works until here");

    speed01 = sqrt(2.0 * gravity * initial_hgt);
    speed02 = sqrt(2.0 * gravity * rhgt01);
    speed03 = sqrt(2.0 * gravity * rhgt02);

    printf("The impact speed of bounce 1 is %f m/s.\nThe rebound height after bounce 1 is %f m.\n", speed01, rhgt01);
    printf("The impact speed of bounce 2 is %f m/s.\nThe rebound height after bounce 2 is %f m.\n", speed02, rhgt02);
    printf("The impact speed of bounce 3 is %f m/s.\nThe rebound height after bounce 3 is %f m.\n", speed03, rhgt03);

    return 0;
}
