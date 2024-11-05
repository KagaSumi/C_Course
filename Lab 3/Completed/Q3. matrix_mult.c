#include <stdio.h>
int main(){
    // Init Var
    int arr1[2][2], arr2[2][2], result[2][2];
    
    // Fill Arrays
    printf("Enter elements of the first 2x2 matrix: ");
    for (int i = 0; i<2;i++){
        for (int j = 0; j<2; j++){
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("Enter elements of the second 2x2 matrix: ");
    for (int i = 0; i<2;i++){
        for (int j = 0; j<2; j++){
            scanf("%d", &arr2[i][j]);
        }
    }

    //Multiply the matrix
    for (int i = 0; i<2;i++){
        for (int j = 0; j<2; j++){
            result[i][j] = 0;
            for (int k = 0; k<2; k++){
            result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    // Print Matrix out
    printf("Resulting matrix after multiplication: \n");
    for (int i = 0; i<2;i++){
        for (int j = 0; j<2; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}