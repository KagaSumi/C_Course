#include <stdio.h>
#include <stdlib.h>

void printQuadruples(int **result, int resultSize, int quadrupleSize) {
    for (int i = 0; i < resultSize; i++) {
        printf("[");
        for (int j = 0; j < quadrupleSize; j++) {
            printf("%d", result[i][j]);
            if (j < quadrupleSize - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int** fourSum(int* arr, int arrSize, int target, int* returnSize) {
    // Sort the array to help skip duplicates
    qsort(arr, arrSize, sizeof(int), cmp);
    
    // The result array to store quadruples
    int** result = (int**)malloc(sizeof(int*) * arrSize);  // Result will always be smaller than size squared
    if(!result){
        perror("Error allocating memory");
        exit(1);
    }
    *returnSize = 0;

    for (int i = 0; i < arrSize - 3; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;  // Skip duplicates for the first element
        }
        for (int j = i + 1; j < arrSize - 2; j++) {
            if (j > i + 1 && arr[j] == arr[j - 1]) {
                continue;  // Skip duplicates for the second element
            }
            int left = j + 1;
            int right = arrSize - 1;
            while (left < right) {
                int sum = arr[i] + arr[j] + arr[left] + arr[right];
                if (sum == target) {
                    // Found a quadruple, store it
                    result[*returnSize] = (int*)malloc(sizeof(int) * 4);
                    result[*returnSize][0] = arr[i];
                    result[*returnSize][1] = arr[j];
                    result[*returnSize][2] = arr[left];
                    result[*returnSize][3] = arr[right];
                    (*returnSize)++;
                    
                    // Skip duplicates for the third element
                    while (left < right && arr[left] == arr[left + 1]) {
                        left++;
                    }
                    // Skip duplicates for the fourth element
                    while (left < right && arr[right] == arr[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return result;
}

int main() {
    //Hard coded since I'm not sure how to parse -2 as input to a int value 
    int arr1[] = {1, 0, -1, 0, -2, 2};
    int target1 = 0;
    int arrSize1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 2, 2, 2, 2};
    int target2 = 8;
    int arrSize2 = sizeof(arr2) / sizeof(arr2[0]);

    int returnSize1 = 0, returnSize2 = 0;

    int **result1 = fourSum(arr1, arrSize1, target1, &returnSize1);
    int **result2 = fourSum(arr2, arrSize2, target2, &returnSize2);

    printf("Output 1:\n");
    printQuadruples(result1, returnSize1, 4);

    printf("\nOutput 2:\n");
    printQuadruples(result2, returnSize2, 4);

    // Free allocated memory
    for (int i = 0; i < returnSize1; i++) {
        free(result1[i]);
    }
    free(result1);
    for (int i = 0; i < returnSize2; i++) {
        free(result2[i]);
    }
    free(result2);

    return 0;
}

