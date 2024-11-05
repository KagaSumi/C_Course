#include <stdio.h>
int main(){
    int odd = 0, even = 0, arr[10];
    
    // Get values
    printf("Enter 10 numbers: ");
    for (int i = 0; i<10; i++){
        scanf("%d", &arr[i]);
    }

    // Parse odd/even
    for (int i = 0; i<10; i++){
        (arr[i]%2 == 0)? even++ : odd++;
    }
    // Print outputs
    printf("Odd numbers: %d\n", odd);
    printf("Even Numbers: %d", even);
    return 0;
}