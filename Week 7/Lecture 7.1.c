#include <stdio.h>

//cond 1:  we can move on disk at a time
//cond 2: the smaller one will be in the top/ a sick can only be
//placed on top of a larger disk
//cond 3:  you can use the B as temp location/ aux location (the middle pole)

//base case - the stopping or end condition or when the return condition is met
//when you have only one disk left and all of the others are sorted on pole C.

//recursive case:
//first, you can move n-1 disks from the source to the destination C.
//then, you can move the nth largest disk from A to B. (move all smaller disks to C, so you can isolate the largest disk on B)
//finally, you can move n-1 disks from B to C.

void towerOfHanoi(int n, char source, char destination, char aux, int* counter){
    if (n==1){
        printf("Move disk %d from %c to %c\n", n, source, destination);
        (*counter)++;
        return;
    }

    towerOfHanoi(n-1, source, aux, destination,counter);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    (*counter)++;
    towerOfHanoi(n-1, aux,destination, source,counter);

}

int main () {
    int numDisks = 13;
    int move_counter =0;
    int *p = &move_counter;
    
    printf("tower of hanoi with %d disks:", numDisks);
    printf("\n");

    towerOfHanoi(numDisks,'A','B','C',p);
    printf("It took %d, steps to complete this tower of hanoi\n", move_counter);
    return 0;
}
