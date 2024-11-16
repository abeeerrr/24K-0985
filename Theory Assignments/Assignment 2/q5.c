/*Name/Roll Number: Abeer Fatima (24K-0985)
Q5: You are tasked with creating a program that generates a histogram based on user input. The user will
provide a set of values, and your program will use loops to create a visual representation of these values.
1. Input Handling: Write a function that takes an array of integers (the values) and the count of
those integers as input.
2. Horizontal Histogram Function: Use loops to generate and print a histogram, where each
value is represented by asterisks (*).
3. Vertical Histogram Function: Use loops to generate and print a vrtical histogram, where
each value is represented by asterisks (*).
Expected Values:
int values [] = {3, 5, 1, 4};
int count = 4;
Horizontal Histogram
Value 1: ***
Value 2: *****
Value 3: *
Value 4: ****
Vertical Histogram
*
* *
* * *
* * *
* * * *
3 5 1 4
*/

#include <stdio.h>

void printHorizontalHistogram(int values[], int count) {
    int i, j;
    printf("Horizontal Histogram:\n");
    for (i = 0; i < count; i++) {
        printf("Value %d: ", i + 1);
        for (j = 0; j < values[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printVerticalHistogram(int values[], int count) {
    printf("\nVertical Histogram:\n");

    int max = 0, i, j;
    for (i = 0; i < count; i++) {
        if (values[i] > max) {
            max = values[i];
        }
    }

    for (i = max; i > 0; i--) {
        for (j = 0; j < count; j++) {
            if (values[j] >= i) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    for (i = 0; i < count; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
}

int main() {
    int values[] = {3, 5, 1, 4};
    int count = 4;

    printHorizontalHistogram(values, count);
    printVerticalHistogram(values, count);

    return 0;
}

