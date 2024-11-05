#include <stdio.h>
int main(){
    int arr1[5], arr2[5], result[10];
    
    // Fill array 1
    printf("Enter 5 numbers for array 1: ");
    for (int i =0 ; i<5;i++){
        scanf("%d", &arr1[i]);
    }
    printf("Enter 5 numbers for array 2: ");
    for (int i =0 ; i<5;i++){
        scanf("%d", &arr2[i]);
    }

    // Merge the two arrays
    for (int i = 0; i<10; i++){
        result[i] = (i<5) ? arr1[i] : arr2[i-5];
    }

    //print Array
    printf("Merged array: ");
    for (int i = 0; i<10; i++){
        printf("%d ", result[i]);
    }
    return 0;
}