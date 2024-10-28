/* Name/Roll Number: Abeer Fatima (24K-0985)

Q5: Generate a pattern of odd numbers in decreasing order starting from a user-specified number
using nested loops.

*/

#include <stdio.h>

int main() {
    int startingNumber;
    int i;
    int j;

    printf("take any odd number: \n");
    scanf("%d", &startingNumber);

 
    if (startingNumber%2==0) {
        printf("error! please enter an odd number!\n");
        return 1; 
    }

    
    for (i=startingNumber ; i>=1 ; i-=2) {
        
        for (j=i ; j>=1 ; j-=2) {
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}