/*
 * PalindromeChecker
 *
 * A program to determine if a given number is a palindrome.
 *
 */

#include <stdio.h>

int main(void) {
    int userNumber, originalNumber, remainder, reversedNumber = 0;

    printf("Enter a number: ");
    scanf("%d", &userNumber);
    originalNumber = userNumber;

    // Reversing the number
    while (userNumber != 0) {
        remainder = userNumber % 10;
        reversedNumber = (reversedNumber * 10) + remainder;
        userNumber /= 10;
    }

    if (originalNumber == reversedNumber) {
        printf("Number input: %d, is a palindrome.\n", originalNumber);
    } else {
        printf("Number input: %d, is NOT a palindrome.\n", originalNumber);
    }

    return 0;
}
