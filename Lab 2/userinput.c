#include <stdio.h>
int main() {
    int age;
    float salary;
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your salary: ");
    scanf("%f", &salary);
    printf("Your age is %d\n", age);
    printf("Your salary is %.2f\n", salary);
    return 0;
}