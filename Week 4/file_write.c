#include <stdio.h>

void WriteFile(const char *filename, int condition){
    FILE *fptr = fopen(filename,"w");
    if (fptr == NULL){
        printf("Error opening the files\n");
        return;
    }
    switch (condition)
    {
        case 1:
            fputs("Condition is 1\n", fptr);
            break;
        case 2:
            fputs("Condition is 2\n", fptr);
            break;
        default:
            fputs("Invalid Condition. \n", fptr);
    }
    fclose(fptr);
}

int main(){
    int condition;
    printf("Enter the condition: \n");
    scanf("%d", &condition);

    WriteFile("example2.txt",condition);
    printf("File example2.txt has been written\n");
}