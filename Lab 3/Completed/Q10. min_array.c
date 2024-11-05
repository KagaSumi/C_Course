#include <stdio.h>
int main(){
    FILE *fptr = fopen("min_arr.txt","r");
    if (fptr == NULL){
        printf("Error opening file \n");
        return 1;
    }
    int number; 
    int smallest;

    // Grab first number in the file and assign it to Smallest
    if (fscanf(fptr, "%d", &number) == 1) {
        smallest = number;
    } else {
        printf("No valid integers inside this file");
        return 1;
    }

    // Loop the Array in the file and check if it is smaller than smallest
    while(fscanf(fptr, "%d", &number) == 1){
        smallest = (smallest>number) ? number : smallest;
    }
    printf("Minimum Value: %d", smallest);
    return 0;
}
