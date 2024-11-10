/* Name/Roll Number: Abeer Fatima (24K-095)
q3: Write a program that takes a destination string and a source string as input. Then, take
an integer n as input and append only the first n characters of the source string to the
destination. Print the new concatenated string.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char destination[100];
	char source[100];
    int n;

    printf("take the destination string: ");
    fgets(destination, sizeof(destination), stdin);
    destination[strcspn(destination, "\n")] = '\0';

    
    printf("Enter the source string: ");
    fgets(source, sizeof(source), stdin);
    source[strcspn(source, "\n")] = '\0'; 

    
    printf("Enter the number of characters to append: ");
    scanf("%d", &n);

    
    strncat(destination, source, n);


    printf("The new concatenated string is: %s\n", destination);

    return 0;
}


