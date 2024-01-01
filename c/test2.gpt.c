/**
 * this code has been a attempt to create a validation of moviments.
 *
 */

#include <stdio.h>

int binaryToGray(int num) {
    return num ^ (num >> 1);
}

void printTowerState(int pegs[][10], int numPegs, int numDisks) {
    printf("Current Tower State:\n");
    for (int peg = 0; peg < numPegs; peg++) {
        printf("Peg %d: ", peg + 1);
        for (int disk = 0; disk < numDisks; disk++) {
            printf("%d ", pegs[peg][disk]);
        }
        printf("\n");
    }
    printf("\n");
}

int validateMove(int pegs[][10], int fromPeg, int toPeg, int disk) {
    // Check if moving a larger disk onto a smaller one
    if (pegs[fromPeg][disk] == 0) {
        printf("Invalid move: Trying to move a disk from an empty peg.\n");
        return 0;
    }

    if (pegs[toPeg][0] != 0 && pegs[fromPeg][disk] > pegs[toPeg][0]) {
        printf("Invalid move: Trying to move a larger disk onto a smaller one.\n");
        return 0;
    }

    return 1;
}

void makeMove(int pegs[][10], int fromPeg, int toPeg, int disk) {
    // Move the disk
    int diskToMove = pegs[fromPeg][disk];
    pegs[fromPeg][disk] = 0;
    int emptySlot = 0;
    while (pegs[toPeg][emptySlot] != 0) {
        emptySlot++;
    }
    pegs[toPeg][emptySlot] = diskToMove;
}

void towerOfHanoi(int n) {
    int i, j, fromPeg, toPeg, changeBitPos;

    // Initialize towers with disks
    int pegs[3][10] = {0}; // Assuming a maximum of 10 disks

    for (int disk = 0; disk < n; disk++) {
        pegs[0][disk] = n - disk;
    }

    printTowerState(pegs, 3, n);

    for (i = 0; i < (1 << n); i++) {
        int gray1 = binaryToGray(i);
        int gray2 = binaryToGray(i + 1);
        int xorResult = gray1 ^ gray2;

        for (j = 0; j < 32; j++) {
            if ((xorResult >> j) & 1) {
                changeBitPos = j;
                break;
            }
        }

        if (changeBitPos == n) {
            break; // GOTO 2
        }

        fromPeg = (i & (i - 1)) % 3;
        toPeg = ((i | (i - 1)) + 1) % 3;

        if (n % 2 == 0) {
            // Swap peg 2 with peg 3
            if (fromPeg == 1) {
                fromPeg = 2;
            } else if (toPeg == 1) {
                toPeg = 2;
            }
        }

        // Validate the move
        if (!validateMove(pegs, fromPeg, toPeg, changeBitPos)) {
            printf("Invalid move detected. Exiting.\n");
            return;
        }

        // Make the move
        makeMove(pegs, fromPeg, toPeg, changeBitPos);

        // Print the updated tower state
        printTowerState(pegs, 3, n);
    }
}

int main() {
    int numDisks;

    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    if (numDisks <= 0) {
        printf("Invalid number of disks. Please enter a positive integer.\n");
        return 1;
    }

    towerOfHanoi(numDisks);

    return 0;
}

