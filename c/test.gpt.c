/*
 * code generated from the defnition of this prompt
 *
convert this to a simple C program .
remember they used gray scale for the binary implementation of 'positions'

1. for step no i
1.1 Compute ith and (i+1)th grey number.
1.2 XOR the two numbers and note which bit changes.
1.3 Let the bit change occur at position j
1.3.1 if j is equal to n, GOTO 2
1.4 Compute the FROM_PEG and TO_PEG using the formula
FROM_PEG = (i & (i-1)) % 3
TO_PEG = ((i | i-1) +1) % 3
1.5 if the number of disks is even then swap the peg 2 with peg 3.
1.6 Move disk j from FROM_PEG to TO_PEG.
1.7 GOTO step 1.1
2. Stop.
 *
 *
 */


#include <stdio.h>

int binaryToGray(int num) {
    return num ^ (num >> 1);
}

void towerOfHanoi(int n) {
    int i, j, fromPeg, toPeg, changeBitPos;

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

        printf("Move disk %d from Peg %d to Peg %d\n", changeBitPos + 1, fromPeg + 1, toPeg + 1);
    }
}

int main_run() {
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

int
main_test_gray () {

    main_run();

    int number = 0b1001001;

    int gnumber = binaryToGray(number); // WORKS

    printf("Number :: %d\n", number);
    printf("Gray Number :: %d\n", gnumber);

}

int main () {
    return main_run();
}
