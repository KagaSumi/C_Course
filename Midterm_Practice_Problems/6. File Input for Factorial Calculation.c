#include <stdio.h>

int factorial(int n) {
    return (n==1)? 1: n* factorial(n-1); 
}

int main(){
    int num;
    FILE *input = fopen("factorial_input.txt","r");// Open Read File
    if (!input){
        printf("Error opening input file");
        return 1;
    }
    fscanf(input,"%d", &num);
    fclose(input);

    num = factorial(num);
    FILE *output = fopen("factorial_output.txt", "w"); // Open Write File
    if (!output){
        printf("Error output file");
        return 1;
    }
    fprintf(output,"%d",num);
    fclose(output);
    return 0;
}

