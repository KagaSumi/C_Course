#include "stdio.h"
struct Student {
    int id;   
    char name[50];
    float gpa;

};
int main(){
    struct Student student1;
    printf("enter the id of student1\n");
    scanf("%d",&student1.id);

    printf("\nEnter the studnet students name\n");
    scanf(" %[^\n]%*c", student1.name);

    printf("Enter the gpa\n");
    scanf("%f",&student1.gpa);

    printf("\nStudent ID: %d\n", student1.id);
    printf("\nStudent Name: %s\n", student1.name);
    printf("\nStudent GPA: %.2f\n", student1.gpa);
}
