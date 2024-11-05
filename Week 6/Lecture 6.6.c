#include <stdio.h>

int power(int base, int exp){
    if (exp == 0)return 1;
    return base *power(base,exp-1);
}


int main(){
    printf("%d\n",power(2,3));
    return 0;
}
