#include <stdio.h>
#include <stdlib.h>

void free_memory(int** matrix,int rows){
    for (int i=0; i<rows; i++){
        free(matrix[i]);
    }
    free(matrix);
}
int main(){
    // Init Var
    int rows, cols;
    printf("Enter the dimensions of the matrices (rows and columns): ");
    scanf("%d",&rows);
    scanf("%d", &cols);

    // Allocate memory for arrays 
    int ** mat_1 = malloc(rows * sizeof(int*));
    int ** mat_2 = malloc(rows * sizeof(int*));
    int ** results = malloc(rows * sizeof(int*));

    //Validate Memory has been allocated
    if (!mat_1 || !mat_2 || !results){
        printf("Error allocating memory\n");
        return 1;
    }

    for (int i = 0; i<rows; i++){
        mat_1[i] = malloc(cols* sizeof(int));
        mat_2[i] = malloc(cols* sizeof(int));
        results[i] = malloc(cols* sizeof(int));
        if (!mat_1[i] || !mat_2[i]|| !results[i]){
            printf("Error Allocating Memory\n");
            return 1;
        }
    }

    // Fill Arrays
    printf("Enter elements of the first %dx%d matrix: ",rows,cols);
    for (int i = 0; i<rows;i++){
        for (int j = 0; j<cols; j++){
            scanf("%d", &mat_1[i][j]);
        }
    }

    printf("Enter elements of the second %dx%d matrix: ",rows,cols);
    for (int i = 0; i<rows;i++){
        for (int j = 0; j<cols; j++){
            scanf("%d", &mat_2[i][j]);
        }
    }

    //Multiply the matrix
    for (int i = 0; i<rows;i++){
        for (int j = 0; j<cols; j++){
            results[i][j] = 0;
            for (int k = 0; k<cols; k++){
            results[i][j] += mat_1[i][k] * mat_2[k][j];
            }
        }
    }

    //Free Memory now that we have finished calculating
    free_memory(mat_1,rows);
    free_memory(mat_2,rows);

    // Print Matrix out
    printf("Resulting matrix after multiplication: \n");
    for (int i = 0; i<rows;i++){
        for (int j = 0; j<cols; j++){
            printf("%d ", results[i][j]);
        }
        printf("\n");
    }
    
    // Free result arrays
    free_memory(results, rows);
    return 0;
}
