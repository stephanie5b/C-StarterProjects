/*
 * ATM Machine Simulator
 * A simple C program that emulates an ATM's cash dispensing functionality. 
 * The program takes a user-inputted amount (up to $200) and breaks it down into the appropriate denominations, simulating the process of giving out the correct bills.
 */

#include <stdio.h>

int main(void) {

    const int DENOMINATIONS[] = {100, 20, 10, 5, 1};
    const char *DENOMINATION_NAMES[] = {"One-Hundred", "Twenty", "Ten", "Five", "One"};
    int billCounts[] = {0, 0, 0, 0, 0};
    int numDenominations = sizeof(DENOMINATIONS) / sizeof(DENOMINATIONS[0]);

    int userEnt;

    printf("Enter amount you would like to withdraw (up to $200): ");
    scanf("%d", &userEnt);

    if (userEnt > 200) {
        printf("Amount exceeds the maximum allowed limit of $200.\n");
        return 1; // Exiting the program
    }

    for (int i = 0; i < numDenominations; i++) {
        while (userEnt >= DENOMINATIONS[i]) {
            userEnt -= DENOMINATIONS[i];
            billCounts[i]++;
            printf("\nGetting a %s Dollar Bill...", DENOMINATION_NAMES[i]);
        }
    }

    printf("\nA total of %d one-hundred dollar bills, %d twenty dollar bills, %d ten dollar bills, %d five dollar bills, %d one dollar bills have been given.\n",
            billCounts[0], billCounts[1], billCounts[2], billCounts[3], billCounts[4]);

    return 0;
}
