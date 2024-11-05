#include <stdio.h>

int main(){
    FILE *input = fopen("grades.txt","r"); // Open Read File
    if (!input){
        printf("Error reading file");
        return 1;
    }
    FILE *output = fopen("output.txt","w"); // Open Write File
    if (!output){
        printf("Error opening file");
        return 1;
    }

    char name[100];
    int grade = 0, total = 0, count =0;
    while (fscanf(input, "%s", name) != EOF){ // Take Name
        while(fscanf(input, "%d", &grade) == 1) { // For as many Grade they have
            total += grade;  
            count++;
        }
        fprintf(output, "%s: %d\n", name, total/count); // Calculate Average
    }
    fclose(input);
    fclose(output);
    return 0;
}
