#include <stdio.h>
#include <stdlib.h>
void free_memory(int** matrix, int row){
    for (int i=0; i<row;i++){
        free(matrix[i]);
    }
    free(matrix);
    return;
}


int main(){
    int rows,cols;
    printf("Enter dimension of the Array: ");
    scanf("%d", &rows);
    scanf("%d", &cols);

    //Allocate Memory
    int **matrix = (int **)malloc(sizeof(int *)*rows);
    if (!matrix){
        printf("Error allocating Memory");
        return 1;
    }
    for (int row =0; row < rows; row++){
        matrix[row] = (int *)malloc(sizeof(int)*cols);
        if (!matrix[row]){
            printf("Error allocating Memory");
            free_memory(matrix, rows);
            return 1;
        }
    }

    //Take Input
    for (int i =0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    //Calculate Sum and output
    int sum = 0;
    for (int i =0 ; i<rows;i++){
        printf("Sensor %d: ",i+1);
        for(int j=0;j<cols;j++){
            sum += matrix[i][j];
        }
        printf("%d\n",sum);
        sum = 0;
    }
    //Clean up
    free_memory(matrix, rows);
    return 0;
}
