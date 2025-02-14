#include <stdio.h>
#include <stdlib.h>

void allocateIndexBlock(int files[], int totalBlocks) {
    int indBlock, n, indexBlock[50], flag = 1;

    while (flag) {
        printf("Enter the index block: ");
        scanf("%d", &indBlock);

        if (indBlock < 0 || indBlock >= totalBlocks) {
            printf("Error: Block %d is out of range.\n", indBlock);
            continue;
        }

        if (files[indBlock] == 1) {
            printf("Error: Block %d is already allocated.\n", indBlock);
            continue;
        }

        printf("Enter the number of blocks and number of files needed for the index %d: ", indBlock);
        scanf("%d", &n);

        if (n > totalBlocks) {
            printf("Error: The requested number of blocks is greater than the total number of available blocks.\n");
            continue;
        }

        int allocated = 0;

        printf("Enter the block numbers to allocate:\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &indexBlock[i]);

            if (indexBlock[i] < 0 || indexBlock[i] >= totalBlocks) {
                printf("Error: Block %d is out of range.\n", indexBlock[i]);
                allocated = -1;
                break;
            }

            if (files[indexBlock[i]] == 1) {
                printf("Error: Block %d is already allocated.\n", indexBlock[i]);
                allocated = -1;
                break;
            }

            allocated++;
        }

        if (allocated == n) {
            files[indBlock] = 1;
            for (int i = 0; i < n; i++) {
                files[indexBlock[i]] = 1;
            }

            printf("Allocation successful!\n");
            printf("File Indexed:\n");
            for (int i = 0; i < n; i++) {
                printf("%d ------> %d\n", indBlock, indexBlock[i]);
            }
        } else {
            printf("Error: Something went wrong with the allocation process. Skipping file.\n");
        }

        while (1) {
            printf("Do you want to enter more files? Enter 1 for Yes, 0 for No: ");
            if (scanf("%d", &flag) != 1) { 
                printf("Invalid input. Please enter 1 or 0.\n");
                while (getchar() != '\n'); //need to clear input buffer to prevent it from automatically exiting
                continue;
            }
            if (flag == 1 || flag == 0) { //valid input check
                break;
            }
            printf("Invalid choice. Please enter 1 for Yes, 0 for No.\n");
        }
    }
}

int main() {
    int files[50] = {0};
    int totalBlocks = 50;

    allocateIndexBlock(files, totalBlocks);

    return 0;
}
