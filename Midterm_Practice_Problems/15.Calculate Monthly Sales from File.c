#include "stdio.h"
int main(void)
{
    FILE *input = fopen("salary.txt","r"); // Open Read file
    if(!input){
        printf("Error reading File\n");
        return 1;
    }
    FILE *output = fopen("total_salaries.txt","w"); // Open Write File
    if(!output){
        printf("Error Opening File");
        return 1;
    }

    char name[50];
    int monthly_salary, months;
    while(fscanf(input, "%s %d %d", name, &monthly_salary, &months)!=EOF){ //Read entire line
        fprintf(output,"%s: %d\n", name, monthly_salary*months); // Write Entire Line
    }

    fclose(input);
    fclose(output);
    return 0;
}
