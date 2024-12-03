/* Name/Roll Number: Abeer Fatima (24K-0985)
q3: Write a program to dynamically allocate memory for an array of integers. Input the size
of the array and the elements from the user, then calculate and display the sum of the
elements. Free the allocated memory before the program ends.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int* array;
    int sum = 0;

    printf("take the size of the array: ");
    scanf("%d", &n);

    array = (int*)malloc(n*sizeof(int));
    if (array==NULL) {
        printf("Error! Dynamic memory allocation has failed!\n");
        return 1;
    }

    printf("rake %d integers:\n", n);
    for (int i=0; i< n; i++) {
        scanf("%d", &array[i]);
        sum += array[i]; 
    }

    printf("The sum of the elements is: %d\n", sum);

    
    free(array);

    return 0;
}
