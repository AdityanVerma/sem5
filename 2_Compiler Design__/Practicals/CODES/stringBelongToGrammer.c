#include <stdio.h>
#include <string.h>

// Function to check if the string belongs to the grammar
int isBelongToGrammar(char *str) {
    int len = strlen(str);
    int i = 0;

    // Starting with non-terminal S
    while (i < len) {
        if (str[i] == 'a') {
            i++;
        } else if (str[i] == 'b') {
            i++;
            while (i < len && str[i] == 'b') {
                i++;
            }
        } else {
            return 0; // Invalid character, not part of grammar
        }
    }

    // Check if the string ends in 'ab'
    if (i == len || (i == len - 1 && str[i] == 'a')) {
        return 1;
    }

    return 0;
}

int main() {
    char input[100];

    printf("\nThe grammar is :- \n S -> aS \n S -> Sb \n S -> ab\n\n");

    printf("Enter a string: ");
    scanf("%s", input);

    if (isBelongToGrammar(input)) {
        printf("String belongs to the grammar.\n\n");
    } else {
        printf("String does not belong to the grammar.\n\n");
    }

    return 0;
}
