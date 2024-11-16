/*Name/Roll Number: Abeer Fatima (24K-0985)
Q4: You are working as a software engineer at a company that manages a large database of customer
transactions. Each transaction is stored as a string that contains encoded information about the
customer. However, some transactions may have been duplicated due to system errors, and these
duplicates appear in scrambled order. Your task is to identify and group these "scrambled"
transactions together, as they represent the same customer activity. Two transactions are considered
scrambled if they contain the same letters but in a different order (anagrams). You are provided with
a list of transaction strings. You need to write a program that groups these scrambled transactions
into separate categories, returning each group of related transactions together.
Example
Input transactions = ["eat", "tea", "tan", "ate", "nat", "bat"]
Expected Output: [['bat'], ['nat', 'tan'], ['ate', 'eat', 'tea']]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortingString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

void groupTransactions(char transactions[][100], int n) {
    int grouped[100] = {0}; 

    for (int i = 0; i < n; i++) {
        if (grouped[i]) continue; 

        char sorted1[100];
        strcpy(sorted1, transactions[i]);
        sortingString(sorted1);

        printf("[");
        printf("%s", transactions[i]); 

        for (int j = i + 1; j < n; j++) {
            char sorted2[100];
            strcpy(sorted2, transactions[j]);
            sortingString(sorted2);

            if (strcmp(sorted1, sorted2) == 0) { 
                printf(", %s", transactions[j]);
                grouped[j] = 1; // Mark as grouped
            }
        }
        printf("]\n");
        grouped[i] = 1; 
    }
}

int main() {

    char transactions[][100] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int n=6; 

    printf("Grouped Transactions: \n");
    groupTransactions(transactions, n);

    return 0;
}



