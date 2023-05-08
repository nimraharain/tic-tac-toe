#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char board[3][3] = {{' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '}};

void display_board() {
    printf("%c | %c | %c\n", board[0][0],board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf("%c | %c | %c\n", board[1][0],board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf("%c | %c | %c\n", board[2][0],board[2][1], board[2][2]);
    printf("---+---+---\n");
}

int check_win() {
    //check rows, cols, diagonals
    //row
    int i;
    for (i = 0; i < 3; i++){
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' '){
            return 1;
        }
        //cols
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' '){
            return 1;
    }
    }
    // diag 1
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' '){
            return 1;
    }
    //diag 2
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '){
            return 1;
    }
    return 0; 
}
int check_tie(){
    int row, col;
    for (row = 0; row < 3; row++){
        for (col = 0; col < 3; col++){
            if (board[row][col] == ' '){
                return 0;
            }
        }
    }
    return 1;

}
void resetBoard(){
    int row, col;
    for (row = 0; row < 3; row++){
        for (col = 0; col < 3; col++){
            board[row][col] = ' ';
        }
    }
}
int main(){
    int row, col, player = 1;
    int gameOver = 0;
    while(gameOver == 0){
        display_board();
        printf("Player %d, pick a row and column: ", player);
        scanf("%d %d", &row, &col);
        if ( row < 0 || row > 2 || col < 0 || col > 2){
            printf("invalid input, try again\n");
            continue;
        }
        if (board[row][col] != ' '){
            printf("spot is taken, try again\n");
            continue;
        }
        if (player == 1){
            board[row][col] = 'X';
        }
        else {
            board[row][col] = 'O';
        }
        if (check_win()) {
            printf("Player %d wins!\n", player);
            char play_again = getchar();
            printf("Do you want to play again? (y/n): \n");
            scanf("%c", &play_again);
            if(play_again == 'y'||play_again == 'Y') {
                resetBoard(); 
                player = 1;
                continue;
            } else {
                break;
    }
}
        if (check_tie()) {
            printf("its a tie!\n");
            char play_again = getchar();
            printf("Do you want to play again? (y/n): \n");
            scanf("%c", &play_again); 
            if(play_again == 'y'|| play_again == 'Y') {
                resetBoard(); 
                player = 1;
                continue;
            } else {
                break;
  }
}       player = (player == 1) ? 2:1;
    }
        return 0;
}