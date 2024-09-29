/* Name/Roll Number: Abeer Fatima/24K-0985
Q5: Write a program using a ternary operator to find the maximum of two numbers.
*/

#include <stdio.h>
int main() {
	int num1, num2;
	printf("take any two numbers\n");
	scanf("&d&d",&num1, &num2);
	
	num1 >= num2 ? printf("num1 is greater than num2\n") : printf("num2 is greater than num1\n");
	
	return 0;
	
	}