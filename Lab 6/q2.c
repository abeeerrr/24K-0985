/*
Q2:Write a program to check whether a given number is a multiple digit number or not.

1. Example: 123 is a multiple digit number.
2. 6 is not a multiple digit number.
*/

#include <stdio.h>
int main() {
int num;
printf("take any number\n");
scanf("%d",&num);

for (;(num<10 && num>=0) || (num>-10 && num<0);) {
printf("number is single digit number\n");

return 0;

}
 printf("the number is multiple digit number\n");

return 0;
}