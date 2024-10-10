/*Name/Roll Number: Abeer Fatima (24K-0985)
Q1: Which loop system would be better for user input. Justify your answer by creating a program
that takes a value and adds it to a variable and prints it repeatedly until the user enters a zero
value.


ANS: 
  A while loop is better for user input. The reason is that the while loop will continue the loop until the condition is proven false.
   This is what the question requires as variable must be printed repeatedly until a zero value is entered.

*/

#include <stdio.h>
int main() {
	int value;
	int i=0;
	
	 printf("take any value: \n");
	 scanf("%d",&value);
	 
	 while (value!=0) {
	 
	 i=value+1;
	 printf("i is the value: %d\n", i);
	 
	  printf("Take any value: \n");
        scanf("%d", &value);
	 }
	 
	 return 0;
	 
	 
	 
	
	
}