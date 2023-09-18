/*
 * Ciphered Password Encoder & Decoder
 *
 * This program takes a user's password, converts it to uppercase, 
 * and then applies a simple cipher transformation by shifting each 
 * character's ASCII value by 25. If the resulting value exceeds the 
 * ASCII value for 'Z', it wraps around starting from 'A'. After encoding, 
 * it displays the ciphered password to the user. The user can then enter 
 * a ciphered password to decode, and the program will reverse the 
 * transformation, displaying the original password in lowercase.
 */

#include <ctype.h>
#include <stdio.h>

char encode(char ch) {
    ch = toupper(ch);
    ch += 25;
    if (ch > 'Z') {
        ch -= 26;
    }
    return ch;
}

char decode(char ch) {
    ch = toupper(ch);
    ch -= 25;
    if (ch < 'A') {
        ch += 26;
    }
    return ch;
}

int main(void) {
    char userPasswordChar;

    printf("Please Enter your Password:\n");
    while ((userPasswordChar = getchar()) != '\n' && userPasswordChar != EOF) {
        if (isalpha(userPasswordChar)) {  // Only process alphabets
            char encodedChar = encode(userPasswordChar);
            printf("\nNew Letter Encoded: %c", encodedChar);
        }
    }
    printf("\n");

    char decodedPasswordChar;

    printf("\nEnter a password to decode: \n");
    while ((decodedPasswordChar = getchar()) != '\n' && decodedPasswordChar != EOF) {
        if (isalpha(decodedPasswordChar)) {  // Only process alphabets
            char originalChar = decode(decodedPasswordChar);
            printf("%c", tolower(originalChar));
        }
    }
    printf(" <---- is your original password\n");
    
    return 0;
}
