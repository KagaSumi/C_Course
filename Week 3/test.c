#include <stdio.h>
#include <stdlib.h>
int main(){
     // int x =10;
    // Allocated some address as X
    // Allocates value at address as 10
    //
    // Defining a pointer use (*)
     // int *ptr;


     // ptr = &x ;

     // printf("Value of x: %d\n", x);
     // printf("Value of X using the pointer: %d\n", *ptr);

    // int arr[] = {10,20,30,40};
    // int *ptr = arr;
    // for (int i=0;i<4; i++){
    //     printf("Elements of Array %d: %d\n",i,*(ptr+i));
    // }

    int n;
    printf("Enter the number of integers\n");
    scanf("%d",&n);

    int *arr = (int *)malloc(n*sizeof(int));

    if (arr==NULL) {
        printf("Memory allocation error\n");
        return 1;
    }
// initialize hte arr and display
    for (int i=0; i<n; i++) {
        arr[i] = i+1;
        printf("%d ", arr[i]);
    }
free(arr);
    return 0;
}