#include <stdio.h>
int main() {
    //Initialize Counter for word character count 
    int counter = 0;
    
    // Open File & Exit if error
    FILE *fptr = fopen("word.txt","r");
    if (fptr == NULL){
        printf("Error opening file!\n");
        return 1;
    }

    // Create Buffer for string input
    char buffer[100];
    while (fgets(buffer,100,fptr)){
        
        // Walk through file and stop once reach Null Character
        for (int i=0; buffer[i]!= '\0'; i++){
            counter++;
        }

    }

    //Close File + Print
    fclose(fptr);
    printf("Number of characters: %d\n", counter);
    return 0;
}