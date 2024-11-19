#include <stdio.h>
#include <stdlib.h>

//Interval as a Struct to keep track of it
typedef struct {
    int start;
    int end;
} Interval;

int compare(const void *a, const void *b) {
    Interval *intervalA = (Interval *)a;
    Interval *intervalB = (Interval *)b;
    return intervalA->start - intervalB->start;
}

Interval* mergeIntervals(Interval* intervals, int intervalsSize, int *mergedSize) {
    if (intervalsSize == 0) {
        *mergedSize = 0;
        return NULL;
    }

    // Sort intervals by start time
    qsort(intervals, intervalsSize, sizeof(Interval), compare);

    // Allocate memory for the result array
    Interval *merged = malloc(intervalsSize * sizeof(Interval));
    if (!merged){
        perror("Error allocating Memory");
        exit(1);
    }
    int index = 0;

    // Initialize the first interval
    merged[index] = intervals[0];

    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i].start <= merged[index].end) {
            // Overlapping intervals, merge them
            merged[index].end = merged[index].end > intervals[i].end ? merged[index].end : intervals[i].end;
        } else {
            // No overlap, add the interval to the result
            index++;
            merged[index] = intervals[i];
        }
    }

    *mergedSize = index + 1;
    return merged;
}

int main() {
    int intervalsSize;
    int mergedSize = 0;
    printf("How many intervals: ");
    scanf("%d", &intervalsSize);
    Interval * intervals = malloc(sizeof(Interval)*intervalsSize);
    if (!intervals){
        perror("Error allocating Memory");
        exit(1);
    }
    for (int i =0 ;i<intervalsSize;i++){
        printf("Interval %d\n", i+1);
        printf("Bounds:");
        scanf("%d", &intervals[i].start);
        scanf("%d", &intervals[i].end);
    }

    Interval *merged = mergeIntervals(intervals, intervalsSize, &mergedSize);
    free(intervals);

    // Print the merged intervals
    printf("Merged Intervals: ");
    for (int i = 0; i < mergedSize; i++) {
        printf("[%d, %d] ", merged[i].start, merged[i].end);
    }
    printf("\n");

    // Free allocated memory
    free(merged);
    return 0;
}

