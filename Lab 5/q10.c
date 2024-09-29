/* Name/Roll Number: Abeer Fatima/24K-0985
Q10: Create a program that calculates the sum of digits of a number until the result is a single digit
(e.g., 123 -> 6).
*/

#include <stdio.h>
int main() {
    int num, sum = 0, lastDigit;
    
    printf("Enter any number: ");
    scanf("%d", &num);
    
    while (num != 0) {
        lastDigit = num % 10;
        sum = sum + lastDigit;
        num = num / 10;
    }
    
    printf("Sum of digits: %d\n", sum);
    
    return 0;
}
