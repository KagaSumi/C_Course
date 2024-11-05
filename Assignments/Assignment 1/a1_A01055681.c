#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int parse_arguments(int argc, char *argv[], int *line_length, char **filename);
char* read_file_content(const char *filename, long *file_size);
int count_words(const char *content, long file_size);
int parse_words(const char *content, long file_size, int line_length, char word_list[][file_size], int *word_length_list);

int main(int argc, char *argv[]) {
    int line_length;
    char *filename;
    
    if (parse_arguments(argc, argv, &line_length, &filename) != 0) {
        return 1;
    }

    long file_size;
    char *content = read_file_content(filename, &file_size);
    if (!content) {
        return 1;
    }

    int word_count = count_words(content, file_size);

    char word_list[word_count][file_size];
    int word_length_list[word_count];

    if (parse_words(content, file_size, line_length, word_list, word_length_list) != 0) {
        free(content); //If too long for given line_length throw error and exit
        return 1;
    }
    free(content); // Done reading the file

    // ----- print out the words ---
    
    int current_word = 0;
    while (current_word < word_count) {
        int line_chars = 0;
        int words_in_line = 0;
        int line_start = current_word;

        // Count words that fit in this line
        while (current_word < word_count && 
               line_chars + word_length_list[current_word] + (words_in_line > 0 ? 1 : 0) <= line_length) {
            line_chars += word_length_list[current_word] + (words_in_line > 0 ? 1 : 0);
            words_in_line++;
            current_word++;
        }

        // Calculate spaces to distribute
        int spaces_to_distribute = line_length - line_chars;
        int gaps = words_in_line - 1;

        // Handle justification
        if (words_in_line == 1) {
            // Center single word
            int left_spaces = spaces_to_distribute / 2;
            printf("%*s%s%*s\n", left_spaces, "", word_list[line_start], 
                   spaces_to_distribute - left_spaces, "");
        } else {
            // Distribute spaces between words
            int base_spaces = gaps > 0 ? spaces_to_distribute / gaps : 0;
            int extra_spaces = gaps > 0 ? spaces_to_distribute % gaps : 0;// Remainder spaces

            // For words
            for (int i = 0; i < words_in_line; i++) {
                printf("%s", word_list[line_start + i]);

                // Check last word of the line 
                // If no hyphen print any remaining extra spaces
                if (i == words_in_line - 1 ){
                    if(word_list[line_start + i][word_length_list[line_start+i] - 1] != '-'){
                        (extra_spaces>0)? printf(" ") : 0;
                        extra_spaces--;
                    }
                }
                else if (i < words_in_line - 1) {
                    if(word_list[line_start + i][word_length_list[line_start+i] - 1] != '-'){
                        printf(" ");
                        int spaces = base_spaces + (extra_spaces > 0 ? 1 : 0);
                        for (int s = 0; s < spaces; s++) {
                            printf(" ");
                        }
                    }
                    extra_spaces--;
                }
            }
            printf("\n");
        }
    }
    
    return 0;
}

// Check User Passed in variables
int parse_arguments(int argc, char *argv[], int *line_length, char **filename) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <line_length> <filename>\n", argv[0]);
        return 1;
    }

    *line_length = atoi(argv[1]);
    *filename = argv[2];
    return 0;
}

// Read the file content to fill out a character array
char* read_file_content(const char *filename, long *file_size) {
    FILE *fptr = fopen(filename, "r");
    if (!fptr) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    //Calculate file_size
    fseek(fptr, 0, SEEK_END);
    *file_size = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    //Create a char array to hold all the characters in the file
    //Load file contents into content array
    char *content = (char *)malloc(*file_size + 1);
    fread(content, 1, *file_size, fptr);
    content[*file_size] = '\0';

    fclose(fptr);
    return content;
}


// Count how many words are in the file
// I am treating - as the end of a word as well
int count_words(const char *content, long file_size) {
    int word_count = 0;
    for (long i = 0; i < file_size; i++) {
        if (content[i] == ' ' || content[i] == '-' || content[i] == '\n') {
            word_count++;
        }
    }

    //Edge Case: file doesn't ended with a  or new line character just to make sure we count and look into that 
    if (file_size > 0 && content[file_size - 1] != ' ' && content[file_size - 1] != '\n') {
        word_count++;
    }

    return word_count;
}

// Verify if any word is too long for line_length and load each word into a 2D char array
// as well as keeping track of how long each word is for later
int parse_words(const char *content, long file_size, int line_length, char word_list[][file_size], int *word_length_list) {
    int char_idx = 0;
    int word_counter = 0;

    for (long i = 0; i < file_size; i++) {
        if (content[i] == ' ' || content[i] == '\n') {
            if (char_idx > 0) {
                if (char_idx > line_length) {
                    fprintf(stderr, "Error. The word processor can't display the output.\n");
                    return 1;
                }
                word_list[word_counter][char_idx] = '\0';
                word_length_list[word_counter] = char_idx;
                word_counter++; // Inc for next word 
                char_idx = 0; // Reset for the next word
            }
            // Handle hyphen at the end of a word
        } else if(content[i] == '-'){
            word_list[word_counter][char_idx] = content[i]; // Add character to the current word
            char_idx++;
            word_list[word_counter][char_idx]='\0';
            word_length_list[word_counter] = char_idx;
            word_counter++;
            char_idx = 0;
        }
        else {
            word_list[word_counter][char_idx++] = content[i]; // Add character to the current word
        }
    }

    // Add the last word if any
    if (char_idx > 0) {
        word_list[word_counter][char_idx] = '\0';
        word_length_list[word_counter] = char_idx;
    }

    return 0;
}

