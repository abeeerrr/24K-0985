/*
Name/Roll Number: Abeer Fatima (24K-0985)

Q2: Write a recursive function that takes a string as input and returns the reversed string.

*/

#include <stdio.h>
#include <string.h>

void reverseString(char string[], int start, int end) {
    if (start >= end) {
        return; 
    }

    char temp = string[start];
    string[start] = string[end];
    string[end] = temp;

    reverseString(string, start + 1, end - 1);
}

int main() {
    char string[100]; 

    printf("Enter any string: ");
  scanf("%s", string); 
  
  
    int length = strlen(string); 
    
	reverseString(string, 0, length - 1); 

    printf("The reversed string is: %s\n", string); 

    return 0;
}
