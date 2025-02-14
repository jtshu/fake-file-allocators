#include <stdio.h>
#include <stdlib.h>

void recursivePart(int pages[]) {
    int st, len, again;
    int current = st;
    int blocksLeft = len;

    printf("Enter the index of the starting block and its length: ");
    scanf("%d%d", &st, &len);

    while (blocksLeft > 0 && current < 50) {
        if (pages[current] == 1) {
            printf("Block %d is already allocated.\n", current);
            current++;
        } else {
            int startBlock = current;
            int allocated = 0;

            while (blocksLeft > 0 && current < 50 && pages[current] == 0) {
                pages[current] = 1;
                allocated++;
                blocksLeft--;
                current++;
            }

            printf("Block %d ---> %d blocks\n", startBlock, allocated);
        }
    }

    if (blocksLeft == 0) {
        printf("Allocation successful. All %d blocks allocated.\n", len);
    } else {
        printf("Allocation not fully successful. %d blocks could not be allocated.\n", blocksLeft);
    }

    printf("Do you want to enter more files? \n");
    printf("Enter 1 for Yes, Enter 0 for No: ");
    scanf("%d", &again);

    if (again == 1)
        recursivePart(pages);
    else
        exit(0);
}

int main() {
    int pages[50], p, a;

    for (int i = 0; i < 50; i++) {
        pages[i] = 0;
    }

    printf("Enter the number of blocks already allocated: ");
    scanf("%d", &p);

    printf("Enter the blocks already allocated: ");
    for (int i = 0; i < p; i++) {
        scanf("%d", &a);
        if (a >= 0 && a < 50) {
            pages[a] = 1;
        } else {
            printf("Error: Invalid block index %d. Skipping file.\n", a);
        }
    }

    recursivePart(pages);
    return 0;
}
