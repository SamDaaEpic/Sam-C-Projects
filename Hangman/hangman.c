#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define RESET "\x1B[0m"
#define BOLD "\x1B[1m"
char body[6] = {' ',' ' ,' ',' ',' ',' '};
char userInput;//aero
char *randWord;
char *randCategory;
char numOfBlanks[15];//aero
int numOfChar;
int winOrLoose = 3;
int numOfFails;
char incorrectGuesses[6];
void drawHangMan(){
	printf("     +___+\n");
	printf("     |   |             \n");
	printf("     %c   |             \n", body[0]);
	printf("    %c%c%c  |             \n",body[2],body[1],body[3]);
	printf("    %c %c  |             \n",body[4],body[5]);
	printf("         |             \n");
	printf(" ==========\n");
}

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

char *throwRand(char *thingUserWant){
	if(thingUserWant == "category"){
		return randCategory = randomStuff.categorys[rand() % 10];
	}else if(thingUserWant == "body"){
		randWord = randomStuff.bodyRand[rand() % 5];
		return randWord;
	}else if(thingUserWant == "country"){
		return randWord = randomStuff.countryRand[rand() % 13];
	}else if(thingUserWant == "vehicle"){
		return randWord = randomStuff.vehicleRand[rand() % 8];
	}else if(thingUserWant == "technology"){
		return randWord = randomStuff.technologyRand[rand() % 11];
	}else if(thingUserWant == "fruit"){
		return randWord = randomStuff.fruitRand[rand() % 12];
	}else if(thingUserWant == "actor"){
		return randWord = randomStuff.actorRand[rand() % 8];
	}else if(thingUserWant == "profession"){
		return randWord = randomStuff.professionRand[rand() % 6];
	}else if(thingUserWant == "color"){
		return randWord = randomStuff.colorRand[rand() % 10];
	}else if(thingUserWant == "nature"){
		return randWord = randomStuff.natureRand[rand() % 6];
	}else if(thingUserWant == "calendar"){
		return randWord = randomStuff.calendarRand[rand() % 12];
	}
}


bool corOrInc(char *checkWut){
	bool correctOrIncorrect;
    	int found = 0; 
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
           winOrLoose=1;
       	}
    	}else{
		numOfFails++;
			
	switch(numOfFails){
	case 1:
		body[0] = 'O';
		incorrectGuesses[0] = userInput;
		break;
	case 2:
		body[1] = '|';
		incorrectGuesses[1] = userInput;
		break;
	case 3:
		body[2] = '/';
		incorrectGuesses[2] = userInput;
		break;
	case 4:
		body[3] = '\\';
		incorrectGuesses[3] = userInput;
		break;
	case 5:
		body[4] = '/';
		incorrectGuesses[4] = userInput;
		break;
	case 6:
		body[5] = '\\';
		incorrectGuesses[5] = userInput;
		winOrLoose = 2;
		break;
	
	}

   } 
}

void safe_flush(FILE *fp)
{
 int ch;
 while( (ch = fgetc(fp)) != EOF && ch != '\n' );
}
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

void numBlank(){
    	for(int i = 0; i < numOfChar; i++){
        	if(isspace(randWord[i]) != 0){
           		numOfBlanks[i] = ' ';
        	}else{
           		numOfBlanks[i] = '_';
        	}
    	}	
}

int main(){
/*body[0] = 'O';
body[1] = '|';
body[2] = '/';
body[3] = '\\';
body[4] = '/';
body[5] = '\\';*/
	struct random random;
	srand(time(NULL));
	printf("Welcome To HangMan, the rules are simple, guess the word, you can only do 6 mistakes, Enjoy!\n");
	drawHangMan();
	//randomCategory();
	printf("\n\n The Category Is %s%s%s\n\n Guess The Word\n\n",BOLD, throwRand("category"), RESET);
	throwRand(randCategory);
	numOfChar = strlen(randWord);
	numBlank();//aero
	while(1){
	UsrInp();
	corOrInc(randCategory);
	printf("\n\n The Category Is %s%s%s\n", BOLD,randCategory, RESET);
	drawHangMan();
	printf("\nUsed Words: %s%s%s\n",BOLD, incorrectGuesses, RESET); // New
	printf("\n");
	if(winOrLoose == 1){
		for(int i = 0; i < numOfChar; i ++){
		printf(" %c", numOfBlanks[i]);
		}
		printf("\n\n You Have %sWON%s\n", BOLD,RESET);
		return winOrLoose;
	}else if(winOrLoose == 2){
		printf("\n The Word Was %s%s%s\n", BOLD,randWord, RESET);
		printf("\n You Have %sLOST%s\n\n", BOLD,RESET);
		return winOrLoose;
	}
	}
}
