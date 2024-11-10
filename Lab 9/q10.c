/* Name/Roll Number: Abeer Fatima (24K-095)
q10: Create a function that returns the maximum and minimum element in an integer array. Use this
function in the main program to find the maximum and minimum from an array entered by the
user.
*/

#include <stdio.h>

  int i;
  void findMaxOrMin(int arr[], int size, int *max, int *min) {
    *max = arr[0]; 
    *min = arr[0];

    for (i = 1; i < size; i++) {
    if (arr[i] > *max) {
           *max = arr[i]; // this is to update max in case a larger element is found
        }
    if (arr[i] < *min) {
        *min = arr[i]; // for smaller element
    }
    }
}

  int main() {
    int n;
    int i;
    
    printf("take number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max;
    int min;

    findMaxOrMin(arr, n, &max, &min);

    printf("The maximum value is: %d\n", max);
    printf("The minimum value is: %d\n", min);

    return 0;
}


