#include <stdio.h>

int main() {
    printf("Hello World\n");
    return 0;
}

// Here is my Age function
int age() {
    int age;
    printf("Enter your age:");
    scanf("%d", &age);
    printf("You are %d years old\n", age);
    return 0;
}