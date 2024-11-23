/*
Name/Roll Number: Abeer Fatima (24K-0985)

Q1: Write a recursive function that calculates the sum of digits of a number. For example, if
the input is 123, the output should be 6.

*/

#include <stdio.h>

int sumCalculator(int num) {
	
	if(num<=0) {
		return 0;
	}
	
	return num%10+sumCalculator(num/10);
}

int main() {
	
	int num;
	printf("enter a number\n");
	scanf("%d", &num);
	
	int sum=sumCalculator(num);
	
	printf("the sum of digits of %d is %d", num, sum);
	
	return 0;
}