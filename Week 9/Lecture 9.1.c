#include <stdio.h>
#include "stdlib.h"

typedef struct {
    char name[50];
    int ID;
    float *grades;
    int gradeCount;
} Student;

void inputStudentData(Student *s)
{
    printf("Enter the students name\n");
    scanf("%s", s->name);

    printf("\n Enter the Student's ID\n");
    scanf("%d", &s->ID);

    printf("\nEnter the number of grades\n");
    scanf("%d", &s->gradeCount);
    if (s->gradeCount<1){
        perror("Value Error: Student cannot have 0 grades");
        exit(1);
    }

    s->grades = malloc(s->gradeCount * sizeof(float));
    if(!s->grades){
        perror("Memory Allocation Failed");// Print Error on failed memory allocation
        exit(1); // Exits with Error Code 1 
    }

    printf("\nEnter the grades\n");
    for (int i=0;i< s->gradeCount;i++){
        scanf("%f", &s->grades[i]);
    }
}

void displayStudentData(const Student *s){
    printf("\nStudent: %s (ID: %d\n", s->name, s->ID);
    printf("\nGrades:\n");
    float sum = 0;
    for (int i=0;i<s->gradeCount;i++){
        printf("%.2f", s->grades[i]);
        sum+=s->grades[i];
    }
    printf("\nAvg of the grades: %.2f\n",sum/s->gradeCount);

}
void freeStudent(Student *s){
    free(s->grades);
}

int main(){

    Student Student1;
    inputStudentData(&Student1);
    displayStudentData(&Student1);
    freeStudent(&Student1);
    return 0;



}

