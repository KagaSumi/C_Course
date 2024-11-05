#include "stdio.h"

int main(){
    FILE * input = fopen("marks.txt","r"); // Open Read File
    if (!input){
        printf("Error reading file");
        return 1;
    }
    FILE * output = fopen("total_marks.txt","w"); // Open Write File
    if (!output){
        printf("Error opening file");
        return 1;
    }

    char name[50];
    int sum=0, tmp;

    while(fscanf(input,"%s",name)!= EOF){ // Read Name
        while(fscanf(input, "%d", &tmp)==1){ // Sum marks
            sum+=tmp;
        }
        fprintf(output, "%s: %d\n", name, sum); // Write output
        sum=0; // Reset sum
    }
    fclose(input);
    fclose(output);
    return 0;
}
