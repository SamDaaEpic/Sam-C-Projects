#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
// Create the Variable to Store the Board 
//char board[3][3];
char board[3][3];
bool spaceTaken1 = false, spaceTaken2 = false, spaceTaken3 = false, spaceTaken4 = false, spaceTaken5 = false, spaceTaken6 = false, spaceTaken7 = false, spaceTaken8 = false, spaceTaken9 = false;
char winner;
// Function To Draw The Main Board
int drawGameBase(){
	int i, j;
	for(i = 0; i < 3; i++){
        	for(j = 0; j < 3; j++){
            	board[i][j] = '.';
            	printf( " %c ", board[i][j]);
        }
        printf("\n");
	}
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



void xMove(){
	int userInput;
        	printf("\n\nIts X Turn, choose from 1-9: ");
        	scanf("%d", &userInput);

        	printf("\n");
        	if(userInput == 1){
            		if(spaceTaken1 == true){
                		printf("\nSpace already taken, Choose Again.\n\n");
                	}
            		else {
                  	board[0][0] = 'x';
              	  	spaceTaken1 = true;
                	}
          	}

          	if(userInput == 2){
            		if(spaceTaken2 == true){
                		printf("\nSpace already taken, Choose Again.\n\n");
                	}
            		else {
                 	board[0][1] = 'x';
              	  	spaceTaken2 = true;
                	}
         	}


          	if(userInput == 3){
            		if(spaceTaken3 == true){
                		printf("\nSpace already taken, Choose Again.\n\n");
                	}
            		else {
                  	board[0][2] = 'x';
              	  	spaceTaken3 = true;
                	}
		}

          	if(userInput == 4){
            		if(spaceTaken4 == true){
                		printf("\nSpace already taken, Choose Again.\n\n");
               		}
            		else {
                  	board[1][0] = 'x';
              	  	spaceTaken4 = true;
                	}
          	}

          	if(userInput == 5){
            		if(spaceTaken5 == true){
                		printf("\nSpace already taken, Choose Again.\n\n");
                	}
            		else {
                  	board[1][1] = 'x';
              	  	spaceTaken5 = true;
                	}
          	}

          	if(userInput == 6){
            		if(spaceTaken6 == true){
                		printf("\nSpace already taken, Choose Again.\n\n");
                	}
            		else {
                  	board[1][2] = 'x';
              	 	spaceTaken6 = true;
                	}
          	}

          	if(userInput == 7){
            		if(spaceTaken7 == true){
                		printf("\nSpace already taken, Choose Again.\n\n");
                	}
            		else {
                  	board[2][0] = 'x';
              	  	spaceTaken7 = true;
                	}
          	}

          	if(userInput == 8){
            		if(spaceTaken8 == true){
                		printf("\nSpace already taken, Choose Again.\n\n");
                	}
            		else {
                  	board[2][1] = 'x';
              	  	spaceTaken8 = true;
                	}
          	}


          	if(userInput == 9){
            		if(spaceTaken9 == true){
                		printf("\nSpace already taken, Choose Again.\n\n");
                	}
            		else {
                  	board[2][2] = 'x';
              	 	spaceTaken9 = true;
                	}
          	}

	}



void oMove(){
	int computerMove;
   	srand(time(0));
  
  	bool computerPlaced = false;
  	while(computerPlaced == false)
    {
       computerMove = rand() % 10;
      
       switch(computerMove)
       {
         case 1:
           if(spaceTaken1 == false)
           {
             computerPlaced = true;
           }
           
           break;
           
         case 2:
           if(spaceTaken2 == false)
           {
             computerPlaced = true;
           }
           break;
           
         case 3:
           if(spaceTaken3 == false)
           {
             computerPlaced = true;
           }
           break;
           
         case 4:
           if(spaceTaken4 == false)
           {
             computerPlaced = true;
           }
           break;
         case 5:
           if(spaceTaken5 == false)
           {
             computerPlaced = true;
           }
           break;
         case 6:
           if(spaceTaken6 == false)
           {
             computerPlaced = true;
           }
           break;
         case 7:
           if(spaceTaken7 == false)
           {
             computerPlaced = true;
           }
           break;
         case 8:
           if(spaceTaken8 == false)
           {
             computerPlaced = true;
           }
           break;
         case 9:
           if(spaceTaken9 == false)
           {
             computerPlaced = true;
           }
           break;
           
         default:
           break;
       }
    }
  
	// computerMove = rand() % 10;
		if(computerMove == 1){
            		if(spaceTaken1 == true){
			oMove();	
                	}
            		else {
                  	board[0][0] = 'o';
              	  	spaceTaken1 = true;
                	}
          	}

          	if(computerMove == 2){
            		if(spaceTaken2 == true){
			oMove();	
                	}
            		else {
                 	board[0][1] = 'o';
              	  	spaceTaken2 = true;
                	}
         	}


          	if(computerMove == 3){
            		if(spaceTaken3 == true){
			oMove();	
                	}
            		else {
                  	board[0][2] = 'o';
              	  	spaceTaken3 = true;
                	}
		}

          	if(computerMove == 4){
            		if(spaceTaken4 == true){
			oMove();	
               		}
            		else {
                  	board[1][0] = 'o';
              	  	spaceTaken4 = true;
                	}
          	}

          	if(computerMove == 5){
            		if(spaceTaken5 == true){
			oMove();	
                	}
            		else {
                  	board[1][1] = 'o';
              	  	spaceTaken5 = true;
                	}
          	}

          	if(computerMove == 6){
            		if(spaceTaken6 == true){
			oMove();	
                	}
            		else {
                  	board[1][2] = 'o';
              	 	spaceTaken6 = true;
                	}
          	}

          	if(computerMove == 7){
            		if(spaceTaken7 == true){
			oMove();	
                	}
            		else {
                  	board[2][0] = 'o';
              	  	spaceTaken7 = true;
                	}
          	}

          	if(computerMove == 8){
            		if(spaceTaken8 == true){
			oMove();	
                	}
            		else {
                  	board[2][1] = 'o';
              	  	spaceTaken8 = true;
                	}
          	}


          	if(computerMove == 9){
            		if(spaceTaken9 == true){
			oMove();	
                	}
            		else {
                  	board[2][2] = 'o';
              	 	spaceTaken9 = true;
                	}
          	}
          		drawBoard();
		
	
}

int main(){
    	printf("Wecome, We Are going to play Tic Tac Toe.\n\n");
    	drawGameBase();

	while(winner != 'x' || winner != 'o'){
	xMove();
	if(board[0][0] == 'x' && board[0][1] == 'x' && board[0][2] == 'x'){
		drawBoard();
		printf("\n'X' is the winner");
		winner = 'X';
		return winner;
	}
	if(board[0][0] == 'x' && board[1][0] == 'x' && board[2][0] == 'x'){
		drawBoard();
		printf("\n'X' is the winner");
		winner = 'X';
		return winner;
	}
	if(board[0][2] == 'x' && board[1][2] == 'x' && board[2][2] == 'x'){
		drawBoard();
		printf("\n'X' is the winner");
		winner = 'X';
		return winner;
	}
	if(board[2][0] == 'x' && board[2][1] == 'x' && board[2][2] == 'x'){
		drawBoard();
		printf("\n'X' is the winner");
		winner = 'X';
		return winner;
	}
	if(board[1][0] == 'x' && board[1][1] == 'x' && board[1][2] == 'x'){
		drawBoard();
		printf("\n'X' is the winner");
		winner = 'X';
		return winner;
	}
	if(board[0][1] == 'x' && board[1][1] == 'x' && board[2][1] == 'x'){
		drawBoard();
		printf("\n'X' is the winner!\n");
		winner = 'X';
		return winner;
	}
	if(board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x'){
		drawBoard();
		printf("\n'X' is the winner!\n");
		winner = 'X';
		return winner;
	}
	if(board[0][2] == 'x' && board[1][1] == 'x' && board[2][0] == 'x'){
		drawBoard();
		printf("\n'X' is the winner!\n");
		winner = 'X';
		return winner;
	}
	oMove();
	if(board[0][0] == 'o' && board[0][1] == 'o' && board[0][2] == 'o'){
		drawBoard();
		printf("\n'O' is the winner");
		winner = 'O';
		return winner;
	}
	if(board[0][0] == 'o' && board[1][0] == 'o' && board[2][0] == 'o'){
		drawBoard();
		printf("\n'O' is the winner");
		winner = 'O';
		return winner;
	}
	if(board[0][2] == 'o' && board[1][2] == 'o' && board[2][2] == 'o'){
		drawBoard();
		printf("\n'O' is the winner");
		winner = 'O';
		return winner;
	}
	if(board[2][0] == 'o' && board[2][1] == 'o' && board[2][2] == 'o'){
		drawBoard();
		printf("\n'O' is the winner");
		winner = 'O';
		return winner;
	}
	if(board[1][0] == 'o' && board[1][1] == 'o' && board[1][2] == 'o'){
		drawBoard();
		printf("\n'O' is the winner");
		winner = 'O';
		return winner;
	}
	if(board[0][1] == 'o' && board[1][1] == 'o' && board[2][1] == 'o'){
		drawBoard();
		printf("\n'O' is the winner!\n");
		winner = 'O';
		return winner;
	}
	if(board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o'){
		drawBoard();
		printf("\n'O' is the winner!\n");
		winner = 'O';
		return winner;
	}
	if(board[0][2] == 'o' && board[1][1] == 'o' && board[2][0] == 'o'){
		drawBoard();
		printf("\n'O' is the winner!\n");
		winner = 'O';
		return winner;
	}

	}	
    return 0;
}
