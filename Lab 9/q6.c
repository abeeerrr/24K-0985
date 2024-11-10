/* Name/Roll Number: Abeer Fatima (24K-095)
q6: Create a C program that swaps the values of two integers using a user-defined function,
swapIntegers. The user inputs two integer values, and the program uses the function to swap
them. It should perform the swap and display the updated values.
*/

#include <stdio.h>

 void swapValues(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1, num2;

    printf("Enter two integers: ");
    scanf("%d%d", &num1, &num2);

    printf("Before swapping values: num1 = %d, num2 = %d\n", num1, num2);
    swapValues(&num1, &num2);
    printf("After swapping values: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}
