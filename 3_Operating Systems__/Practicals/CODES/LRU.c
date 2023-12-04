#include <stdio.h>

int main() {
    int i, j, min, rs[25], m[10], count[10], flag[25], n, f, pf = 0, next = 1;

    printf("\nEnter the length of reference string -- ");
    scanf("%d", &n);

    printf("\nEnter the reference string -- ");
    for (i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
        flag[i] = 0;
    }

    printf("\nEnter the number of frames -- ");
    scanf("%d", &f);
    for (i = 0; i < f; i++) {
        count[i] = 0;
        m[i] = -1;
    }

    printf("\nThe Page Replacement process is -- \n");
    for (i = 0; i < n; i++) {
        flag[i] = 0;

        // Check if page is already in memory
        for (j = 0; j < f; j++) {
            if (m[j] == rs[i]) {
                flag[i] = 1;
                count[j] = next;
                next++;
                break;
            }
        }

        if (flag[i] == 0) {
            int replace = 0;
            min = count[0];
            
            // Finding the page with minimum count to replace
            for (j = 1; j < f; j++) {
                if (count[j] < min) {
                    min = count[j];
                    replace = j;
                }
            }

            m[replace] = rs[i];
            count[replace] = next;
            next++;
            pf++;

            for (j = 0; j < f; j++)
                printf("%d\t", m[j]);
            
            printf("PF No. -- %d\n", pf);
        }
    }

    printf("\nThe number of page faults using LRU is %d\n", pf);
    return 0;
}
