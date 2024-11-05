#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int turncount;
    int target;
    int max_turn_count;
}Game;

void initalize_game(Game * g){
    g->turncount = 0;
    g->max_turn_count = 5;
    g->target = rand()%100+1; //1- 100;
}
void play_game(Game* g){
    int guess;

    //Take Initial Guess
    printf("Atttempt 1: Guess a number between 1-100: ");
    scanf("%d", &guess);
    g->turncount++;

    //Game Loop
    while (g->turncount< g->max_turn_count){
        if (guess==g->target){
            printf("Winner!");
            return;
        }
        (guess<g->target)?printf("Hint: Too Low!\n"):printf("Hint: Too High!\n");
        printf("Attempt %d: Guess a number between 1-100: ", g->turncount + 1);
        scanf("%d", &guess);
        g->turncount++;
    }
    printf("The Target number was %d\nBetter Luck Next Time!\n", g->target);
    return;
}

int main(){
    srand(time(NULL));//Seeding number Generator
    Game g; //Creating Game
    initalize_game(&g);
    play_game(&g);
    return 0;
}
