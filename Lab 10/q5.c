/*
Name/Roll Number: Abeer Fatima (24K-0985)

Q5: Write a recursive function that takes an array and its size as input and prints all the
elements.

*/
#include <stdio.h>

void printArray(int array[], int size) {
    if (size == 0) {
        return; 
    }

    printf("%d ", array[0]);

    
    printArray(array + 1, size - 1);
}

int main() {
    int array[] = {5, 6, 6, 5, 5};
    int size = sizeof(array) / sizeof(array[0]); 

    printf("Array elements are: ");
    printArray(array, size); 
    printf("\n");

    return 0;
}
