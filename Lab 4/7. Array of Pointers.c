#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    int num_words;
    char **words;
    char temp_word[1000]; //Max Word Length

    // Get the number of words from the user
    printf("Enter the number of words: ");
    scanf("%d", &num_words);

    // Consume the newline character left by scanf
    getchar();

    // Allocate memory for the array of pointers
    words = (char **)malloc(num_words * sizeof(char *));
    if (words == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Get the words from the user
    printf("Enter the words: ");
    for (int i = 0; i < num_words; i++) {
        scanf("%s", temp_word);
        
        // Allocate memory for each word and copy it
        words[i] = (char *)malloc((strlen(temp_word) + 1) * sizeof(char));
        if (words[i] == NULL) {
            printf("Memory allocation failed for word %d.\n", i + 1);
            // Free previously allocated memory
            for (int j = 0; j < i; j++) {
                free(words[j]);
            }
            free(words);
            return 1;
        }
        strcpy(words[i], temp_word);
    }

    // Print the entered words
    printf("You entered:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);
    }

    // Free the allocated memory
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}
