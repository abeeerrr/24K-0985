/* Name/Roll Number: Abeer Fatima/24K-0985
Q11: Write a program to find the greatest of three numbers using nested if-else statements.
*/

#include <stdio.h>
int main() {
	int num1, num2, num3;
	printf("take any three numbers\n");
	scanf("%d %d %d",&num1, &num2, &num3);
	
	if (num1>num2 && num1>num3) {
		printf("num1 is greater than num2 and num3\n");
	}
	else if (num2>num1 && num2>num3) {
		printf("num2 is greater than num1 and num3\n");
	}
	else if (num3>num1 && num3>num2) {
		printf("num3 is greater than num1 and num2\n");
	}
	else{
		printf("invalid input!\n");
	}
	
	return 0;
}