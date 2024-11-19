#include <stdio.h>
#include <stdlib.h>

// Comparison function for integers
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); // Compare integers directly
}

// Function to find the minimum number of platforms required
int minPlatforms(int arrival[], int departure[], int n) {
    // Sort arrival and departure arrays using the correct comparison function
    qsort(arrival, n, sizeof(int), compare);
    qsort(departure, n, sizeof(int), compare);

    int platforms_needed = 1; // We need at least one platform initially
    int result = 1; // To store the maximum number of platforms required
    int i = 1, j = 0; // Start pointers for arrival and departure

    // Iterate through all the events
    while (i < n && j < n) {
        // If next event is an arrival, increase platform count
        if (arrival[i] <= departure[j]) {
            platforms_needed++;
            i++;
        }
        // If next event is a departure, decrease platform count
        else if (arrival[i] > departure[j]) {
            platforms_needed--;
            j++;
        }
        // Update the result with the maximum platforms needed
        if (platforms_needed > result) {
            result = platforms_needed;
        }
    }

    return result;
}

int main() {
    int size;
    printf("Enter Amount of trains: ");
    scanf("%d", &size);
    int * arrival = malloc(sizeof(int)*size);
    if (!arrival){
        perror("Error allocating memory");
        exit(1);
    }

    int * departure = malloc(sizeof(int)*size);
    if (!departure){
        perror("Error allocating memory");
        exit(1);
    }
    for (int i =0;i<size;i++){
        printf("Enter Train %d's Arrival and Departure: ",i+1);
        scanf("%d", &arrival[i]);
        scanf("%d", &departure[i]);

    }

    // Function calls to find the minimum platforms
    printf("Minimum platforms required : %d\n", minPlatforms(arrival,departure,size)); 

    free(arrival);
    free(departure);
    return 0;
}

