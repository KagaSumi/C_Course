#include <stdio.h>
int main(){
    //Take Tax Value
    double tax;
    scanf("%lf", &tax);

    FILE *input = fopen("sales.txt", "r"); // Open Read File
    if (!input){
        printf("Error reading file");
        return 1;
    }
    FILE *output = fopen("total_prices.txt", "w"); // Open Write File
    if (!output){
        printf("Error opening file");
        return 1;
    }

    char product[50];
    double price, amount;
    while (fscanf(input,"%s %lf %lf", product, &price, &amount)!= EOF){ //For Each Line Take Values
        fprintf(output, "%s: %.2lf\n", product, price*amount*(1+tax));// Calculate Tax and print into Write File
    }
    fclose(input);
    fclose(output);
    return 0;
}
