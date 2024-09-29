/* Name/Roll Number: 24K-0985, Abeer Fatima
Q3: 1. Write a program that checks if a number is divisible by both 3 and 5 using logical operators.
*/

#include <stdio.h>
int main() {
	int num1;
	printf("take any number\n");
	scanf("%d",&num1);
	
	if(num1%3==0 && num1%5==0){
		printf("the number is divisible by both 3 and 5\n");
	}
	else{
		printf("error! number is not divisible by 3 and 5\n");
	}
	
	return 0;
	
}