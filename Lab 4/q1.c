/*Name: Abeer Fatima (24K-0985)
 *File: q1.c
  Task 1: Write a C program to check whether a number is a mutliple of 3 or not.
 */

#include <stdio.h>
 int main(){
   int x;
	printf("take any number\n");
	scanf("%d", &x);
	
	if(x%3==0){
	  printf("x is a multiple of 3\n");
			  }
	else {
		printf("x is not a multiple of 3\n");
	}	 
		return 0;
			}