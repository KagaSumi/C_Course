#include <stdio.h>
#include <stdlib.h>

void free_mem(int ** mtx, int row){
    for (int i=0;i<row;i++){
        free(mtx[i]);
    }
    free(mtx);
}

int main(){
    int rows,cols,total=0,sum=0;
    scanf("%d",&rows);
    scanf("%d",&cols);
    
    // Allocate Memory
    int **matrix = (int**)malloc(sizeof(int*)*rows);
    if (!matrix){
        printf("Error Allocating Memory");
        return 1;
    }
    for (int i = 0; i<rows;i++){
        matrix[i] = (int*)malloc(sizeof(int)*cols);
        if(!matrix[i]){
            printf("Error Allocating Memory");
            return 1;
        }
    }

    //Fill the Matrix
    for (int i =0; i<rows; i++){
        for (int j = 0; j<cols;j++){
            scanf("%d",&matrix[i][j]);
        }
    }

    //calculations
    for (int i =0; i<rows; i++){
        for (int j = 0; j<cols;j++){
            sum += matrix[i][j];
        }
        printf("Category %d: %d\n",i+1,sum);
        total += sum;
        sum = 0;
    }
    printf("Overall Total: %d\n", total);
    free_mem(matrix, rows);
    return 0;
}
