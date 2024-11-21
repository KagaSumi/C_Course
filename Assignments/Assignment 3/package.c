#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structures Definition
typedef struct {
    int trackingID;
    char priority[10];
    int hour;
    int minute;
} Package;

typedef struct node {
    Package value;
    struct node *next;
} Node;

// Prototypes
Node* create_node(Package value);
void freeNode(Node * head);
void log_error(FILE * log, int ID, const char *priority);
void read_file(FILE *file, FILE *log, Package **standard, Package **urgent, int *size_standard, int *size_urgent);
int compare_by_time(const void *a, const void *b);
void parse_collisions(Node* standard_head, Node* urgent_head);
void print_list(Node *head);

// Function to free all nodes in the list
void freeNode(Node* head) {
    Node* current = head;
    Node* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    return;
}

// Function to create a new node
Node* create_node(Package value) {
    Node* new_node = malloc(sizeof(Node));
    if (!new_node) {
        perror("Error Allocating Memory");
        exit(1);
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at a specific index
void insert_node(Node** head, Package value, int index) {
    Node* new_node = create_node(value);

    if (index == 0 || *head == NULL) {
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

// Function to print the list
void print_list(Node *head) {
    Node* current = head;
    while (current != NULL) {
        printf("Tracking ID: %d | Priority: %s | Delivery Window: %02d:%02d\n", current->value.trackingID,
               current->value.priority, current->value.hour, current->value.minute);
        current = current->next;
    }
}

// Function to log errors
void log_error(FILE *log, int ID, const char *priority) {
    char time_buffer[100]; // Buffer for timestamp (shouldn't be overflowing in the next couple of centuries)
    time_t raw_time = time(NULL);
    struct tm *time_info = localtime(&raw_time);
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", time_info);
    if (priority == NULL) { // Duplicate ID
        printf("Package ID %d: Skipped (Duplicate ID)\n", ID);
        fprintf(log, "[%s] Error: Duplicate Tracking ID for package ID %d\n", time_buffer, ID);
        return;
    }

    // Priority invalid
    printf("Package ID %d: Skipped (Invalid Priority)\n", ID);
    fprintf(log, "[%s] Error: Invalid Priority \"%s\" for package ID %d\n", time_buffer, priority, ID);
    return;
}

// Function to read package data from a file
void read_file(FILE *file, FILE *log, Package **standard, Package **urgent, int *size_standard, int *size_urgent) {
    int id_size = 0, id_arr_size = 2, id, hour, minutes;
    char buffer[10];
    int *id_arr = malloc(sizeof(int) * id_arr_size);
    if (!id_arr) {
        perror("Error allocating memory");
        exit(1);
    }

    int standard_capacity = 10; // Initial capacity for standard packages
    int urgent_capacity = 10;   // Initial capacity for urgent packages

    // Allocate initial memory for standard and urgent packages
    *standard = malloc(sizeof(Package) * standard_capacity);
    *urgent = malloc(sizeof(Package) * urgent_capacity);
    if (!(*standard) || !(*urgent)) {
        perror("Error allocating memory for packages");
        free(id_arr);
        exit(1);
    }

    while (fscanf(file, "%d %s %d:%d", &id, buffer, &hour, &minutes) != EOF) {
        // Check for duplicate IDs
        int duplicate = 0;
        for (int i = 0; i < id_size; i++) {
            if (id == id_arr[i]) {
                log_error(log, id, NULL);
                duplicate = 1;
            }
        }
        
        // Check if invalid priority level
        if (strcmp(buffer, "Urgent") != 0 && strcmp(buffer, "Standard") != 0) {
            log_error(log, id, buffer);
        } else {
            // This is now valid, so we will update the ID Array and add into the correct package list
            if (id_size == id_arr_size) {
                id_arr_size *= 2;
                int *tmp = realloc(id_arr, sizeof(int) * id_arr_size);
                if (!tmp) {
                    perror("Error reallocating memory");
                    free(id_arr);
                    free(*standard);
                    free(*urgent);
                    exit(1);
                }
                id_arr = tmp;
            }
            id_arr[id_size++] = id;

            // Process package based on priority
            if (strcmp(buffer, "Urgent") == 0) {
                // Expand urgent array if necessary
                if (*size_urgent == urgent_capacity) {
                    urgent_capacity *= 2;
                    Package *tmp = realloc(*urgent, sizeof(Package) * urgent_capacity);
                    if (!tmp) {
                        perror("Error reallocating memory for urgent packages");
                        free(id_arr);
                        free(*standard);
                        free(*urgent);
                        exit(1);
                    }
                    *urgent = tmp;
                }

                // Add to urgent array
                (*urgent)[*size_urgent].trackingID = id;
                strncpy((*urgent)[*size_urgent].priority, buffer, sizeof((*urgent)[*size_urgent].priority));
                (*urgent)[*size_urgent].hour = hour;
                (*urgent)[*size_urgent].minute = minutes;
                (*size_urgent)++;
            } else { // Standard Package
                // Expand standard array if necessary
                if (*size_standard == standard_capacity) {
                    standard_capacity *= 2;
                    Package *tmp = realloc(*standard, sizeof(Package) * standard_capacity);
                    if (!tmp) {
                        perror("Error reallocating memory for standard packages");
                        free(id_arr);
                        free(*standard);
                        free(*urgent);
                        exit(1);
                    }
                    *standard = tmp;
                }

                // Add to standard array
                (*standard)[*size_standard].trackingID = id;
                strncpy((*standard)[*size_standard].priority, buffer, sizeof((*standard)[*size_standard].priority));
                (*standard)[*size_standard].hour = hour;
                (*standard)[*size_standard].minute = minutes;
                (*size_standard)++;
            }
        }
    }
    free(id_arr); // Clean up allocated memory
}

// Comparison function for sorting by delivery time
int compare_by_time(const void *a, const void *b) {
    Package *packageA = (Package *)a;
    Package *packageB = (Package *)b;

    // Compare by hour first
    if (packageA->hour < packageB->hour) return -1;
    if (packageA->hour > packageB->hour) return 1;

    // If hours are the same, compare by minute
    if (packageA->minute < packageB->minute) return -1;
    if (packageA->minute > packageB->minute) return 1;

    return 0; // They are equal
}

// Function to handle collisions and update times
void parse_collisions(Node* standard_head, Node* urgent_head) {
    Node* current_standard = standard_head;
    Node* current_urgent = urgent_head;

    while (current_standard != NULL && current_urgent != NULL) {
        // Compare the delivery times (hour and minute) of standard and urgent packages
        if (current_standard->value.hour == current_urgent->value.hour &&
            current_standard->value.minute == current_urgent->value.minute) {

            // If there's a collision (same time), increment standard package by 5 minutes
            current_standard->value.minute += 5;

            // Handle minute overflow
            if (current_standard->value.minute >= 60) {
                current_standard->value.minute = 0;
                current_standard->value.hour += 1;
            }
        }
        else if (current_standard->value.hour < current_urgent->value.hour || 
                 (current_standard->value.hour == current_urgent->value.hour && 
                  current_standard->value.minute < current_urgent->value.minute)) {
            // If standard time is earlier than urgent, move standard pointer forward
            current_standard = current_standard->next;
        } 
        else {
            // If urgent time is earlier than standard, move urgent pointer forward
            current_urgent = current_urgent->next;
        }
    }
}

int main (){
    FILE * fptr = fopen("packages.txt", "r");
    if (!fptr){
        perror("Error opening packages.txt");
        exit(1);
    }
    FILE * log = fopen("error_log.txt","a");
    if (!log){
        perror("Error opening error log txt"); 
        exit(1);
    }
    int size_urgent = 0,size_standard = 0;

    Node* head_urgent= NULL;
    Node* head_standard = NULL;
    Package * urgent, * standard; // List for both Urgent and Standard
    // read and fill out above lists
    printf("Reading package data from file...\n");
    read_file(fptr,log,&standard,&urgent,&size_standard,&size_urgent);
    fclose(fptr);
    fclose(log);

    //Sort using qsort the packages
    printf("Sorting Packages...\n");
    qsort(urgent,size_urgent,sizeof(Package),compare_by_time);
    qsort(standard,size_standard,sizeof(Package),compare_by_time);

    //Create linked list for both standard and urgent based on sorted sort_linkedlist
    for(int i=0;i<size_urgent;i++){
        insert_node(&head_urgent, urgent[i], i);
    }
    for(int j=0;j<size_standard;j++){
        insert_node(&head_standard, standard[j], j);
    }

    // Lastly Loop to verify IF same time +5 on standard if no collision do this as a last pass over the sorted lists
    printf("Removing any collisions...\n");
    parse_collisions(head_standard, head_urgent);


    // Print out Linked List:
    printf("Sorted Package List:\n");
    print_list(head_urgent);
    print_list(head_standard);

    //Free Memory
    freeNode(head_urgent);
    freeNode(head_standard);
    return 0;
}
