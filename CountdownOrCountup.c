/*
 * CountdownOrCountup
 *
 * A program that generates either a countup (1 to 10) or countdown (10 to 1) 
 * based on user input. Uses the function "generateCounter" to produce the list.
 * The function takes in an array to store the count, two string pointers for
 * "countup" and "countdown", and a flag. The flag (true for countdown and false 
 * for countup) determines the list type.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void generateCounter(int *countHolder, bool isCountdown);
void printList(int *countHolder, bool isCountdown);

int main(void) {
    int choice;
    int countHolder[10];

    printf("Enter:\n'1' for count UP or\n'2' for count DOWN\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            generateCounter(countHolder, false);
            printList(countHolder, false);
            break;
        case 2:
            generateCounter(countHolder, true);
            printList(countHolder, true);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}

void generateCounter(int *countHolder, bool isCountdown) {
    if (isCountdown) {
        for (int i = 0; i < 10; i++) {
            countHolder[i] = 10 - i;
        }
    } else {
        for (int i = 0; i < 10; i++) {
            countHolder[i] = i + 1;
        }
    }
}

void printList(int *countHolder, bool isCountdown) {
    printf(isCountdown ? "Countdown:\n**********\n" : "Countup:\n********\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", countHolder[i]);
    }
}
