#include <stdio.h>

int main(){
    // Get 5 numbers from the user
    int arr[5];
    printf("Enter 5 number: ");
    for (int i=0; i<5; i++){
        scanf("%d", &arr[i]);
    }
    
    FILE *fptr = fopen("arr.txt","w");
    if (fptr == NULL) {
        printf("Error opening the file");
        return 1;
        }
    for (int i=0; i<5; i++){
        fprintf(fptr, "%d ", arr[i]); 
    }
    fclose(fptr);
}
