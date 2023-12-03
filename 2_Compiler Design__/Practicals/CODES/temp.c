#include <ctype.h>
#include <stdio.h>
#include <string.h>

void follow(char c);
void followfirst(char c, int c1, int c2);

// The total number of productions
int count = 8;

// The production rules
char production[10][10];
char f[10];
int m = 0;

int main(int argc, char **argv) {
    // Your production rules initialization here...

    printf("Follow Sets:\n");
    for (int e = 0; e < count; e++) {
        char ck = production[e][0];

        if (!isupper(ck))
            continue;

        int ptr = -1;
        int point1 = 0;
        int point2 = 0;
        int xxx = 0;
        char donee[count];

        for (int kay = 0; kay <= ptr; kay++)
            if (ck == donee[kay])
                xxx = 1;

        if (xxx == 1)
            continue;

        follow(ck);
        ptr += 1;
        donee[ptr] = ck;

        printf(" Follow(%c) = { ", ck);
        for (int i = 0; i < m; i++) {
            int chk = 0;

            for (int lark = 0; lark < point2; lark++) {
                if (f[i] == production[point1][lark]) {
                    chk = 1;
                    break;
                }
            }

            if (chk == 0) {
                printf("%c, ", f[i]);
                production[point1][point2++] = f[i];
            }
        }
        printf(" }\n\n");
        m = 0;
        point1++;
    }
    return 0;
}

void follow(char c) {
    if (production[0][0] == c) {
        f[m++] = '$';
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 2; j < 10; j++) {
            if (production[i][j] == c) {
                if (production[i][j + 1] != '\0') {
                    followfirst(production[i][j + 1], i, (j + 2));
                }

                if (production[i][j + 1] == '\0' && c != production[i][0]) {
                    follow(production[i][0]);
                }
            }
        }
    }
}

void followfirst(char c, int c1, int c2) {
    if (!(isupper(c))) {
        f[m++] = c;
    } else {
        int i = 0, j = 1;
        // Follow set of c
        while (production[c1][0] != production[i][0])
            i++;

        while (production[i][j] != '!') {
            if (production[i][j] != '#') {
                f[m++] = production[i][j];
            } else {
                if (production[c1][c2] == '\0') {
                    follow(production[c1][0]);
                } else {
                    followfirst(production[c1][c2], c1, c2 + 1);
                }
            }
            j++;
        }
    }
}
