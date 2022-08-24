#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define RESET "\x1B[0m"
#define BOLD "\x1B[1m"
#define MAXFAILS 6
#define WON 1
#define LOST 2
char body[MAXFAILS] = {' ',' ' ,' ',' ',' ',' '};
char userInput;//aero
char *randWord;
char *randCategory;
char numOfBlanks[15];//aero
int numOfChar;
int winOrLose = 3;
int numOfFails;
char incorrectGuesses[MAXFAILS];
char bodyParts[MAXFAILS] = {'O', '|', '/', '\\', '/', '\\'};

// Draw Hangman 
void drawHangMan(){
	printf("     +___+\n");
	printf("     |   |             \n");
	printf("     %c   |             \n", body[0]);
	printf("    %c%c%c  |             \n",body[2],body[1],body[3]);
	printf("    %c %c  |             \n",body[4],body[5]);
	printf("         |             \n");
	printf(" ==========\n");
}

// Create a Dictionary of words for Hangman
struct random{
	char *categorys[20];
	char *bodyRand[20];
	char *countryRand[20];
	char *vehicleRand[20];
	char *technologyRand[20];
	char *fruitRand[20];
	char *actorRand[20];
	char *professionRand[20];
	char *colorRand[20];
	char *natureRand[20];
	char *calendarRand[20];
};

// Set the Dictionary words
struct random randomStuff = {
	.categorys = {"body", "country", "vehicle", "technology", "fruit", "actor", "profession", "color", "nature", "calendar"},
	.bodyRand = {"HEART", "LEG", "HAND", "FACE", "TORSO"},
	.countryRand = {"INDIA", "PAKISTAN", "UNITED STATES", "UNITED KINGDOM", "RUSSIA", "CHINA", "JAPAN", "FRANCE", "INDONESIA", "PHILIPPINES", "KOREA", "SRI LANKA", "NEPAL"},
	.vehicleRand = {"CAR", "BOAT", "BIKE", "AEROPLANE", "SHIP", "JET", "CYCLE", "RICKSHAW"},
	.technologyRand = {"LAPTOP", "PHONE", "TELEVISION", "COMPUTER", "IPAD", "IPHONE", "AIR CONDITIONER", "HEADPHONES", "SPEAKER", "KEYBOARD", "MOUSE"},
	.fruitRand = {"BANANA", "APPLE", "ORANGE", "GRAPES", "MANGO", "WATERMELON", "PAPAYA", "PEAR", "CHERRY", "STRAWBERRY", "COCONUT", "GUAVA"},
	.actorRand = {"ALLU ARJUN", "SALMAN KHAN", "NTR", "MAHESH BABU", "TOM CRUISE", "WILL SMITH", "BEN AFFLECK", "CHRIS HEMSWORTH"},
	.professionRand = {"ENGINEER", "DOCTOR", "PIRATE", "PILOT", "DENTIST", "CARPAINTER"},
	.colorRand = {"ORANGE", "RED", "WHITE", "BLACK", "BLUE", "GREEN", "YELLOW", "PURPLE", "BROWN", "CYAN"},
	.natureRand  = {"PLANTS", "TREE", "CLIMATE", "WATER", "SOIL", "ATMOSPHERE"},
	.calendarRand = {"JANUARY", "FEBUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMEBER"},
};

// Select a random category and a random Word From the Dictionary.
char *throwRand(char *thingUserWant){
	if(strcmp(thingUserWant,"category") == 0){
		return randCategory = randomStuff.categorys[rand() % 10];
	}else if(strcmp(thingUserWant,"body") == 0){
		return randWord = randomStuff.bodyRand[rand() % 5];
	}else if(strcmp(thingUserWant,"country") == 0){
		return randWord = randomStuff.countryRand[rand() % 13];
	}else if(strcmp(thingUserWant,"vehicle") == 0){
		return randWord = randomStuff.vehicleRand[rand() % 8];
	}else if(strcmp(thingUserWant,"technology") == 0){
		return randWord = randomStuff.technologyRand[rand() % 11];
	}else if(strcmp(thingUserWant,"fruit") == 0){
		return randWord = randomStuff.fruitRand[rand() % 12];
	}else if(strcmp(thingUserWant,"actor") == 0){
		return randWord = randomStuff.actorRand[rand() % 8];
	}else if(strcmp(thingUserWant,"profession") == 0){
		return randWord = randomStuff.professionRand[rand() % 6];
	}else if(strcmp(thingUserWant,"color") == 0){
		return randWord = randomStuff.colorRand[rand() % 10];
	}else if(strcmp(thingUserWant,"nature") == 0){
		return randWord = randomStuff.natureRand[rand() % 6];
	}else if(strcmp(thingUserWant,"calendar") == 0){
		return randWord = randomStuff.calendarRand[rand() % 12];
	}
	return NULL;
}

// Check if user is correct or incorrect
void corOrInc(){
    	int found = 0; 
	// For Loop to loop through the randWord and check if userInput is correct or not.
	for(int i = 0; i < numOfChar; i++){
		if(randWord[i]== userInput){
			if(randWord[i] == numOfBlanks[i]){
				printf("\n You Enterd the same thing!\n");
			}
          		numOfBlanks[i]=userInput;
          		found++;
		}
     	} 
     	if(found!=0){
       	if(strcasecmp(randWord, numOfBlanks) == 0){
        	winOrLose = WON;
       	}
	}else{
		incorrectGuesses[numOfFails] = userInput;
		body[numOfFails] = bodyParts[numOfFails];
		numOfFails++;
		if(numOfFails == MAXFAILS){
			winOrLose = LOST;
		}	
	} 
}

// Don't listen to user if they put multiple alphabet in a single time
void safe_flush(FILE *fp){
 	int ch;
 	while( (ch = fgetc(fp)) != EOF && ch != '\n' );
}

// Get User Input
void UsrInp(){
	for(int i = 0; i < numOfChar; i ++){
	printf(" %c", numOfBlanks[i]);
	}
	printf("\n\n");
	printf(" Guess:  ");
	fflush(stdin);
	scanf(" %c", &userInput);
        safe_flush(stdin);
	userInput = toupper(userInput);
}

// Asign blank `_` vaule to the variable acording to the size of the randWord
void numBlank(){
    	for(int i = 0; i < numOfChar; i++){
        	if(isspace(randWord[i]) != 0){
           		numOfBlanks[i] = ' ';
        	}else{
           		numOfBlanks[i] = '_';
        	}
    	}	
}

// Magic Function
int main(){
	// Initialize srand/rand
	srand(time(NULL));
	printf("Welcome To HangMan, the rules are simple, guess the word, you can only do 6 mistakes, Enjoy!\n");
	// Draw Hangman
	drawHangMan();
	printf("\n\n The Category Is %s%s%s\n\n Guess The Word\n\n",BOLD, throwRand("category"), RESET);
	// Select a random Category
	throwRand(randCategory);
	// Get the number of Char for nunBlank
	numOfChar = strlen(randWord);
	// NumBLANK
	numBlank();
	while(1){
	// User INput
	UsrInp();
	// Check Correct or Incorrect Input
	corOrInc();
	printf("\n\n The Category Is %s%s%s\n", BOLD,randCategory, RESET);
	// Draw Hangman Again with the updated parts
	drawHangMan();
	printf("\nUsed Incorrect Words: %s%s%s\n",BOLD, incorrectGuesses, RESET); // New
	printf("\n");
	// Check if user Wins
	if(winOrLose == WON){
		for(int i = 0; i < numOfChar; i ++){
		printf(" %c", numOfBlanks[i]);
		}
		printf("\n\n You Have %sWON%s\n", BOLD,RESET);
		return winOrLose;
	}
	// Check if User Loses
	else if(winOrLose == LOST){
		printf("\n The Word Was %s%s%s\n", BOLD,randWord, RESET);
		printf("\n You Have %sLOST%s\n\n", BOLD,RESET);
		return winOrLose;
	}
	}
}
