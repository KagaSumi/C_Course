#include <stdio.h>
#include <string.h>
// Read from a file and then replace the condition/content
// based on user input

/*
Same text file you have the following text
Condition is 1
Condition is 2

Use input: change condition 2 to 3
replace in the file
*/

void readFile(const char *filename)
{
    int cond1,cond_2;
    //Read file
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL){
        printf("Error Reading File");
        return NULL;
    }
    char buffer[100];
    while (fgets(buffer, 100,fptr) != NULL){
        printf("%s",buffer);
        fgets(cond1,)
    }
    fclose(fptr);

    //Get Target and value

    int target, value;
    printf("Which condition do you want to change?");
    scanf("%d", &target);
    printf("What do you want to change it to?");
    scanf("%d", &value);

    //Replace Value

    //Overwrite the file
    FILE *fptr = fopen(filename,"w");
    fputs(??,fptr);
    fclose(fptr);
}

int main()
{
    readFile("example2.txt");
}