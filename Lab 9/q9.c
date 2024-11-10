/* Name/Roll Number: Abeer Fatima (24K-095)
q9: Create a function that reverses a given string and returns the reversed string. Use this function
in the main program to display the reversed string entered by the user.
*/

#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int length = strlen(str);
    int start= 0;
    int end = length-1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char str[100];
    
    printf("take a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    
    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
