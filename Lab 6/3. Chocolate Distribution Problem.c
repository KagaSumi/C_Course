#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort (to sort the array in ascending order)
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int chocolateDistribution(int arr[], int n, int m) {
    // If there are fewer packets than students, return 0 (invalid case)
    if (n < m) {
        return 0;
    }

    // Sort the array
    qsort(arr, n, sizeof(int), cmp);

    // Initialize the minimum difference as a large number
    int min_diff = arr[m - 1] - arr[0]; // Initial difference for the first window

    // Iterate through the array and consider each window of size m
    for (int i = 1; i <= n - m; i++) {
        int diff = arr[i + m - 1] - arr[i];
        if (diff < min_diff) {
            min_diff = diff;
        }
    }

    return min_diff;
}

int main() {
    int size;
    int minimum;
    printf("Enter size of array: ");
    scanf("%d",&size);

    int* arr = malloc(sizeof(int)*size);
    if (!arr){
        perror("Error allocating memory");
        exit(1);
    }

    printf("Enter array values: ");
    for (int i = 0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter minimum chocolate distrubuted: ");
    scanf("%d", &minimum);

    // Function calls
    printf("%d\n", chocolateDistribution(arr, size, minimum));

    return 0;
}

