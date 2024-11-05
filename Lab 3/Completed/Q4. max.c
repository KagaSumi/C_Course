#include <stdio.h>
int main(){
    // Intialize array
    int arr[10];
    int max = 0;
    // Fill array
    printf("Enter 10 numbers: ");
    for (int i = 0; i<=10; ++i){
        scanf("%d ",&arr[i]);
    }
    // Find largest int in array
    for (int i = 0; i<=10; ++i){
        if (max <= arr[i]){
            max = arr[i];
        }
    }
    printf("Maximum element: %d", max);
    return 0;
}