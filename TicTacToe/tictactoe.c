#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
char board[3][3]; 
#define RESET "\x1B[0m"
#define BOLD "\x1B[1m"     
int row;
int col;
char winner;
bool wantToPlayWithComp;
int initBoard(){
	int i, j;
	for(i = 0; i < 3; i++){
        	for(j = 0; j < 3; j++){
            	board[i][j] = '.';
        }
	}
        printf("\n\n");
}

void drawBoard() 
{
	for(int row = 0; row < 3; row++) 
    	{
        	for(int column = 0; column < 3; column++)
		{
            	printf(" %c ", board[row][column]);
        	}
        	printf("\n");
    	}
}

void askCompOrLocal()
{
	int choose;
	printf("\n\nDo you Want to play Local Multiplayer or With Computer/AI?");
	printf("\n\n1. Local Multiplayer.\n2. Computer/AI\n\n");
	printf("Choose: ");
	scanf("%d", &choose);
       	switch(choose)
       	{
        	case 1:
		wantToPlayWithComp = false;
		printf("\n\nYou Are Playing Local Multiplayer\n");
           	break;
           
         	case 2:
		wantToPlayWithComp = true;	
		printf("\n\nYou Are Playing with Computer/AI\n");
           	break;
           
         	default:
		printf("\n%sInvalid Number%s", BOLD, RESET);
		askCompOrLocal();
		break;

       }
}

char checkIfXWins(){
	/* X X X
	   . . .
	   . . . */
	if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X'){
		printf("\n%s'X' is the winner%s", BOLD, RESET);
		winner = 'X';
		return winner;
	}
	/* X . .
	   X . .
	   X . . */
	if(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X'){
		printf("\n%s'X' is the winner%s", BOLD, RESET);
		winner = 'X';
		return winner;
	}
	/* . . X
	   . . X
	   . . X */
	if(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X'){
		printf("\n%s'X' is the winner%s", BOLD, RESET);
		winner = 'X';
		return winner;
	}
        /* . . .
	   . . .
	   X X X */
	if(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'x'){
		printf("\n%s'X' is the winner%s", BOLD, RESET);
		winner = 'X';
		return winner;
	}
	/* . . .
	   X X X
	   . . . */
	if(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X'){
		printf("\n%s'X' is the winner%s", BOLD, RESET);
		winner = 'X';
		return winner;
	}
	/* . X .
	   . X .
	   . X . */
	if(board[0][1] == 'X' && board[1][1] == 'x' && board[2][1] == 'X'){
		printf("\n%s'X' is the winner%s", BOLD, RESET);
		winner = 'X';
		return winner;
	}
	/* X . .
	   . X .
	   . . X */
	if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X'){
		printf("\n%s'X' is the winner%s", BOLD, RESET);
		winner = 'X';
		return winner;
	}
	/* . . X
	   . X .
	   X . . */
	if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'){
		printf("\n%s'X' is the winner%s", BOLD, RESET);
		winner = 'X';
		return winner;
	}
}
char checkIfOWins(){
	/* X X X
	   . . .
	   . . . */
	if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O'){
	printf("\n%s'O' is the winner%s", BOLD, RESET);
	winner = 'O';
	return winner;
	}
	/* X . .
	   X . .
	   X . . */
	if(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O'){
		printf("\n%s'O' is the winner%s", BOLD, RESET);
		winner = 'O';
		return winner;
	}
	/* . . X
	   . . X
	   . . X */
	if(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O'){
		printf("\n%s'O' is the winner%s", BOLD, RESET);
		winner = 'O';
		return winner;
	}
        /* . . .
	   . . .
	   X X X */
	if(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O'){
		printf("\n%s'O' is the winner%s", BOLD, RESET);
		winner = 'O';
		return winner;
	}
	/* . . .
	   X X X
	   . . . */
	if(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O'){
		printf("\n%s'O' is the winner%s", BOLD, RESET);
		winner = 'O';
		return winner;
	}
	/* . X .
	   . X .
	   . X . */
	if(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O'){
		printf("\n%s'O' is the winner%s", BOLD, RESET);
		winner = 'O';
		return winner;
	}
	/* X . .
	   . X .
	   . . X */
	if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O'){
		printf("\n%s'O' is the winner%s", BOLD, RESET);
		winner = 'O';
		return winner;
	}
	/* . . X
	   . X .
	   X . . */
	if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'){
		printf("\n%s'O' is the winner%s", BOLD, RESET);
		winner = 'O';
		return winner;
	}

}

void xMove()
{
	printf("\n%sX%s Turn(Row): ", BOLD,RESET);
	scanf("%d", &row);
	printf("\n%sX%s Turn(Column): ", BOLD,RESET);
	scanf("%d", &col);
	printf("\n");
	row = row - 1;
	col = col - 1;
		if(board[row][col] != '.'){
		printf("%sSpace Already Taken\n\n%s", BOLD, RESET);
		drawBoard();
		xMove();
		} else {
		board[row][col] = 'X';
		}


}

void oLocalMove()
{

	printf("\n%sO%s Turn(Row): ", BOLD,RESET);
	scanf("%d", &row);
	printf("\n%sO%s Turn(Column): ", BOLD,RESET);
	scanf("%d", &col);
	printf("\n");
	row = row - 1;
	col = col - 1;
		if(board[row][col] != '.'){
		printf("%sSpace Already Taken\n\n%s", BOLD, RESET);
		drawBoard();
		oLocalMove();
		} else {
		board[row][col] = 'O';
	drawBoard();
		}

}

void oCompMove()
{
	//int comRow;
	//int comCol;
	if(board[rand() % 3][rand() % 3] != '.'){
		oCompMove();
	} else {
		board[rand() % 3][rand() % 3] = 'O';
		drawBoard();
	}

}

int main(){
	printf("Tic Tac Toe!");
	askCompOrLocal();
	initBoard();
	drawBoard();
	while(winner != 'X' || winner != 'O')
	{
	xMove();
	checkIfXWins();
	if(winner == 'X'){
		return winner;
	}
	if(wantToPlayWithComp == false){
	drawBoard();
		oLocalMove();
		checkIfOWins();
		if(winner == 'O'){
			return winner;
		}

	}	
	if(wantToPlayWithComp == true){
		oCompMove();
		checkIfOWins();
		if(winner == 'O'){
			return winner;
		}

	}	
	}
}
