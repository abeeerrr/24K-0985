/* Name/Roll Number: Abeer Fatima (24K-095)
q8: Write a C program with a user-defined function calculate to perform basic arithmetic operations
such as addition, subtraction, multiplication, and division. The program should take two
numbers and an operation choice as input, and then use the function to perform the operation.
*/

#include <stdio.h>

 float calculate(float num1, float num2, char operator) {
    switch (operator) {
        case '+':
            return num1+num2;
        case '-':
            return num1-num2;
        case '*':
            return num1*num2;
        case '/':
            if (num2 != 0) {
                return num1/num2;
            } 
			else {
                printf("Error! Division by zero is not allowed.\n");
                return 0; 
            }
        default:
            printf("Error! Invalid operator.\n");
            return 0; 
    }
}

int main() {
    float num1, num2, result;
    char operator;

    printf("take first number: ");
    scanf("%f", &num1);
    printf("take second number: ");
    scanf("%f", &num2);
    printf("take an operator: ");
    scanf(" %c", &operator); 

    
    result = calculate(num1, num2, operator);


    if (operator == '/' && num2 == 0) {
        
    } else {
        printf("Result: %f\n", result);
    }

    return 0;
}
