/*
Name/Roll Number: Abeer Fatima (24K-0985)

Q12: Write a recursive function linearSearch that takes an array, its size, the target element
to search for, and the current index. It checks if the target is at the current index and
continues searching in the subsequent indices until it either finds the target or exhausts
the array.

*/
#include <stdio.h>

int linearSearch(int arr[], int size, int target, int currentIndex) {
    if (currentIndex >= size) {
        return 0;
    }

    if (arr[currentIndex] == target) {
        return currentIndex; 
    }

    return linearSearch(arr, size, target, currentIndex + 1);
}

int main() {
    int arr[] = {6, 5, 7, 6, 5, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target, index;

    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    index = linearSearch(arr, size, target, 0);

    if (index != -1) {
        printf("Target element %d found at index %d.\n", target, index);
    } else {
        printf("Target element %d not found in the array.\n", target);
    }

    return 0;
}
