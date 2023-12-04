#include <stdio.h>
int main()
{
    int i, j, k, f, pf = 0, count = 0, rs[25], m[10], n, flag;

    printf("\nEnter the length of reference string -- ");
    scanf("%d", &n);

    printf("\nEnter the reference string -- ");
    for (i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
    }

    printf("\nEnter no. of frames -- ");
    scanf("%d", &f);
    for (i = 0; i < f; i++) {
        m[i] = -1;
    }

    printf("\nThe Page Replacement Process is --\n");
    for (i = 0; i < n; i++)
    {
        flag = 0;
        for (j = 0; j < f; j++)
        {
            if (m[j] == rs[i]) {
                flag = 1; // Page found in memory
                break;
            }
        }

        if (flag == 0) // Page fault
        {
            pf++;
            m[count] = rs[i];
            count = (count + 1) % f;

            for (j = 0; j < f; j++)
                printf("\t%d", m[j]);

            printf("\tPF No.%d\n", pf);
        }
    }

    printf("\nThe number of Page Faults using FIFO is %d\n\n", pf);
    return 0;
}
