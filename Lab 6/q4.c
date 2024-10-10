/*Name/Roll Number: Abeer Fatima (24K-0985)
Q4: Write a program to print the following series: 1, 2, 3, 5, 8, 13.

*/

#include <stdio.h>

int main() {
    int num1=1, num2=2, nextTerm=0;
    int terms = 6; 
    int i;


    printf("%d\n",num1);
    printf("%d\n",num2);


    for (i = 3; i<=terms; i=i+1) {
        nextTerm = num1 + num2;
        num1 = num2;
        num2 = nextTerm;
        printf("%d\n", nextTerm);
    }

    return 0;
}