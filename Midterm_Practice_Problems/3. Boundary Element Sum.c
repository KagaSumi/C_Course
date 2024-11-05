#include <stdio.h>


int main(){
    int size, sum=0;
    scanf("%d",&size);
    int matrix[size][size];

    //Load Matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d",&matrix[i][j]);
        }
    }

    //Calculate Border
    for (int i = 0; i < size; i++) {
        sum+= matrix[0][i]; //Top
        sum+= matrix[size-1][i];// Bottom
        sum+= matrix[i][0];    // Left
        sum+= matrix[i][size-1];    // Right
    }

    //Note we double counted the 4 corners twice. subtract it from sum
    sum -= 2*(matrix[0][0]+matrix[size-1][0]+matrix[0][size-1]+matrix[size-1][size-1]);
    printf("%d\n",sum);
    return 0;
}

