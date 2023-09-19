/*
 * GasStationManager
 *
 * A program to manage the gas tanks at a station with four pumps.
 * It tracks the gas content of each tank, refilling them when low.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define PUMPS 4
#define USAGE 10
#define LOW_LIMIT 20

int pumps[PUMPS] = {100, 75, 50, 150};
int capacities[PUMPS] = {100, 75, 50, 150};

void displayTanks() {
    printf("\nCurrent Contents of the tanks:\n");
    for (int i = 0; i < PUMPS; i++) {
        printf("Tank %d: %d gallons\n", i + 1, pumps[i]);
    }
}

void refillRequest(int pumpNum) {
    pumps[pumpNum] = capacities[pumpNum];
    printf("Tank %d refilled to %d gallons!\n", pumpNum + 1, pumps[pumpNum]);
}

void processCar(int pumpNum) {
    if (pumps[pumpNum] >= USAGE) {
        pumps[pumpNum] -= USAGE;
        printf("\nGas Pump #%d used by car\n", pumpNum + 1);
        displayTanks();
        if (pumps[pumpNum] < LOW_LIMIT) {
            refillRequest(pumpNum);
        }
    } else {
        printf("\nGas Pump #%d is low on fuel and cannot be used.\n", pumpNum + 1);
    }
}

int main(void) {
    for (int i = 0; i < 60; i++) {
        int randomPump = rand() % PUMPS;
        processCar(randomPump);
    }
    return 0;
}