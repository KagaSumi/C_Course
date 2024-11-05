#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[60];
    float price;
    int quantity;
    char productID[10];
} Product;

void inputProduct(Product *p) {
    printf("Enter Product Name: ");
    scanf("%s", p->name);

    printf("Enter Price: ");
    scanf("%f", &p->price);

    printf("Enter Quantity: ");
    scanf("%d", &p->quantity);

    printf("Product ID: ");
    scanf("%s", p->productID);
}

void displayProduct(Product *p) {
    printf("Product Name: %s\n", p->name);
    printf("Price: %.2f\n", p->price);
    printf("Quantity: %d\n", p->quantity);
    printf("Product ID: %s\n", p->productID);
}

int countLine(FILE *file) {
    int count = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') count++;
    }
    rewind(file);
    return count;
}

void parseLog(Product** inventory, int* size) {
    FILE *log = fopen("inventory.txt", "r");
    if (!log) {
        perror("Error reading file");
        exit(1);
    }

    *size = countLine(log);
    *inventory = malloc(*size * sizeof(Product));
    if (!*inventory) {
        perror("Error allocating memory");
        fclose(log);
        exit(1);
    }

    for (int i = 0; i < *size; i++) {
        if (fscanf(log, "%59s %f %d %9s\n", (*inventory)[i].name, &(*inventory)[i].price, &(*inventory)[i].quantity, (*inventory)[i].productID) != 4) {
            fprintf(stderr, "Error reading line %d\n", i + 1);
        }
    }
    fclose(log);
}

void logProduct(Product* inventory, int size) {
    FILE *log = fopen("inventory.txt", "w");
    if (!log) {
        perror("Error opening file for writing");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        fprintf(log, "%s %.2f %d %s\n", inventory[i].name, inventory[i].price, inventory[i].quantity, inventory[i].productID);
    }
    fclose(log);
}

int main() {
    //Ensure that inventory.txt exists before anything is done.
    FILE *log = fopen("inventory.txt", "r");
    if (!log) {
        printf("Error reading log, creating a new one\n");
        log = fopen("inventory.txt", "w");
        if (!log) {
            perror("Error creating inventory");
            exit(1);
        }
    }
    fclose(log);

    char state = ' '; //Blank State
    Product *inventory;// Empty Pointer will get allocated at a later date.
    int size = 0, selection = -1;

    //Repeat until user chooses option 'q'
    while (state != 'q') {
        parseLog(&inventory, &size);//Dynamically Allocates Memory for current inventory

        printf("\nCurrent inventory:\n");
        for (int i = 0; i < size; i++) {
            printf("--------Item %d--------\n", i + 1);
            displayProduct(&inventory[i]);
            printf("\n");
        }

        printf("Enter Action:\nA - Add New Item\nU - Update Quantity\nD - Delete an Item\nQ - Quit\n");
        scanf(" %c", &state);  // Use " %c" to consume whitespace
        getchar();  // Clear newline from buffer

        //Parse Option
        switch (state) {
            case 'A':
            case 'a': {
                Product *temp = realloc(inventory, (size + 1) * sizeof(Product));
                if (!temp) {
                    perror("No memory available");
                    exit(1);
                }
                inventory = temp;
                inputProduct(&inventory[size]);
                size++;
                logProduct(inventory, size);
                break;
            }
            case 'U':
            case 'u': {
                printf("Which product would you like to update? (Use Item Number) ");
                scanf("%d", &selection);
                if (selection < 1 || selection > size) {
                    printf("Error accessing outside inventory range.\n");
                } else {
                    printf("Enter new quantity for %s: ", inventory[selection - 1].name);
                    scanf("%d", &inventory[selection - 1].quantity);
                    logProduct(inventory, size);
                }
                break;
            }
            case 'D':
            case 'd': {
                printf("Which product would you like to delete? (Use Item Number) ");
                scanf("%d", &selection);
                if (selection < 1 || selection > size) {
                    printf("Error accessing outside inventory range.\n");
                } else {
                    for (int i = selection - 1; i < size - 1; i++) inventory[i] = inventory[i + 1];
                    Product *temp = realloc(inventory, (size - 1) * sizeof(Product));
                    if (!temp && size - 1 > 0) {
                        perror("No memory available");
                        exit(1);
                    }
                    inventory = temp;
                    size--;
                    logProduct(inventory, size);
                }
                break;
            }
            case 'Q':
                      state= 'q';//Forcing lower to Quit
                      printf("Quitting program.\n");
                      break;
            case 'q':
                printf("Quitting program.\n");
                break;
            default:
                printf("Not a valid input.\n");
        }
    }
    free(inventory);
    return 0;
}

