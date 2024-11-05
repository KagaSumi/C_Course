#include <stdio.h>
#include <stdlib.h>

void find_max(int* matrix, int size, int* max){
    // Stepping Right to Left 
    *max = (*max <matrix[size])?matrix[size]:*max; // Set Max if current step is large
    if (size ==0) return; 
    find_max(matrix, size-1, max); // Step using size
}

int main(){
    //Initalizing Var
    int size, max=0;
    int* ptr = &max;
    scanf("%d", &size);
    //Allocating Memory
    int* matrix  = malloc(sizeof(int)*size);
    if (!matrix){
        printf("Error allocating memory");
        return 1;
    }
    //Fill Matrix
    for (int i =0; i<size;i++){
        scanf("%d",&matrix[i]);
    }
    find_max(matrix,size-1,ptr);
    printf("%d\n", max);
    return 0;
}
