#include <stdio.h>
int RecursiveFactorial(int n){
    return (n == 1)? 1: n * RecursiveFactorial(n-1);
}

int main(){
    //Take input
    int input;
    scanf("%d", &input);
    //Print Factorial
    printf("%d\n",RecursiveFactorial(input));
    return 0;
}
