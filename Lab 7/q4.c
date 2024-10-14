/* Name/Roll Number: Abeer Fatima (24K-0985)
Q4: Given an array arr[] of size N which contains elements from 0 to N-1, you need to
find all the elements occurring more than once in the given array.
Input:
Array Size =5
Element 1=2
Element 2=3
Element 3=1
Element 4=2
Element 5=3
Output:
Number 2 and 3 in array occur more than once.
Note: You cannot utilize nested loops.
*/
#include <stdio.h>
int main() {
    int n; //size of array
    int index;
    int i;
    int arr[100];
    
    printf("Enter the size of the array.\n");
    scanf("%d", &n);
    
    printf("Enter the elements of the array.\n");
   
    for (i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("The repeating elements are:\n");
    for (i=0; i<n; i++) {
        index = arr[i] < 0 ? -arr[i] : arr[i]; 
        
       
        if (index < n && arr[index] >= 0) {
            arr[index] = -arr[index]; 
        } else if (index < n) {
          
            printf("%d\n", index);
        }
    }
    
    return 0;
}