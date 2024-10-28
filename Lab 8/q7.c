/* Name/Roll Number: Abeer Fatima (24K-0985)

Q7: Write a C program to multiply two matrices of size 3x3 and display the result matrix.

*/

#include <stdio.h>

  int main() {
    int mat1[3][3], mat2[3][3], product[3][3];
    int i;
    int j;
    int k;

    printf("Enter elements of the first 3x3 matrix: \n");
    for (i = 0 ; i < 3 ; i++) {
      for (j = 0 ; j < 3 ; j++) {
            printf("Enter element at [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter elements of the second 3x3 matrix: \n");
    for (i = 0 ; i < 3 ; i++) {
       for (j = 0 ; j < 3 ; j++) {
            printf("Enter element at [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &mat2[i][j]);
        }
    }

    for (i = 0 ; i < 3 ; i++) {
        for (j = 0 ; j < 3 ; j++) {
            product[i][j] = 0;
        }
    }

    for (i = 0 ; i < 3 ; i++) {
        for (j = 0 ; j < 3 ; j++) {
            for (k = 0 ; k < 3 ; k++) {
                product[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("The product of the two matrices is: \n");
    for (i = 0 ; i < 3 ; i++) {
        for (j = 0 ; j < 3 ; j++) {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }

    return 0;
}