/* Name/Roll Number: Abeer Fatima/24K-0985
Q9: Write a program that checks if a year is a leap year using the modulus operator.
*/

#include <stdio.h>
int main() {
	
	int year;
	printf("take any year\n");
	scanf("%d",&year);
	
    if ((year%4==0 && year%100!=0) || year%400==0) {
    	printf("it is a leap year\n");
	}
	else {
		printf("it is not a leap year\n");
	}
	
	return 0;
}
