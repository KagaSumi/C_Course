#include <stdio.h>

int sumDigits(int n){
    return (n< 10)? n :sumDigits(n%10+ sumDigits(n/10));
}

int main(){
    int input;
    scanf("%d",&input); // Take Input
    printf("%d\n", sumDigits(input)); // Print Output
    return 0;
}
