/* Name/Roll Number: Abeer Fatima (24K-0985)
Q2: Write a program in C to read n number of values in an array and display it in reverse
order
Input: {1,2,3,4,5,6,7,8,9}
Output: 9 8 7 6 5 4 3 2 1
*/

#include <stdio.h>

int main() {
    int i;
    int n;
    
    printf("Take the number of elements.\n");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter %d values.\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("The values in reversed order are: \n");
    for(i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
