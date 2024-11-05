#include "stdio.h"
#include "stdlib.h"

#define MAX_NAME_LENGTH 50

typedef struct { 
    char name[MAX_NAME_LENGTH];
    int ID;
    float *grades;
    int gradeCount;
} Student;

void inputStudentData(Student *s)
{
    printf("Enter name: ");
    scanf(" %[^\n]%*c", s->name); 
    printf("\nEnter the student ID: ");
    scanf("%d", &s->ID);
    printf("\nEnter the number of grades: ");
    scanf("%d", &s->gradeCount);
    s->grades = malloc(s->gradeCount * sizeof(float));
    if(!s->grades){
        printf("Memory Allocation Failed");
        return;
    }

    for (int i=0;i< s->gradeCount;i++){
        printf("Enter grade %d: ", i+1);
        scanf("%f", &s->grades[i]);
    }
}

void displayStudentData(const Student *s){
    printf("Student: %s (ID: %d)\n", s->name, s->ID);
    printf("Grades: ");
    float sum = 0;
    for (int i=0;i<s->gradeCount;i++){
        printf("%.0f ", s->grades[i]);
        sum+=s->grades[i];
    }
    printf("\nAvg of the grades: %.2f\n\n",sum/s->gradeCount);

}
void freeStudent(Student *s){
    free(s->grades);
}

void Addanother(char * state){
    printf("Add another Student? (y/n)\n");
    scanf(" %c", state);
    if (*state == 'y' || *state == 'n') return;
    else {
        printf("Invalid input. Please enter 'y' or 'n'.\n");
        Addanother(state);
    } 
}

int main(){
    int numberofStudent;
    char state = ' '; //Initialize Blank Value

    printf("Enter number of students: ");
    scanf("%d", &numberofStudent);
    printf("\n");

    //Allocate Memory of all students
    Student *list= malloc(sizeof(Student)*numberofStudent);
    if (!list){
        perror("Memory Allocation Error");
        exit(1);
    }

    for (int i=0;i<numberofStudent;i++){
        printf("Entering data for student %d:\n",i+1);
        inputStudentData(&list[i]);
        displayStudentData(&list[i]);
    }

    //Repeat? or Quit
    Addanother(&state);
    while (state == 'y'){
        numberofStudent++;
        list = realloc(list, sizeof(Student)*numberofStudent);
        if (!list){
            perror("Error reallocating memory");
            exit(1);
        }
        printf("Entering data for student %d:\n",numberofStudent);
        inputStudentData(&list[numberofStudent-1]);

        printf("\nStudent Records:\n");
        for (int i=0;i<numberofStudent;i++){
            displayStudentData(&list[i]);
        }
        Addanother(&state);
    }
    
    //Memory Clean Up
    for (int i=0;i<numberofStudent;i++) freeStudent(&list[i]);
    free(list);
    return 0;
}

