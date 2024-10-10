/*Name/Roll Number: Abeer Fatima (24K-0985)
Q6: Create a C program to calculate the following series using loop statements.
1,2,2,4,8,32,256,8192,2097152


*/

#include <stdio.h>

int main() {
    int term;

    term = 1;
    printf("%d, ", term);


    term = 2;
    printf("%d, ", term);


    for (int i = 3; i <= 8; i=i+1) {
        if (i == 4) {
            term = 4;
        } 
		else if (i == 5) {
            term = 8; 
        } 
		else if (i == 6) {
            term = 32;
        } 
		else if (i == 7) {
            term = 256; 
        } 
		else if (i == 8) {
            term = 8192; 
        } 
		else if (i == 9) {
            term = 2097152; 
        }
        
        printf("%d", term);
        if (i < 8) {
            printf(", "); 
        }
    }

    printf("\n"); 

    return 0;
}
