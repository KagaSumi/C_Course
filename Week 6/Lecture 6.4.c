#include <stdio.h>
//Recruision
//use cases - factorial and fib series
//for next lecture - can only use value of 12 in this function
//
//Since a integer is only assigned 32 bits with 1 bit for signing. We have realistically 31 bits of data that we can hold
//When we consider 
//31 bits = 2,147,483,648
//factorial(12) = 479,001,600
//Factorial(13) = 6,227,020,800
//We are unable to represent 13! in 31 bits 
#include <sys/types.h>
int factorial (int n){
    if (n == 1) return 1;
    return n * factorial(n-1);
}

int main(){
    printf("%d\n", factorial(5));
    return 0;
}
