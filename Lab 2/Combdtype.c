#include <stdio.h>
int main() {
    char name[50];
    int age;
    float salary;
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your salary: ");
    scanf("%f", &salary);
    printf("Name %s, Age: %d, Salary %.2f\n",name,age,salary);
    return 0;
}