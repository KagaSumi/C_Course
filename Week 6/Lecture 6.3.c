#include <stdio.h>
//shift - right and left:

int main(){
    int x =4;
    int leftshift= x<<1; //1 denotes how many positions we are shifting by
    int rightshift = x>>1; // Denoted by decimal
    //  rightshift2 = x>>2;
    printf("x<<1 = %d",leftshift); // 8
    printf("x>>1 = %d", rightshift); // 2
    return 0;
}
