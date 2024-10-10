/*Name/Roll Number: Abeer Fatima (24K-0985)
Q2: Write a program to check whether a given number is a multiple digit number or not.

1. Example: 123 is a multiple digit number.
2. 6 is not a multiple digit number.

*/

#include <stdio.h>
int main() {
	int num;
	
	printf("take any number\n");
	scanf("%d",&num);
	
	while (num!=0) {
		 if (num > 0 && num < 10) {
            printf("it is a single-digit number.\n");
        }
        
        else if (num >= 10) {
            printf("it is a multiple-digit number.\n");
        }
        
		
        
        printf("take any number\n");
	    scanf("%d",&num);
        
	}
	return 0;
		
	
}