/* Name/Roll Number: Abeer Fatima (24K-0985)
Q3: Write a C Program to find the minimum and maximum number in an array.
Input: {4,1,6,8,10,21,8,9,2,6}
Output:
Minimum Number = 1
Maximum Number = 21
*/
#include <stdio.h>
int main() {
   
    int i;
    int n;
    int min;
    int max;
     int arr[100];
    
   printf("enter the size of the array\n");
   scanf("%d", &n);
    printf("enter the elements of the array\n");
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    min=arr[0];
    max=arr[0];
    
    for (i=0 ; i<n ; i++) {
    if (arr[i]>max) {
		max=arr[i];
	}
	
	if(arr[i]<min){
		min=arr[i];
	 }
     }
    
	printf("Maximum element is: %d\n", max);
	printf("Minimum element is: %d\n", min);
 
	return 0;
        }