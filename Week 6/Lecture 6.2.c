#include <stdio.h>

//bitwise and, or xor,op

int main(){
    int a = 5;
    int b = 3;

    int andResult = a&b;// 1

    int orResult = a|b; // 7

    int xorResult = a^b; // 6

    printf("a AND b is %d\n", andResult);
    printf("a or b is %d\n", orResult);
    printf("a xor b is %d\n", xorResult);

    return 0;

}
