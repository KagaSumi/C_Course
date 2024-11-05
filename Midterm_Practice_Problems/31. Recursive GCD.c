#include <stdio.h>
int gcd (int a, int b){
    return (b==0) ? a : gcd(b, a%b);
}

int main(){
    //Take Input
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    //Print Largest GCD
    printf("%d\n", gcd(a,b));

    return 0;
}
