#include <stdio.h>
#include <stdlib.h>
void free_memory(int** matrix,int rows){
    for (int i=0; i<rows; i++){
        free(matrix[i]);
    }
    free(matrix);
}

int main(){
    int size;
    printf("Enter the size of the matrix: ");
    scanf("%d", &size);

    //Make Array
    int **original_matrix = malloc(sizeof(int *)*size);
    int **transposed_matrix = malloc(sizeof(int *) *size);
    if (!original_matrix || !transposed_matrix){
        printf("Error allocating memory");
        return 1;
    }
    //Fill with sub arrays
    for (int i=0;i<size;i++){
        int * sub_org = malloc(sizeof(int)*size);
        int * sub_transposed = malloc(sizeof(int)*size);
        if (!sub_org||!sub_transposed){
            printf("Error allocating memory");
            return 1;
        }
        original_matrix[i] = sub_org;
        transposed_matrix[i] = sub_transposed;
    }

    //Fill the array
    int counter = 1;
    for(int row=0;row<size;row++){
        for (int col=0;col<size;col++){
            original_matrix[row][col] = counter;
            transposed_matrix[col][row] = counter;
            counter++;
        }
    }

    printf("Orignal matrix:\n");
    for(int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            printf("%d ", original_matrix[i][j]);
        }
        printf("\n");
    }
    free_memory(original_matrix,size);// Done with original_matrix

    printf("Transposed matrix:\n");
    for(int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            printf("%d ", transposed_matrix[i][j]);
        }
        printf("\n");
    }
    free_memory(transposed_matrix,size);

    return 0;
}
