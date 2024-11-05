#include <stdio.h>
#include <stdlib.h>

int main(){
    int size = 2, counter = 0, input =-2; // Initialize some variables
    int *num_array = malloc(sizeof(int)*2);
    if (!num_array){
        printf("Error allocating Memory\n");
        return 1;
    }
    printf("Enter numbers one by one (type -1 to stop): ");

    //Loop Infinitely
    while (1){
        scanf("%d",&input);
        if (input==-1){
            break; //Exit condition
        }

        //If counter is as large as size then we are full 
        if (counter == size){
            size *=2;
            int * temp = realloc(num_array, (sizeof(int)*size)); //Assign reallocated to temp incase of memory err
            if(!temp){
                free(num_array);
                printf("Error allocating Memory");
                return 1;
            }
            num_array = temp; // Rerassign enlarged array
        }
        num_array[counter] = input;
        counter++;

    }

    printf("Final Array: ");
    for (int i=0; i<counter;i++){
        printf("%d ",num_array[i]);
    }
    printf("\n");
    free(num_array);
    return 0;
}
