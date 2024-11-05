#include <stdio.h>
int factorial(int base, int power){
    return (power==0)?1:base*factorial(base,power-1); 
}

int main(){
    //Get input
    int base, power,result;
    scanf("%d",&base);
    scanf("%d",&power);

    result = factorial(base,power); 
    printf("%d\n",result);
    return 0;
}
