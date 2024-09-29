/* Name/Roll Number: Abeer Fatima/24K-0985
Q8: Create a program that counts the number of 1s in the binary representation of a number.
*/

#include <stdio.h>
int main() {
	int num, ones;
	
	printf("take your number\n");
	scanf("%d", &num);
	
	ones=0;
	
	while (num>0) {
		if (num&1) {
			ones=ones+1;
		}
		num=num>>1;
	}
	printf("the number of ones in your number: %d\n", ones);
	
	return 0;
	
	       }
	
	