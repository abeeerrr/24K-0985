/* Name/Roll Number: Abeer Fatima (24K-0985)
q3: Create a program to validate an email address based on a few basic criteria. The program will
prompt the user to enter an email address and will dynamically allocate memory to store and
process the input.
Define the following function:
1. int validateEmail(char* email): This function validates the email based on the following
criteria:
? Contains exactly one @ symbol.
? Contains at least one dot (.) after the @ symbol.
? Is non-empty.
? Returns 1 if the email is valid, and 0 if invalid.

Steps:
1. User Input: Prompt the user to enter an email address. Allocate memory dynamically for the
email, ensuring the memory size is based on the input length.
2. Validation Process:
? Call the validateEmail function to check if the email meets the criteria.
3. Display Results:
? Print "Valid Email" if the email meets the criteria.
? Print "Invalid Email" if the email does not meet the criteria.
4. Memory Cleanup:
? Free the dynamically allocated memory after validation to prevent memory leaks.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(char* email);

int main() {
    char *email;
    size_t length;

    printf("enter your email address: ");
    
    email = (char*)malloc(256*sizeof(char)); 
    if (email == NULL) {
        printf("Error! Dynamic Memory Allocation failed.\n");
        return 1;
    }

    fgets(email, 256, stdin);
    length = strlen(email);

    if (email[length - 1] == '\n') {
        email[length - 1] = '\0';
    }
 
    if (validateEmail(email)) {
        printf("Valid Email\n");
    } else {
        printf("Invalid Email\n");
    }

    free(email);

    return 0;
}

int validateEmail(char* email) {
    int atCount = 0, dotCount = 0;
    char *atPos = NULL;

    if (email == NULL || strlen(email) == 0) {
        return 0;
    }

    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            atCount++;
            atPos = &email[i]; 
        }
    }

    if (atCount != 1) {
        return 0;
    }

    for (char *ptr = atPos + 1; *ptr != '\0'; ptr++) {
        if (*ptr == '.') {
            dotCount++;
        }
    }

    if (dotCount < 1) {
        return 0;
    }

    return 1; 
}
