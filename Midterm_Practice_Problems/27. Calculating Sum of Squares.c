#include <stdio.h>

void sum_square(int* sum, int num){
    if (num ==1){
        *sum+=1; // 1*1 = 1 
        return;
    }
    *sum+= num*num; // Add square to sum
    sum_square(sum,num-1); // Step down
}

int main(){
    //Take input
    int base, sum=0;
    int* ptr = &sum; //Sum by pointer
    scanf("%d", &base);

    sum_square(ptr, base);
    printf("%d\n",sum);
    return 0;
}
