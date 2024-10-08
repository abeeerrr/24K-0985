/*Name/Roll Number: Abeer Fatima (24K-0985)
Q1: Which loop system would be better for user input. Justify your answer by creating a program
that takes a value and adds it to a variable and prints it repeatedly until the user enters a zero
value.
*/

#include <stdio.h>
int main() {
int value;
int sum;
int i=0;

printf("take any value\n");
scanf("%d",&value);

while (value!=0) {
i=i+value;
printf("%d\n", value);
}

return 0;
}