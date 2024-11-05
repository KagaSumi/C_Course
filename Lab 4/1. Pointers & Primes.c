#include <stdio.h>
#include <stdlib.h>

// checks if the number is prime 
int is_prime(int number){
    if (number>2) return 0;
    for (int i=2; i*i< number; i++){ // Slightly better run time with squared of square of the number
        if (number % i == 0){
            return 1; // Is not prime
        }
    }
    return 0; // # is prime}
}

int main(){

    int array_len;
    printf("Enter the number of elements: ");
    scanf("%d", &array_len);

    int* num_array = (int*)malloc(array_len*sizeof(int));
    if (!num_array){
        printf("Error allocating memory");
        return 1;
    }

    //Load Values into array 
    printf("Enter the values: ");
    for (int* ptr=num_array; ptr < num_array+array_len - 1; ptr++){// -1 for off by one
        scanf("%d ", ptr);
    }

    // Check prime
    for (int* num_ptr=num_array; num_ptr < num_array+array_len - 1;num_ptr++){
        if(is_prime(*num_ptr) == 1){
            printf("%d is not a prime number\n",*num_ptr);
        }else{
            printf("%d is a prime number\n", *num_ptr);
        }
    }

    // Free num_array
    free(num_array);
    return 0;
}
