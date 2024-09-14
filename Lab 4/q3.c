/*Name: Abeer Fatima (24K-0985)
 *File: q1.c
  Task 3: Write a C program to input a character from the user and check whether the given character is a small alphabet,
  capital alphabet, digit or special character, using if else.
 */
 
#include <stdio.h>
 int main(){
 char givenCharacter;
 
 printf("enter the given character\n");
 scanf("%c", &givenCharacter);
 
   if(givenCharacter>='a' && givenCharacter<='z'){
    printf("givenCharacter is a small alphabet\n");
	}
	else if(givenCharacter>='A' && givenCharacter<='Z') {
	 printf("givenCharacter is capital alphabet\n");
	 }
	 else if(givenCharacter>='0' && givenCharacter<='9') {
	  printf("givenCharacter is a digit\n");
	  }
	 else{
	  printf("givenCharacter is a special character\n");
	  }
	  
	  return 0;
	  }
 
 