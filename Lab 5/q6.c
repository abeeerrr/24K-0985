/* Name/Roll Number: Abeer Fatima/24K-0985
Q6: Use the ternary operator to check if a number is positive, negative, or zero.
*/

#include <stdio.h>
int main() {
	int num;
	printf("take any number\n");
	scanf("%d",&num);
	
	(num > 0) ? printf("The number is positive.\n") : (num < 0) ? printf("The number is negative.\n") : printf("The number is zero.\n");
	
	return 0;
}