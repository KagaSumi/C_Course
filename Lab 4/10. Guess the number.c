#include <stdio.h>
#include <stdlib.h>

int main(){
    int size=2,number,guess,guess_count=0;
    int * guesses = malloc(sizeof(int)*2); 
    if(!guesses){
        printf("Error allocating memory\n");
        return 1;
    }
    number = (rand()%100) +1; // Random number [0-99] + 1 =  [1 - 100]

    //Gameloop
    while(1){
        //Take input
        printf("Enter your guess: ");
        scanf("%d",&guess);

        //Make more room if needed
        if (guess_count == size){
            size *=2;
            int * temp = realloc(guesses, sizeof(int)*size);
            if (!temp){
                printf("Error allocating memory\n");
                free(guesses);
                return 1;
            }
            guesses=temp;
        }
        //Store Guess
        guesses[guess_count] = guess;
        guess_count++;
        if (guess == number){
            break;// Exit Condition
        }
        //Else report too high or low
        (guess<number) ? printf("Too low.\n"): printf("Too high.\n");
    }

    //Report Guessses
    printf("Congratulations! You guessed the number.\nTotal guesses: %d\nYour Guesses: ",guess_count);
    for (int i=0;i<guess_count;i++){
        printf("%d ", guesses[i]); 
        }
    printf("\n");
    free(guesses);
    return 0;
}
