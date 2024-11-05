#include <stdio.h>
int main(){
    // Try accessing file
    FILE *fptr = fopen("arr.txt","r");
    if (fptr == NULL){
        printf("Error parsing file \n");
        return 1;
    }

    // Print Header
    printf("Matrix from fie: \n");
    
    char buffer[100]; // Create buffer
    // Get information and print
    while (fgets(buffer, 100, fptr)){
        printf("%s",buffer);
    }
    return 0;
}