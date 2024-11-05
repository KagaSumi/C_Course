#include <stdio.h>
#include <string.h>

void reverseString(char* s,int start,int end){
    if (start>=end) return; // When  middle return
    char tmp = s[start]; // Hold Value
    s[start] = s[end]; // Swap
    s[end] = tmp; // Swap
    reverseString(s, start+1, end-1); // Step Throught
}
int main(){
    // Take input
    char test[500];
    scanf("%s",test);

    reverseString(test,0,strlen(test)-1);
    printf("%s\n",test);
    return 0;
}
