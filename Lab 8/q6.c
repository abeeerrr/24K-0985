/* Name/Roll Number: Abeer Fatima (24K-0985)

Q6: Write a C program to find the saddle point(s) in a given 3x3 matrix. A saddle point is an element
that is the smallest in its row and the largest in its column.

*/

#include <stdio.h>

int main() {
    int matrix[3][3];
    int i, j, k;
    int saddle_point_found = 0;


    printf("Enter elements of the 3x3 matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Enter element at [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("The given matrix is:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++) {
        int row_min = matrix[i][0];
        int col_index = 0;

        for (j = 1; j < 3; j++) {
            if (matrix[i][j] < row_min) {
                row_min = matrix[i][j];
                col_index = j;
            }
        }

        int is_saddle_point = 1;
        for (k = 0; k < 3; k++) {
            if (matrix[k][col_index] > row_min) {
                is_saddle_point = 0;
                break;
            }
        }

        if (is_saddle_point) {
            printf("Saddle point found at [%d][%d]: %d\n", i + 1, col_index + 1, row_min);
            saddle_point_found = 1;
        }
    }

    if (!saddle_point_found) {
        printf("No saddle point found in the matrix.\n");
    }

    return 0;
}
