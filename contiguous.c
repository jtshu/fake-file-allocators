#include<stdio.h>

int main()
{
    char name[10][30];
    int start[10], length[10], num;
    int usedBlocks[1000] = {0}; //initializing array of 1000 blocks to 0 which is the free status
    int allocated = 0; 

    printf("Enter the number of files to be allocated\n");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("Enter the name of the file %d\n", i + 1);
        scanf("%s", name[allocated]);
        
        printf("Enter the start block of the file %d\n", i + 1);
        scanf("%d", &start[allocated]);

        printf("Enter the length of the file %d\n", i + 1);
        scanf("%d", &length[allocated]);

        int isValid = 1;

        for (int j = start[allocated]; j < start[allocated] + length[allocated]; j++) {
            if (usedBlocks[j] == 1) {
                isValid = 0;
                break;
            }
        }

        if (isValid) {
            for (int j = start[allocated]; j < start[allocated] + length[allocated]; j++) {
                usedBlocks[j] = 1;
            }
            allocated++;
        }
        else {
            printf("Error: At least some of the disk space from block %d to block %d is already allocated by another file. Skipping file.\n",
                   start[allocated], start[allocated] + length[allocated] - 1);
        }
    }

    printf("\nFile Allocation Table\n\n");
    printf("%s%40s%40s\n","File Name","Start Block","Length");
    // printf("%s%50d%50d\n",name[0],start[0],length[0]);

    // for(int i=0,j=1;i<num && j<num;i++,j++)
    // {
    //     if(start[i+1]<=start[i] || start[i+1]>=length[i])
    //         {
    //             printf("%s%50d%50d\n",name[j],start[j],length[j]);
    //         }
    // }

    for (int i = 0; i < allocated; i++) {
        printf("%s%50d%50d\n", name[i], start[i], length[i]);
    }

    return 0;
}