#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//Resources I used for time.h:
//https://www.geeksforgeeks.org/time-h-header-file-in-c-with-examples/

// ------- Structures ---------
typedef struct {
    char id;
    int move_count;

}Player;

typedef struct {
    char id;
    int row;
    int cols;
    time_t timestamp;
}Move;

// Function Prototypes

// Board and Board Clean up
void free_memory(char **matrix, int size);
char** create_board();
void displayBoard(char **board);

// Logging
void logMove(FILE *file, Move move);
void logWin(FILE *file, Player player, int Draw);

// Move Logic
int isValidMove(char **board, int row, int col);
Move makeMove(char **board, Player *player, int row, int col);

// Game Logic
int checkState(char **board, Player player, int *draw);
int checkRow(char **board, Player player, int row);
int checkCol(char **board, Player player, int col);
int checkDiag(char **board, Player player);
int checkWin(char **board, Player player);
void endGame(char **board, FILE *file);
int Play(char **board, FILE *file, Player *player, int *draw);

// -------- Board and Board Clean up ----------
void free_memory(char **matrix, int size){
    for (int i=0; i<size;i++){
        free(matrix[i]); //Free all sub-arrays
    }
    free(matrix); //Free Main Array
}

char** create_board(){
    char** board = malloc(sizeof(char*)*3);
    if (!board){
        perror("Error allocating memory");
        exit(1);
    }
    for (int i=0;i<3;i++){
        board[i] = malloc(sizeof(char)*3);
        if (!board[i]){
            perror("Error Allocating Memory");
            free_memory(board, 3);
            exit(1);
        }
        memset(board[i], '-',3);//Load - into subarray
    }
    return board;
}

void displayBoard (char **board){
    printf("Current Board:\n");
    for (int i = 0;i<3;i++){
        for (int j = 0;j<3;j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    return;
}

// ------- Logging ---------
void logMove(FILE *file, Move move){
    //Log Move
    char time_buffer[100];
    struct tm *time_info = localtime(&move.timestamp);
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", time_info);
    fprintf(file,"Player %c placed at Row: %d, Col: %d, Time: [%s]\n",move.id,move.row,move.cols,time_buffer);
    return;
}

void logWin(FILE *file, Player player, int Draw){
    if (Draw){ //1 == Draw, 0 = Player Wins
        printf("Draw!\n");
        fprintf(file,"Draw");
        return;
    }
    printf("Player %c Wins!\n", player.id);
    fprintf(file,"Final Result: Player %c Wins",player.id);
    return;
}

// ----------- Move Logic  ---------------
int isValidMove(char ** board, int row, int col){
    if (row < 0 || row >= 3 || col < 0 || col >= 3) return 0; // Not Valid
    else if (board[row][col] != '-') return 0; // Not Valid 
    return 1; // Valid
}

Move makeMove(char **board, Player *player, int row, int col){
    board[row][col] = player->id;
    player->move_count++;  // Increment the move counter on the original player struct
    time_t current_time = time(NULL);
    Move move = {player->id, row, col, current_time};
    return move;
}

// ------------ Game Logic --------------
int checkState(char **board, Player player, int * draw){
    //Return 1 when someone wins/Draw
    //Return 0 when no wins
    if (checkWin(board,player)) return 1; //Player Won Game
    else if (player.id == 'X' && player.move_count == 5){ //Draw Condition
        *draw = 1; // Update Draw Flag
        return 1;
    }
    return 0;
}

int checkRow(char** board,Player player, int row){
    //Checks the row (Left to right)
    int counter = 0;
    for (int col=0;col<3;col++){
        if (board[row][col] == player.id) counter++;
    }
    return (counter ==3)?1:0;// return 1 if 3 in a row

}

int checkCol(char** board,Player player, int col){
    int counter = 0;
    for (int row=0;row<3;row++){
        if (board[row][col] == player.id) counter++;
    }
    return (counter ==3)?1:0;// return 1 if 3 in a row
}

int checkDiag(char** board,Player player){
    int counter = 0;
    //Left Diag
    for (int i=0;i<3;i++){
        if (board[i][i] == player.id) counter++;
    }
    if (counter==3) return 1;// Win on Left Diag

    //Right Diag
    counter = 0; // Reset Count
    for (int i=0;i<3;i++){
        if (board[i][3-1-i] == player.id) counter++;
    }
    if (counter==3) return 1;// Win on Right Diag
    return 0;// No win
}

int checkWin(char ** board, Player player){
    //This function will check diagonal if the player has won, then each row or column.
    if (checkDiag(board, player) == 1) return 1; //Diagonal Match
                                                 
    for (int i = 0;i<3;i++){//For Each Row/Col Check if there is a Win
       if (checkRow(board, player, i) == 1) return 1; //Horizontal Match
       else if (checkCol(board, player, i) == 1) return 1; //Vertical Match
    }
    return 0;// No Win
}

// Clean up
void endGame(char **board, FILE * file){
    free_memory(board,3); 
    fclose(file);
    return;
}

int Play(char **board, FILE *file, Player *player, int * draw) {  // Change to Player *player
    int row, col;
    int valid = 0, win = 0;
    Move tmp_move;
    while(valid == 0){
        printf("Player %c, enter your move (row and column): ", player->id);
        scanf("%d %d", &row, &col);
        row--;
        col--;
        valid = isValidMove(board, row, col);
        if (!valid){
            printf("Invalid Move, please try again\n");
        }
    }
    printf("\n");
    tmp_move = makeMove(board, player, row, col);
    logMove(file, tmp_move);
    if (checkState(board, *player, draw) == 1) return 1;
    return 0;
}

int main(){
    char **board = create_board();
    if (!board){
        perror("Error allocating memory for the board");
        exit(1);
    }

    FILE *log = fopen("game_log.txt","a");
    if (!log){
        perror("Error opening game_log.txt for logging");
        exit(1);
    }

    //Initialize the players and Game Var
    Player player_x = {'X', 0}, player_y = {'Y', 0};
    Player* Current_Player = &player_x;
    int draw = 0;

    printf("Welcome to Tic Tac Toe!\n");
    while (1){ //Infinite Game Loop 
        displayBoard(board);
        printf("\n");
        if(Play(board, log, Current_Player, &draw) == 1) break; //If Play Return 1, it means game is over (Either Win/Draw)
        // Break before we update the Current_Player
        Current_Player = (Current_Player == &player_x) ? &player_y : &player_x;
    }
   
    logWin(log,*Current_Player,draw);
    endGame(board, log);
    return 0;
}
