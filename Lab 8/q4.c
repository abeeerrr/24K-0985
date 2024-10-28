/* Name/Roll Number: Abeer Fatima (24K-0985)

Q4: Write a C program that generates a sequence of prime numbers within a given range using
nested loops.

*/

#include <stdio.h>

int main() {
    int lower; 
	int upper;
	int i;
	int j;
	int isPrime;

    printf("take a lower and upper range: ");
    scanf("%d%d", &lower, &upper);

    printf("Prime numbers between %d and %d are: \n", lower, upper);

    for (i = lower; i <= upper; i++) {
        if (i < 2) continue; 
        isPrime = 1; 

        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = 0; 
                break;
            }
        }

        if (isPrime) {
            printf("%d ", i);
        }
    }

    return 0;
}