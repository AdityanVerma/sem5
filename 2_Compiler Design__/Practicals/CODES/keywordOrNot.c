#include <stdio.h>
#include <string.h>

int containsKeyword(const char *str, const char *keyword) {
    if (strstr(str, keyword) != NULL) {
        return 1; // Keyword found in the string
    }
    return 0; // Keyword not found in the string
}

int main() {
    char input[500];
    char keyword[20];

    printf("\nEnter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline from fgets input

    printf("Enter the keyword to check: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0'; // Remove newline from fgets input

    if (containsKeyword(input, keyword)) {
        printf("\nThe string contains the keyword '%s'.\n", keyword);
    } else {
        printf("\nThe string does not contain the keyword '%s'.\n", keyword);
    }

    printf("\n");

    return 0;
}
