/* Name/Roll Number: Abeer Fatima (24K-095)
q4: Write a program that initializes a 2D character array with a list of words. Then, take a
word as input from the user and check if it exists in the array. Display "Found" if it’s there,
otherwise display "Not Found".
*/

#include <stdio.h>
#include <string.h>

int main() {
    
    char words[5][20] = {
        "mairaj",
        "aashir",
        "nazia",
        "amna",
        "ishtiaq"
                       };
    
    char input[20];
    int found = 0;
    int i;

    printf("search a word: ");
    scanf("%19s", input);

    for (i = 0; i < 5; i++) {
        if (strcmp(words[i], input) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    return 0;
}
