/*Name/Roll Number: Abeer Fatima (24K-0985)
Q7: One of the master coders designed a subscript block that stores random characters in a
multidimensional array. You are asked to design a program that will find a given string in a
multidimensional array of characters. The search for characters can be present and operational from
left to right and top to down only. The program should create a 6 x 5 2D array and populate it with
random alphabet characters. After that, the program should print it in a tabular form as shown below.
Search the user-entered string in the 2D array, if it is present then add a point to the score, if it is not
available then subtract one. Print the score at every input. The program stops asking and re-populates
the 2D array with new random characters when the user enters “END” as the string.
[NOTE: After generating random numbers, the last row should have your student ID’s last four digits]

E D D F R
A F V A Q
T E B S T
L J G T T
1 2 3 4 Q

Search Str= “FAST”
Output:
FAST is present Score 1
Search Str= “EAT”
EAT is present Score 2
Search Str= “GREAT”
GREAT is not present Score 1
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define ROWS 6
#define COLS 5

void populateArray(char array[ROWS][COLS]) {
    int i, j;

    for (i = 0; i < ROWS - 1; i++) {
        for (j = 0; j < COLS; j++) {
            array[i][j] = 'A' + rand() % 26; 
        }
    }

    array[ROWS - 1][0] = '1';
    array[ROWS - 1][1] = '2';
    array[ROWS - 1][2] = '3';
    array[ROWS - 1][3] = '4';
    array[ROWS - 1][4] = 'Q';
}

void displayArray(char array[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", array[i][j]);
        }
        printf("\n");
    }
}

int searchString(char array[ROWS][COLS], char str[]) {
    int len = strlen(str);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <= COLS - len; j++) {
            int found = 1;
            for (int k = 0; k < len; k++) {
                if (array[i][j + k] != str[k]) {
                    found = 0;
                    break;
                }
            }
            if (found) {
                return 1; 
            }
        }
    }

    for (int i = 0; i <= ROWS - len; i++) {
        for (int j = 0; j < COLS; j++) {
            int found = 1;
            for (int k = 0; k < len; k++) {
                if (array[i + k][j] != str[k]) {
                    found = 0;
                    break;
                }
            }
            if (found) {
                return 1; 
            }
        }
    }
  return 0; 
}

int main() {
    char array[ROWS][COLS];
    char input[100];
    int score = 0;

    srand(time(NULL)); 

    populateArray(array);

    while (1) {
        
        printf("\nGenerated 2D Array:\n");
        displayArray(array);

        printf("\nEnter a string to search (type \"END\" to regenerate the array): ");
        scanf("%s", input);

        if (strcmp(input, "END") == 0) {
            printf("Repopulating the array with new characters...\n");
            populateArray(array);
            continue;
        }

        for (int i = 0; i < strlen(input); i++) {
            input[i] = toupper(input[i]);
       }

        if (searchString(array, input)) {
            printf("%s is present. ", input);
            score++;
        } else {
            printf("%s is not present. ", input);
            score--;
        }

        printf("Score: %d\n", score);
    }

    return 0;
}
