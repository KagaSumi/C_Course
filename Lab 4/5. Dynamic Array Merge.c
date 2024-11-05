#include <stdio.h>
#include <stdlib.h>

//Qsort Snippet taken from
//https://www.geeksforgeeks.org/c-program-to-sort-an-array-in-ascending-order/
int compare(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int main(){
    int arr1_len, arr2_len;

    printf("Enter the size of the first array: ");
    scanf("%d",&arr1_len);
    int* arr1 = malloc(arr1_len*sizeof(int));
    if(!arr1){
        printf("Error allocating memory");
        return 1;
    }
    printf("Enter the elements: ");
    for (int i=0; i< arr1_len;i++){
        scanf("%d",&arr1[i]);
    }

    printf("Enter the size of the second array: ");

    scanf("%d",&arr2_len);

    int* arr2 = malloc(arr2_len*sizeof(int));
    if(!arr2){
        printf("Error allocating Memory");
        free(arr1);
        return 1;
    }

    printf("Enter the elements: ");
    for (int i=0; i< arr2_len;i++){
        scanf("%d",&arr2[i]);
    }
    
    int * resultarr = malloc((arr1_len+arr2_len) *sizeof(int));
    if (!resultarr){
        printf("Error Allocating Memory");
        free(arr1);
        free(arr2);
        return 1;
    }
    // Combine the two arrays into resultarr
    for (int i = 0; i < arr1_len; i++) {
        resultarr[i] = arr1[i];
    }
    for (int i = 0; i < arr2_len; i++) {
        resultarr[arr1_len + i] = arr2[i];
    }
    free(arr1);
    free(arr2);

    // Sort the combined array using qsort
    qsort(resultarr,  arr1_len+arr2_len,sizeof(int), compare);

    // Output the sorted result
    printf("Sorted combined array: ");
    for (int i = 0; i < arr1_len+arr2_len; i++) {
        printf("%d ", resultarr[i]);
    }
    printf("\n");

    // Free dynamically allocated memory
    free(resultarr);
    return 0;
}
