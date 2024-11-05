#include <math.h>
#include <stdio.h>

int isPrime(int n,int start){
    if (n%start==0) return 0; // Not Prime 
    if (start>sqrt(n)) return 1; // Is Prime
    isPrime(n, start+1); //Step up from 2-> Sqrt(n)
}

int main(){
    //Take input
   int input;
   scanf("%d", &input);

   //Print if Prime or not
   (isPrime(input,2)?printf("YES\n"):printf("NO\n"));
   return 0;
}
