#include "stdio.h"
#include <string.h>
int RecursivePalindrome(char *s, int start, int end){
    if (start >= end) return 1; //Reached middle meaning true palindrome
    else if(s[start] != s[end]) return 0; //If left and right don't match fail
    RecursivePalindrome(s,start+1,end-1);
}


int main(){
    char input[500];
    scanf("%s",input);
    (RecursivePalindrome(input, 0 , strlen(input)-1))? printf("YES\n"): printf("NO\n");
    return 0;
}
