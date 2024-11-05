//
// Created by Quinten Leung on 2024-09-09.
//
#include <stdio.h>

int main() {
    printf("Welcome to Basic C Programming!\n");
    printf("Here is me using the %%d formatter for integers\nInteger: %d\n", 15);
    printf("This is how you format a float value using %%f\n Float: %f\n", 2.5124);
    printf("By using %%.2f we can also round the float\n Float: %.2f\n", 2.5124);
    printf("We can also format %%c characters\n Character: %c\n", "d");
    printf("We can also format %%s characters\n String: %s\n" "String");
    return 0;
}
