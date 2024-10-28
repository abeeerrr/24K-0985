/* Name/Roll Number: Abeer Fatima (24K-0985)
Q1: 1. Write a C program to generate the following pattern:
1
1 2
1 2 3
1 2 3 4
*/

#include <stdio.h>
int main() {
int i;
int j;

 for (i = 1; i <= 5; i++) {
             for (j = 1; j <= i; j++) { 
printf("%d", j);
}
printf("\n");
}
return 0;
}