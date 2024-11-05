#include <stdio.h>

int main(){
    FILE *input = fopen("inventory.txt","r"); //Open Read File 
    if (!input){
        printf("Error reading file");
        return 1;
    }
    FILE *output = fopen("inventory_value.txt","w"); // Open Write File
    if (!output){
        printf("Error reading file");
        return 1;
    }

    char product[50];
    double price, quantity;

    while(fscanf(input, "%s %lf %lf",product, &price, &quantity)!=EOF){ // Read Entire Line
        fprintf(output, "%s: %.2f\n",product, price*quantity); // Write Line
    }

    fclose(input);
    fclose(output);
    return 0;
}
