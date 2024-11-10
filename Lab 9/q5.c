/* Name/Roll Number: Abeer Fatima (24K-095)
q5: Create a program that accepts a 2D array of strings (e.g., 5 words with a max length of 20
characters each). Determines if each word (row) is a palindrome. Outputs “Palindrome” or “Not
Palindrome” for each word. A palindrome is a word that reads the same forward and backward.
For example: "madam", "racecar", "level", "radar".
*/

#include <stdio.h>
#include <string.h>

int i;
int Palindrome(char word[]) {
    int length = strlen(word);
    for (i = 0; i < length / 2; i++) {
        if (word[i] != word[length - 1 - i]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Palindrome
}

int main() {
    char words[5][20];
    int numWords = 5;
    int i;

    printf("Enter 5 words (max 20 characters each):\n");
    for (i = 0; i < numWords; i++) {
        printf("Word %d: ", i + 1);
        scanf("%19s", words[i]);
    }

  for (int i = 0; i < numWords; i++) {
        if (Palindrome(words[i])) {
           printf("Word %d (%s) is a Palindrome\n", i + 1, words[i]);
        }
		 else {
            printf("Word %d (%s) is not a Palindrome\n", i + 1, words[i]);
        }
    }

    return 0;
}
