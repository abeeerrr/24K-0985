/* Name/Roll Number: Abeer Fatima (24K-0985)

Q2: Write a program to take a 2D array input from the user and display its transpose.

*/

#include <stdio.h>
int main() {

    int mat[2][2] = {{5, 6}, {10, 12}};
    int transpose[2][2];

    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            transpose[j][i] = mat[i][j];
        }
    }


    printf("The transpose of the matrix is \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}