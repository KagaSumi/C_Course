#include <stdio.h>

int main(){
    // Initialize Variables
    int max = 0,min = 0;
    double average, sum=0, count=0;

    FILE *file = fopen("data.txt", "r"); // Open Read File
    if (!file) {
        printf("Error opening file");
        return 0;
    }

    int temp;
    while(fscanf(file, "%d", &temp) != EOF){
        max = (temp>max)? temp: max; // If smaller set max
        min = (temp<max)? temp: min; // If larger  set min
        sum += temp; // Add to sum
        count++; // Add count for avg
    }
    average = (count != 0)?sum/count:0; // Calculate Average (Divide by 0 edge case)
    fclose(file);

    FILE *output = fopen("result.txt","w"); // Open Write File 
    fprintf(output,"Sum: %0.0lf\nAverage: %.2lf\nMax: %d\nMin: %d",sum,average,max,min); // Write File
    fclose(output);

    return 0;
}
