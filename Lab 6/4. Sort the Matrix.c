#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort (to sort the array in ascending order)
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void sortMatrix(int ** matrix, int n) {
    // Create a temporary array to hold all the elements
    int temp[n * n];

    // Flatten the matrix into the temporary array
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[k++] = matrix[i][j];
        }
    }

    // Sort the temporary array
    qsort(temp, n * n, sizeof(int), cmp);

    // Put the sorted elements back into the matrix in row-major order
    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = temp[k++];
        }
    }
}

void printMatrix(int ** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void free_matrix(int** matrix,int n){
    for (int i=0;i<n;i++){
        free(matrix[i]);
    }
    free(matrix);
    return;
}

int main() {
    int n;
    printf("Enter size n for array: ");
    scanf("%d",&n);


   int** mat = malloc(sizeof(int*)*n);
   if (!mat){
       perror("Error allocating memory");
       exit(1);
   }
   for (int i=0;i<n;i++){
       mat[i] = malloc(sizeof(int)*n);
       if (!mat){
           perror("Error allocating memory");
           exit(1);
       }
   }
   printf("Enter Matrix values: ");
   for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           scanf("%d",&mat[i][j]);
       }
    }
    printf("Original Matrix:\n");
    printMatrix(mat, n);
    
    sortMatrix(mat, n);
    
    printf("Sorted Matrix:\n");
    printMatrix(mat, n);

    free_matrix(mat, n);
    return 0;
}

