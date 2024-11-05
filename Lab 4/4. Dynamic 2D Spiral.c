#include<stdio.h>
#include<stdlib.h>

void free_memory(int** matrix,int rows){
    for (int i=0; i<rows; i++){
        free(matrix[i]);
    }
    free(matrix);
}

void spiralmatrix(int n){
int** matrix = malloc(n*sizeof(int*));
if (!matrix){
    printf("Error allocating memory\n");
    return;
}
for (int i =0; i<n;i++){
    matrix[i] = malloc(n*sizeof(int));
    if (!matrix[i]){
        printf("Error allocating memory\n");
        return;
    }
}

int top = 0, bottom = n-1, left = 0, right = n-1;
int value = 1;

while(value <= n*n)
{
    //fill the top row (left to right)

    for(int i = left; i<= right; i++)
    {
        matrix[top][i] = value++;
    }
    top++;

    //fill the right col (top to bottom)

    for(int i = top; i<=bottom; i++)
    {
        matrix[i][right] = value++;
    }
    right--;

    //fill the bottom row (right to left)

    for(int i = right; i>= left; i--)
    {
        matrix[bottom][i] = value++;
    }
    bottom--;

    // fill the left col (bottom to top)

    for(int i = bottom; i>=top; i--)
    {
        matrix[i][left] = value++;
    }
    left++;
}
    //print the matrix
    for(int i = 0; i<n; i++)
    {
        for(int j=0; j<n;j++)
        {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

free_memory(matrix, n);
}


int main()
{
    int n;
    printf("Enter the integer value\n");
    scanf("%d", &n);

    if (n>0)
    {
        spiralmatrix(n);
    }
    else
    {
        printf("Invalid n value, no matrix to print\n");
    }

    return 0;
} 
