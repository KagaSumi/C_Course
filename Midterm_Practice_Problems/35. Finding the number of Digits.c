#include <stdio.h>

void digit_count(int* count,int num){
    if (num ==0) return; // Check if at end
    *count +=1; //inc count
    digit_count(count, num/10); // floor div by 10 (remove 1 digit)
} 

int main(){
    //Take input
    int count =0,number;
    int * ptr = &count;
    scanf("%d",&number);
    
    digit_count(ptr,number);
    printf("%d\n", count);
    return 0;
}
