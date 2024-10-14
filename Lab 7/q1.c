/* Name/Roll Number: Abeer Fatima (24K-0985)
Q1: Write a C Program that takes an user input array and prints the sum of its elements.
Input: {1,2,3,4,5,6,7,8,9}
Output: 45
*/
#include <stdio.h>

int main() {
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int sum = 0;
    int i;

    for (i = 0; i < 9; i++) {
        sum = sum + arr[i]; 
    }


    printf("The sum of the elements is %d\n", sum);

    return 0;
}