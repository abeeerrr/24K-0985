/* Name/Roll Number: Abeer Fatima

q1: Write a c program to find the second smallest element in an array.
Input 5 elements in the array (value must be <9999):
element - 0: 0
element - 1: 9
element - 2: 4
element - 3: 6
element - 4: 5
Expected Output:
The Second smallest element in the array is: 4

*/

#include <stdio.h>

int main() {
    int arr[5];
    int i;
    int smallest;
    int secondSmallest;

    printf("enter 5 elements of the array (value < 9999): \n");
    for (i = 0; i < 5; i++) {
        printf("element - %d: ", i);
        scanf("%d", &arr[i]);
    }

    smallest = secondSmallest = 9999;

    for (i = 0; i < 5; i++) {
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != secondSmallest) {
            secondSmallest = arr[i];
        }
    }

    if (secondSmallest == 9999) {
        printf("There is no second smallest element.\n");
    } else {
        printf("The Second smallest element in the array is: %d\n", secondSmallest);
    }

    return 0;
    
}


