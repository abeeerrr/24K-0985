/* Name/Roll Number: 24K-0985, Abeer Fatima
Q2:Create a program that determines if a number is positive, negative, or zero, and if it’s positive,
checks if it’s an even or odd number.
*/

#include <stdio.h>
int main(){
	int num1;
	printf("take any number\n");
	scanf("%d",&num1);
	
	if(num1==0) {
		printf("the number is 0\n");
	}
	else if(num1<0) {
		printf("the number is negative\n");
	}
	else if(num1>0) {
		if(num1%2==0){
			printf("the number is even\n");
		}
		else{
			printf("the number is odd\n");
		}
		}
	else{
		printf("invalid input!\n");
	}
	
	return 0;	
	}
	
	