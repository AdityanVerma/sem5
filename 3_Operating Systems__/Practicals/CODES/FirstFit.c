#include <stdio.h>
#define MAX 25

int main() {
    int frag[MAX], b[MAX], f[MAX], bf[MAX], ff[MAX];
    int i, j, nb, nf, temp;

    printf("\n\tMemory Management Scheme - First Fit\n");
    printf("Enter the number of blocks: ");
    scanf("%d", &nb);

    printf("Enter the number of files: ");
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:\n");
    for (i = 1; i <= nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
        bf[i] = 0; // Initialize allocation flag for blocks
    }

    printf("\nEnter the size of the files:\n");
    for (i = 1; i <= nf; i++) {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
        ff[i] = -1; // Initialize file allocation block to -1 (unallocated)
    }

    for (i = 1; i <= nf; i++) {
        for (j = 1; j <= nb; j++) {
            if (bf[j] == 0 && b[j] >= f[i]) { // if block j is not allocated and fits file i
                ff[i] = j;
                frag[i] = b[j] - f[i]; // Calculate fragmentation
                bf[j] = 1; // Mark block as allocated
                break; // Move to next file
            }
        }
    }

    printf("\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragment\n");
    for (i = 1; i <= nf; i++) {
        printf("%d\t\t%d\t\t", i, f[i]);
        if (ff[i] != -1) {
            printf("%d\t\t%d\t\t%d\n", ff[i], b[ff[i]], frag[i]);
        } else {
            printf("Not allocated\tNot allocated\tNot allocated\n");
        }
    }
    printf("\n");

    return 0;
}
