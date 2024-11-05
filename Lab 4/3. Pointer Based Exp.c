#include <stdio.h>
#include <stdlib.h>
int main(){
    //Initalize Var and get user input
    int base,exponent;
    printf("Enter the base: ");
    scanf("%d", &base);
    printf("Enter the exponent (n): ");
    scanf("%d", &exponent);
    int * result = malloc(sizeof(int));
    if (!result){
        printf("Error alllocating memory");
        return 1;
    }
    *result = 1;
    for (int i=0;i<exponent;i++){
        *result *= base;
    }
    
    // Load the base into result
    printf("%d raise to the power %d is %d\n", base,exponent,*result);
    return 0;
};
