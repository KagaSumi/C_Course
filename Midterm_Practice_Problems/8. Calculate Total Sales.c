#include <stdio.h>

int main(){
    double sum =0;
    FILE *input = fopen("sales.txt","r"); // Open Read File
    if (!input){
        printf("Error opening sales.txt");
        return 1;
    }

    double temp;
    // Add up total Sales
    while(fscanf(input, "%lf", &temp)!= EOF){
        sum += temp;
    }
    fclose(input);

    FILE *output = fopen("total_sales.txt","w"); // Open and Write the total to file
    if (!output){
        printf("Error with output file");
        return 1;
    }
    fprintf(output,"%.2lf",sum);
    fclose(output);

    return 0;
}

