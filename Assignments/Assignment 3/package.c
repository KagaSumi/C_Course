#include <time.h>
#include <stdlib.h>
#include <stdio.h>

//Structures Definition
typedef struct{
    int trackingID;
    char priority[10];
    char deliverWindow[6];
    int hour;
    int minute;

}Package;

typedef struct node{
    Package current;
    struct node * next;
}Node;

//Prototypes
Node* create_node(Package current,Node* next);
void sort_linkedlist(Node head);
void display_linkedlist(Node head);
void freeNode(Node * head);
void log_error(FILE* log);

void freeNode(Node* head){
    if(head == NULL) return;
    Node* tmp = head;
    head =  head->next;
    free(tmp);
    freeNode(head);
}


//Store each in Linked List
void create_linked_list(FILE * packages, Node* head){
    Node* current;
    //For line 
    Package pkg_cur;
    if(head == NULL){
        head = create_node(pkg_cur,NULL);
        current = head;
    }
    current = create_node(pkg_cur, current);

    return;
}

Node* create_node(Package current, Node* before) {
    Node* new_node;
    if (before){
        before->next = (Node*)malloc(sizeof(Node));
        new_node = before->next; //This is if it is a child node
    }
    else{
        new_node = (Node*)malloc(sizeof(Node)); // This is now my head, no other reference.
    }

    if (new_node == NULL) {
        perror("Error Creating Node");
        exit(1);
    }

    // Initialize the node fields (tail)
    new_node->current = current;
    new_node->next = NULL;

    return new_node;
}

//Sorts by priority

void sort_linkedlist (Node head){
    return;
}
//Validate input and Log Error
int main (){
    FILE * fptr = fopen("packages.txt", "r");
    if (!fptr){
        perror("Error opening packages.txt");
        exit(1);
    }
    Node* head_urgent,head_standard,current_urgent,current_standard;
    //TODO Can use qsort before
    //TODO Can have two linked list (urgent and Standard)
    //DO use realloc and log urgent and standard and qsort based and ids seen
    //IF same time +5 on standard if no collision do this as a last pass over the sorted lists

    return 0;
}
