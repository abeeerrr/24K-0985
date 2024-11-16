/*Name/Roll Number: Abeer Fatima (24K-0985)
Q3: You are working for a text-processing company that optimizes storage for large amounts of written
data. The company has identified a recurring issue: words in documents are often unnecessarily
lengthy due to repeated consecutive characters. Your task is to minimize these words by reducing
consecutive duplicate characters to a single instance of the character.
Operations:
Compress a Word: Write a function that takes a string (a word) as input and returns a minimized
version of the word, where all consecutive duplicate letters are reduced to one.
Multiple Word Compression: You will then apply this function to a list of words and return the
minimized version for each word.
Add a feature to calculate how many characters were removed during the compression process.
Input: words = [“booooook”, “coooool”, “heeeey”]
Output: [“bok”, “col”, “hey”]
*/

#include <stdio.h>
#include <string.h>

void compressWord(const char *word, char *compressed) {
       int j = 0;
       
    for (int i = 0; word[i] != '\0'; i++) {
        if (i == 0 || word[i] != word[i - 1]) {
            compressed[j++] = word[i];
        }
    }
       compressed[j] = '\0'; 
}

      void compressWords(char words[][100], int n, char compressedWords[][100], int *totalRemoved) {
    *totalRemoved = 0;

    for (int i = 0; i < n; i++) {
    char compressed[100];
        compressWord(words[i], compressed);

    *totalRemoved += strlen(words[i]) - strlen(compressed);

        strcpy(compressedWords[i], compressed);
    }
}

int main() {
    char words[][100] = {"booooook", "coooool", "heeeey"};
    int n=3; 

    char compressedWords[100][100];
    int totalRemoved;

    compressWords(words,n, compressedWords, &totalRemoved);

    printf("compressed Words: \n");
    for (int i =0; i < n; i++) {
        printf("%s\n", compressedWords[i]);
    }
    printf("total Characters Removed: %d\n", totalRemoved);

    return 0;
}
