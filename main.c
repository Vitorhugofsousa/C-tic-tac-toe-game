#include <stdio.h>

char board[3][3] = {
    {'-','-','-'},
    {'-','-','-'},
    {'-','-','-'}
};

char actualPlayer = 'X';
int endGame = 0;

void boardInitialize(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            board[i][j] = '-';
        }
    }
}

void displayBoard(){
    printf("---\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    printf("---\n");
}

void makeaMove(){
    int row, column;
    printf("Type the Row: \n");
    scanf("%d", &row);

    printf("Type the Column : \n");
    scanf("%d", &column);

    if (board[row][column] == '-'){
        board[row][column] = actualPlayer;
    }else{
        printf("That position is occupied, try again.");
        makeaMove();
    }
    
}

int verifyWinner(){
    for (int i = 0; i < 3; i++){
        if (board[i][0] == actualPlayer && board[i][1] == actualPlayer && board[i][2] == actualPlayer){
            return 1;
        }
    }
    for (int i = 0; i < 3; i++){
        if (board[0][1] == actualPlayer && board[1][i] == actualPlayer && board[2][i] == actualPlayer){
            return 1;
        }
    }
    
        if ((board[0][0] == actualPlayer && board[1][1] == actualPlayer && board[2][2] == actualPlayer) || (board[0][2] == actualPlayer && board[1][1] == actualPlayer && board[2][0] == actualPlayer)){
            return 1;
        }  
        return 0;
}

int verifyDraw(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[i][j] == '-'){
                return 0;
            }
        }
    }
    return 0;
}

void switchPlayer(){
    actualPlayer = (actualPlayer == 'X') ? 'O' : 'X';
}

int main (){
    boardInitialize();

    while (!endGame){
        displayBoard();
        makeaMove();

        if (verifyWinner()){
            displayBoard();
            printf("PLAYER %c WIN!\n", actualPlayer);
            endGame = 1;
        }else if (verifyDraw()){
            displayBoard();
            printf("We have a Draw, Try Again!");
        }
        
        switchPlayer();
    }
    return 0;    
}
