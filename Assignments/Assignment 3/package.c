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
void log_error_with_line(FILE* log, int line, int ID, const char* priority);
int read_file(FILE* file, FILE* log, Package** standard, Package** urgent, int* size_standard, int* size_urgent);
int compare_by_time(const void *a, const void *b);
void parse_collisions(Node* standard_head, Node* urgent_head);
void print_list(Node *head);
void resize_array(Package** array, int* capacity);
int is_valid_priority(const char* priority);

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
void log_error_with_line(FILE *log,int line, int ID, const char *priority) {
    char time_buffer[100]; // Buffer for timestamp (shouldn't be overflowing in the next couple of centuries)
    time_t raw_time = time(NULL);
    struct tm *time_info = localtime(&raw_time);
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", time_info);
    if (priority == NULL) { // Duplicate ID
        printf("Line Number: %d Package ID %d: Skipped (Duplicate ID)\n",line, ID);
        fprintf(log, "[%s] Error: Duplicate Tracking ID for package ID %d Line#%d\n", time_buffer, ID,line);
        return;
    }

    // Priority invalid
    printf("Line Number: %d Package ID %d: Skipped (Invalid Priority)\n",line, ID);
    fprintf(log, "[%s] Error: Invalid Priority \"%s\" for package ID %d Line# %d\n", time_buffer, priority, ID, line);
    return;
}
void resize_array(Package** array, int* capacity) {
    *capacity *= 2;
    Package* temp = realloc(*array, sizeof(Package) * (*capacity));
    if (!temp) {
        perror("Error reallocating memory");
        free(*array);
        exit(1);
    }
    *array = temp;
}
int is_valid_priority(const char* priority) {
    const char* valid_priorities[] = {"Urgent", "Standard"};
    for (int i = 0; i < sizeof(valid_priorities) / sizeof(valid_priorities[0]); i++) {
        if (strcmp(priority, valid_priorities[i]) == 0) {
            return 1;
        }
    }
    return 0;
}


// Function to read package data from a file
int read_file(FILE* file, FILE* log, Package** standard, Package** urgent, int* size_standard, int* size_urgent) {
    int id_size = 0, id_arr_size = 2, id, hour, minutes;
    char buffer[10];
    int* id_arr = malloc(sizeof(int) * id_arr_size);
    if (!id_arr) {
        perror("Error allocating memory for ID array");
        return -1;
    }

    int standard_capacity = 10, urgent_capacity = 10;
    *standard = malloc(sizeof(Package) * standard_capacity);
    *urgent = malloc(sizeof(Package) * urgent_capacity);
    if (!(*standard) || !(*urgent)) {
        perror("Error allocating memory for packages");
        free(id_arr);
        return -1;
    }

    int line_number = 0;
    while (fscanf(file, "%d %s %d:%d", &id, buffer, &hour, &minutes) != EOF) {
        line_number++;

        // Check for duplicate ID
        int duplicate = 0;
        for (int i = 0; i < id_size; i++) {
            if (id == id_arr[i]) {
                log_error_with_line(log, line_number, id, NULL);
                duplicate = 1;
                break;
            }
        }
        if (duplicate) continue;

        // Validate priority
        if (!is_valid_priority(buffer)) {
            log_error_with_line(log, line_number, id, buffer);
            continue;
        }

        // Add ID to id_arr
        if (id_size == id_arr_size) {
            id_arr_size *= 2;
            int* tmp = realloc(id_arr, sizeof(int) * id_arr_size);
            if (!tmp) {
                perror("Error reallocating memory for ID array");
                free(id_arr);
                free(*standard);
                free(*urgent);
                return -1;
            }
            id_arr = tmp;
        }
        id_arr[id_size++] = id;

        // Add package to the appropriate list
        Package pkg = {id, "", hour, minutes};
        strncpy(pkg.priority, buffer, sizeof(pkg.priority));
        if (strcmp(buffer, "Urgent") == 0) {
            if (*size_urgent == urgent_capacity) {
                resize_array(urgent, &urgent_capacity);
            }
            (*urgent)[(*size_urgent)++] = pkg;
        } else {
            if (*size_standard == standard_capacity) {
                resize_array(standard, &standard_capacity);
            }
            (*standard)[(*size_standard)++] = pkg;
        }
    }

    free(id_arr);
    return 0;
}

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
