/* Name/Roll Number: Abeer Fatima (24K-095)
q7: Implement a function that checks if a given integer is a prime number. Use this function in the
main program to check if numbers entered by the user are prime.
*/

#include <stdio.h>

int prime(int n) {
    if (n <= 1) {
        return 0; 
    }
    for (int i = 2; i * i <= n; i++) { 
        if (n % i == 0) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    int num;

    printf("take a number: ");
    scanf("%d", &num);

    if (prime(num)) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }

    return 0;
}

