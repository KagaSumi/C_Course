#include <stdio.h>
int GCD (int a, int b){
    return (b==0) ? a : GCD(b, a%b);
}

int main(){
    int num1, num2, result;
    FILE *input = fopen("gcd_input.txt","r");// Open Read File
    if (!input) {
        printf("Error opening input file");
        return 1;
    }
    // Get Values
    fscanf(input,"%d",&num1);
    fscanf(input,"%d",&num2);
    fclose(input);

    result = GCD(num1,num2);
    FILE *output = fopen("gcd_output.txt", "w"); // Open Write File
    if (!output){
        printf("Error with gcd_output.txt");
        return 1;
    }
    fprintf(output,"%d",result);
    fclose(output);
    return 0;
}
