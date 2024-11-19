#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int value;
    struct node* next;
} Node;

// Function to create a new node
Node* create_node(int value) {
    Node* new_node = malloc(sizeof(Node));
    if (!new_node) {
        perror("Error Allocating Memory");
        exit(1);
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Function to free all nodes in the list
void free_nodes(Node* head) {
    Node* current = head;
    Node* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    return;
}

// Function to insert a node at a specific index
void insert_node(Node** head, int value, int index) {
    Node* new_node = create_node(value);

    if (index == 0) {
        new_node->next = *head;
        *head = new_node;
    } else {
        Node* current = *head;
        for (int i = 0; current != NULL && i < index - 1; i++) {
            current = current->next;
        }

        if (current == NULL) {
            printf("Index out of bounds\n");
            free(new_node);
        } else {
            new_node->next = current->next;
            current->next = new_node;
        }
    }
    return;
}

// Function to print the linked list
void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
    return;
}

    
void sort_list(Node* head){
    if (head == NULL || head->next == NULL) {
        return; // No sorting needed for empty or single-element lists
    }

    int swapped;
    Node* ptr1;
    Node* lptr = NULL; // Last sorted node

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) { // Traverse until the last sorted node
            if (ptr1->value < ptr1->next->value) {
                // Swap the values
                int temp = ptr1->value;
                ptr1->value = ptr1->next->value;
                ptr1->next->value = temp;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1; // Update the last sorted node
    } while (swapped);
}

void delete_node(Node** head, int index){
    Node * temp;
    if (*head == NULL) return;
    if (index == 0){
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    else{
        Node* current = *head;
        for (int i=0; current!= NULL&&i<index-1;i++){
            current = current->next;
        }

        if (current == NULL || current->next == NULL) {
            printf("Index out of bounds\n");
            return;
        }

        //Current | Target | Temp
        temp = current->next;
        current->next = temp->next;
        free(temp);

    }
    return;
}
void sum_nodes(Node* head,int index, int* sum){
    Node* current = head;
    for (int i=0;i<index-1 && current!=NULL;i++){
        *sum += current->value;
        current= current->next;
    }
    if (current== NULL){
        printf("Index out of bounds error\n");
        exit(0);
    }
    *sum += current->value;
    return;
}

int main() {
    int size, tmp;
    Node* head = NULL;

    printf("Enter the size of the list: ");
    scanf("%d", &size);

    printf("Enter %d values:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &tmp);
        insert_node(&head, tmp, i);  // Insert nodes at the end of the list
    }

    printf("Linked list:\n");
    print_list(head);

    int idx,sum=0;
    printf("Enter Position to sum up to: ");
    scanf("%d",&idx);

    sum_nodes(head,idx,&sum);
    printf("Sum of Nodes: %d\n",sum);

    // Free all allocated memory
    free_nodes(head);

    return 0;
}
