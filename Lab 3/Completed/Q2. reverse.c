#include <stdio.h>
int main()
{
    // Create Array
    int arr[5];

    // Load array
    printf("Enter 5 numbers: ");
    for (int i=0; i< 5; i++){
    scanf("%d", &arr[i]);
    }

    // Print Array backwards
    printf("Reversed order: ");
    for (int i=4;i>=0; i--){
        printf("%d ",arr[i]);
    }
    return 0;
}