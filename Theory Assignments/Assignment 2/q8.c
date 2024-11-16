/*Name/Roll Number: Abeer Fatima (24K-0985)
Q8: Write a C program that contains the following functions for different numerical conversions:
1. int BinaryToDecimal(int number); Converts a binary number to its decimal equivalent.
2. int DecimalToBinary(int number); Converts a decimal number to its binary equivalent.
3. void DecimalToHexadecimal(int number); Converts a decimal number to its hexadecimal
equivalent and prints it.
4. void HexadecimalToDecimal(string hexNumber); Converts a hexadecimal number to its
decimal equivalent and prints it.
5. void BinaryToHexadecimal(int number); Converts a binary number to its hexadecimal
equivalent and prints it.
6. void HexadecimalToBinary(string hexNumber); Converts a hexadecimal number to its binary
equivalent and prints it.
Each function should take an appropriate input and return or display the converted value. Ensure that
the program handles invalid inputs gracefully. Your program must display the menu which function
the user wants to call.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int isBinary(int number) {
    while (number > 0) {
        if (number % 10 > 1) return 0;
        number /= 10;
    }
    return 1;
}

int BinaryToDecimal(int number) {
    if (!isBinary(number)) {
        printf("Invalid binary number.\n");
        return -1;
    }
    int decimal = 0, base = 1, lastDigit;
    while (number > 0) {
        lastDigit = number % 10;
        decimal += lastDigit * base;
        base *= 2;
        number /= 10;
    }
    return decimal;
}

int DecimalToBinary(int number) {
    int binary = 0, base = 1;
    while (number > 0) {
        binary += (number % 2) * base;
        number /= 2;
        base *= 10;
    }
    return binary;
}

void DecimalToHexadecimal(int number) {
    char hex[100];
    int index = 0;
    while (number > 0) {
        int remainder = number % 16;
        if (remainder < 10) {
            hex[index++] = '0' + remainder;
        } else {
            hex[index++] = 'A' + (remainder - 10);
        }
        number /= 16;
    }
    hex[index] = '\0';
    
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hex[i]);
    }
    printf("\n");
}

void HexadecimalToDecimal(char hexNumber[]) {
    int length = strlen(hexNumber), decimal = 0, base = 1;
    for (int i = length - 1; i >= 0; i--) {
        char c = toupper(hexNumber[i]);
        if (c >= '0' && c <= '9') {
            decimal += (c - '0') * base;
        } else if (c >= 'A' && c <= 'F') {
            decimal += (c - 'A' + 10) * base;
        } else {
            printf("Invalid hexadecimal number.\n");
            return;
        }
        base *= 16;
    }
    printf("%d\n", decimal);
}

void BinaryToHexadecimal(int number) {
    int decimal = BinaryToDecimal(number);
    if (decimal != -1) {
        DecimalToHexadecimal(decimal);
    }
}

void HexadecimalToBinary(char hexNumber[]) {
    int decimal = 0, base = 1;
    int length = strlen(hexNumber);

    for (int i = length - 1; i >= 0; i--) {
        char c = toupper(hexNumber[i]);
        if (c >= '0' && c <= '9') {
            decimal += (c - '0') * base;
        } else if (c >= 'A' && c <= 'F') {
            decimal += (c - 'A' + 10) * base;
        } else {
            printf("Invalid hexadecimal number.\n");
            return;
        }
        base *= 16;
    }

    DecimalToBinary(decimal);
    int binary = DecimalToBinary(decimal);
    printf("%d\n", binary);
}

void displayMenu() {
    printf("\nNumerical Conversion Menu:\n");
    printf("1. Binary to Decimal\n");
    printf("2. Decimal to Binary\n");
    printf("3. Decimal to Hexadecimal\n");
    printf("4. Hexadecimal to Decimal\n");
    printf("5. Binary to Hexadecimal\n");
    printf("6. Hexadecimal to Binary\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice, number;
    char hexNumber[100];

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter a binary number: ");
            scanf("%d", &number);
            printf("Decimal: %d\n", BinaryToDecimal(number));
            break;
        case 2:
            printf("Enter a decimal number: ");
            scanf("%d", &number);
            printf("Binary: %d\n", DecimalToBinary(number));
            break;
        case 3:
            printf("Enter a decimal number: ");
            scanf("%d", &number);
            printf("Hexadecimal: ");
            DecimalToHexadecimal(number);
            break;
        case 4:
            printf("Enter a hexadecimal number: ");
            scanf("%s", hexNumber);
            printf("Decimal: ");
            HexadecimalToDecimal(hexNumber);
            break;
        case 5:
            printf("Enter a binary number: ");
            scanf("%d", &number);
            printf("Hexadecimal: ");
            BinaryToHexadecimal(number);
            break;
        case 6:
            printf("Enter a hexadecimal number: ");
            scanf("%s", hexNumber);
            printf("Binary: ");
            HexadecimalToBinary(hexNumber);
            break;
        case 7:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
