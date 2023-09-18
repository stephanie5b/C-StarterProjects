#include <stdio.h>

#define DOLLAR_SIGN '$'
#define DOT '.'

int main(void) {
    int currentChar;
    
    printf("Enter a line to extract the numeric dollar amount:\n");

    // Scan each character of the input line
    while ((currentChar = getchar()) != '\n') {
        // If a dollar sign is detected, start printing the amount
        if (currentChar == DOLLAR_SIGN) {
            putchar(currentChar);
            
            // Continue to print numbers and potential dot for cents until another character is encountered
            while (1) {
                currentChar = getchar();
                
                // Check if current character is a dot or a numeric digit
                if (currentChar == DOT || (currentChar >= '0' && currentChar <= '9')) {
                    putchar(currentChar);   
                } else {
                    break; // Exit the loop if any other character is detected
                }
            }
            printf("\n"); // New line after printing the full amount
        }
    }

    return 0;
}