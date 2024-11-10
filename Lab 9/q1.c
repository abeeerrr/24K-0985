/* Name/Roll Number: Abeer Fatima (24K-095)
q1: Write a function in C program to calculate the product.
*/

#include <stdio.h>


int multiply(int a, int m) {
    return a*m;
}

int main() {
    int num1;
    int num2;
    int product;
    
    printf("take two numbers: ");
    scanf("%d%d", &num1, &num2);

    
    product = multiply(num1, num2);

    printf("The product is: %d\n", product);

    return 0;
}