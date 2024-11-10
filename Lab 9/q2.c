/* Name/Roll Number: Abeer Fatima (24K-095)
q2: Write a function that checks if a given number is even or odd.
*/

#include <stdio.h>

int evenOrOdd(int num) {
	if(num%2==0) {
		printf("it is even");
	}
	else{
		printf("it is odd");
	}
	}
	
	int main() {
	   int num;
	   
    printf("take a number: ");
    scanf("%d", &num);

    evenOrOdd(num);

    return 0;
}
	

