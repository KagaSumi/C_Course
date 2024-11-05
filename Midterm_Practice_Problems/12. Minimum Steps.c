#include <stdio.h>

int main(){
    int input, counter=0;
    scanf("%d",&input);
    while (input !=1){
        input--;// Subtract by 1
        input = (input%2==0)? input/2:input;// Divide by 2 if possible
        counter++; // Inc Step Count
    }

    printf("%d\n",counter); //Print Count
    return 0;
}
