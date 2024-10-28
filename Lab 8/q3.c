/* Name/Roll Number: Abeer Fatima (24K-0985)

Q3: Create a 3D array representing 2 pages of a 3x3 matrix. Initialize it and find the sum of all the
elements on each page.

*/
#include <stdio.h>

int main() {
    int array[2][3][3] = {
        {
            {10, 2, 5},
            {4, 45, 6},
            {7, 3, 1}
        },
        {
            {9, 8, 0},
            {8, 5, 4},
            {3, 6, 1}
        }
    };

    for (int page = 0; page < 2; page++) {
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                sum += array[page][i][j];
            }
        }
        printf("Sum of elements on page %d: %d\n", page + 1, sum);
    }

    return 0;
}