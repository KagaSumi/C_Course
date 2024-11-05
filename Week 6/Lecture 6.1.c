#include <stdio.h>

void decimalTobinary(int n){
    for (int i = 31; i>=0; i--){
        int bit = (n>>i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

int main(){
    decimalTobinary(30);
    return 0;
}
