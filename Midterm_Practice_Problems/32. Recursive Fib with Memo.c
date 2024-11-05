#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int fib(int n, int memo[]){
    if (n==0 || n== 1) return n; // Return 0 or 1 
    if (memo[n] != -1) return memo[n]; // If in List then use value
    memo[n] = fib(n-1,memo) + fib(n-2,memo);// Else Calculate and store in list
    return memo[n]; // Return Requested Value
}

int main(){
    int num;
    scanf("%d",&num);
    int* memo =  malloc(sizeof(int)*(num+1));
    // Create array to store Fib seq
    if (!memo){
        printf("Error Allocating Memory");
        return 1;
    }
    memset(memo, -1, sizeof(int)* (1+num));// Set to -1 as un-evaluated
                                           
    for (int i =0;i<num;i++){
        printf("%d ", fib(i,memo));
    }
    printf("\n");
    free(memo);
    return 0;
}

