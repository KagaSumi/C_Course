#include <stdio.h>
#include <stdlib.h>

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
}

// Function to print the linked list
void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
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

    int val,idx;
    printf("Enter value of new node: ");
    scanf("%d", &val);
    printf("Enter index of new node: ");
    scanf("%d", &idx);
    insert_node(&head, val, idx-1);

    printf("Linked list:\n");
    print_list(head);

    // Free all allocated memory
    free_nodes(head);

    return 0;
}
