/*Name/Roll Number: Abeer Fatima (24K-0985)
Q5: Using for-loop statement print the following series: 
65536, 32768, 10922, 2730, 546, 91, 13, 1, 0.

*/

#include <stdio.h>

int main() {
    int x, i, quotient;
    int y = 65536;


    printf("%d, ", y);

    for (x = 1, i = 2; x < 7; x=x+1, i=i+1) {
        quotient = y / i; 
        y = quotient; 
        
        
        printf("%d", quotient);
        
    
        if (x < 6) {
            printf(", ");
        }
    }

    
    printf(", 1, 0\n"); 

    return 0;
}