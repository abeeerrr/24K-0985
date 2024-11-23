/*
Name/Roll Number: Abeer Fatima (24K-0985)

Q9: Write a recursive function bubbleSort that takes an array and its size. It performs the
bubble sort algorithm by repeatedly comparing adjacent elements and swapping them if
they are in the wrong order.

*/
#include <stdio.h>

void bubbleSort(int arr[], int size) {
    if (size == 1) {
        return;
    }
    
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
    
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    bubbleSort(arr, size - 1);
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {93, 11, 34, 12, 38, 24, 68};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, size);

   
    bubbleSort(arr, size);

    printf("Sorted array: \n");
    printArray(arr, size);

    return 0;
}
