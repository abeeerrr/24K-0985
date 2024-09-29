/* Name/Roll Number: 24K-0985, Abeer Fatima
Q1: Write a program that categorizes a person's age into different life stages: Child, Teenager, Adult,
and Senior, using nested if-else statements.
*/

#include <stdio.h>
int main(){
 int age;
 printf("input any number\n");
 scanf("%d",&age);
 
 if(age<=12 && age>0) {
 	printf("the person is a child\n");
 }
 else if(age>=13 && age<20) {
 	printf("the person is a teenager\n");
 }
 else if(age<=60 && age>19) {
 	printf("the person is an adult\n");
 }
 else if(age>60) {
 	printf("the person is a senior\n");
 }
 
 return 0;
 
}
