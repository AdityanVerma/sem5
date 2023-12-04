#include <stdio.h>

int main() {
    int buffer[10], bufsize = 10, in = 0, out = 0, produce, consume, choice = 0;

    while (choice != 3) {
        printf("\n1.Produce \t 2. Consume \t3.Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if ((in + 1) % bufsize == out) {
                    printf("\nBuffer is Full");
                } else {
                    printf("\nEnter the value : ");
                    scanf("%d", &produce);
                    buffer[in] = produce;
                    in = (in + 1) % bufsize;
                }
                break;

            case 2:
                if (in == out) {
                    printf("\nBuffer is Empty");
                } else {
                    consume = buffer[out];
                    printf("\nThe consumed value is %d", consume);
                    out = (out + 1) % bufsize;
                }
                break;

            case 3:
                printf("\nExiting the program.\n");
                break;

            default:
                printf("\nInvalid choice. Enter 1, 2, or 3.\n");
                break;
        }
    }

    return 0;
}
