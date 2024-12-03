/* Name/Roll Number: Abeer Fatima (24K-0985)
q2: Write a program to dynamically allocate memory for 2, 2D arrays of size m×n. Input the
dimensions m and n and the elements of the matrices, then find the multiplication in a
function by passing reference of the matrices.
*/

#include <stdio.h>
#include <stdlib.h>

void multiplyMatrices(int** mat1, int** mat2, int** result, int m, int n, int p) {
   
   
    for (int i =0; i<m; i++) {
        for (int j=0; j<p; j++) {
            result[i][j] = 0;
            for (int k=0; k<n; k++) {
                result[i][j] += mat1[i][k]*mat2[k][j];
            }
        }
    }
}

int main() {
    int m;
    int n;
    int p;

    printf("take the number of rows (m) of Matrix 1: ");
    scanf("%d", &m);
    printf("take the number of columns (n) of Matrix 1 (and rows of Matrix 2): ");
    scanf("%d", &n);
    printf("take the number of columns (p) of Matrix 2: ");
    scanf("%d", &p);

    
    int** mat1 = (int**)malloc(m*sizeof(int*));
    for (int i = 0; i < m; i++) {
        mat1[i] = (int*)malloc(n*sizeof(int));
    }

    int** mat2 = (int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++) {
        mat2[i] = (int*)malloc(p*sizeof(int));
    }

    int** result = (int**)malloc(m*sizeof(int*));
    for (int i = 0; i < m; i++) {
        result[i] = (int*)malloc(p*sizeof(int));
    }

    printf("Enter elements of Matrix 1 (%d*%d):\n", m, n);
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter elements of Matrix 2 (%d*%d):\n", n, p);
    for (int i=0; i<n; i++) {
        for (int j=0; j<p; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    multiplyMatrices(mat1, mat2, result, m, n, p);

    printf("The resulting matrix (%d*%d) after multiplication is: \n", m, p);
    for (int i=0; i<m; i++) {
        for (int j =0; j<p; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    for (int i=0; i<m; i++) free(mat1[i]);
    for (int i=0; i<n; i++) free(mat2[i]);
    for (int i=0; i<m; i++) free(result[i]);
    free(mat1);
    free(mat2);
    free(result);

    return 0;
}
