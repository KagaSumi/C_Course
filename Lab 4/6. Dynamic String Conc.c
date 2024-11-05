#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char string1[100], string2[100]; // Declare arrays to hold the strings

    // Input first string
    printf("Enter the first string: ");
    scanf("%s", string1);

    // Input second string
    printf("Enter the second string: ");
    scanf("%s", string2);

    // Calculate the length of the concatenated string
    int length = strlen(string1) + strlen(string2) + 1; // +1 for the null terminator

    // Allocate memory for the concatenated result
    char *resultarr = malloc(length * sizeof(char));
    if (resultarr == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    // Concatenate string1 and string2 into resultarr
    strcpy(resultarr, string1);  // Copy string1 to resultarr
    strcat(resultarr, string2);  // Concatenate string2 to resultarr

    // Output the concatenated result
    printf("Concatenated string: %s\n", resultarr);

    // Free dynamically allocated memory
    free(resultarr);

    return 0;
}

