/*
Name/Roll Number: Abeer Fatima (24K-0985)

Q11: Create a C program that defines a constant for the conversion factor of meters to
kilometers. Use a static variable in a function to count how many times the function is
called.

*/

#include <stdio.h>

#define METER_TO_KM_CONVERSION 0.001

struct Distance {
    double meters;
    double kilometers;
};

double convertMetersToKilometers(struct Distance *dist) {
    static int callCount = 0; 
    callCount++; 
    printf("Function called %d times.\n", callCount);
    
    if (dist->meters <= 0) {
        return 0;
    }
    
    dist->kilometers = dist->meters * METER_TO_KM_CONVERSION;
    
    dist->meters = 0; 
    return dist->kilometers; 
}

int main() {
    struct Distance dist; 
    double kilometers;

    printf("Enter the distance in meters: ");
    scanf("%lf", &dist.meters);

    kilometers = convertMetersToKilometers(&dist);

    printf("%.2f meters is equal to %.2f kilometers.\n", dist.meters, kilometers);

    return 0;
}
