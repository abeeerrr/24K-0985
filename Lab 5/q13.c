/* Name/Roll Number: Abeer Fatima/24K-0985
Q13: Write a program that uses bitwise operators to perform encryption and decryption of a
character.
*/

#include <stdio.h>
 int main() {
 	
    char character, encryptedChar, decryptedChar;
    int key;

    
	printf("take any character\n");
    scanf("%c", &character);

    printf("Enter an encryption key\n");
    scanf("%d", &key);



    encryptedChar = character^key;
    printf("Encrypted character: %c\n", encryptedChar);

    decryptedChar = encryptedChar^key;
    printf("Decrypted character: %c\n", decryptedChar);

    return 0;
}
	