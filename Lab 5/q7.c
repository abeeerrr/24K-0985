/* Name/Roll Number: Abeer Fatima/24K-0985
Q7: Write a program to swap two numbers using bitwise XOR.
*/

#include <stdio.h>
int main() {
	
	int a, b;
	printf("take any two numbers\n");
	scanf("%d %d",&a, &b);
	
    printf("Before swapping: a=%d, b=%d\n", a, b);
	
	 a = a ^ b;  
     b = a ^ b;  
     a = a ^ b;  
     
     printf("After swapping: a=%d, b=%d\n", a, b);
     
     return 0;
     
}