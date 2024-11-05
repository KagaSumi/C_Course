#include <math.h>
#include <stdio.h>

int isPrime(int n){
    for (int i=2; i<= sqrt(n);i++){
        if (n%i==0)return 0; //Not Prime
    }
    return 1; // Prime
}

int main(){
    //Take input
    int start,end,count=0;
    scanf("%d",&start);
    scanf("%d",&end);

    // If Prime in range add to count 
    for (int i = start;i<end;i++){
        (isPrime(i))? count++: 0;
    }
    printf("%d\n", count);
}
