#include <stdio.h>
#include <stdlib.h>

int num1,num2,whatYouWantToAdd;
int result;
void calculator(){
	printf("1. Addition \n2. Subtraction\n3. Multiplication.\n4. Division.\n5. Exit.\n\nEnter(1-5): ");
	scanf("%d", &whatYouWantToAdd);
		if(whatYouWantToAdd == 1){
			printf("\nYou Selected Addition\n\n");
			printf("Enter Two Numbers To Add: ");
			scanf("%d", &num1);
			printf("Enter Second Number: ");
			scanf("%d", &num2);
			result = num1 + num2;
			printf("The Answer is: %d", result);
		}
		if(whatYouWantToAdd == 2){
			printf("\nYou Selected Subtraction\n\n");
			printf("Enter Two Numbers To Subtract: ");
			scanf("%d", &num1);
			printf("Enter Second Number: ");
			scanf("%d", &num2);
			result = num1 - num2;
			printf("The Answer is: %d", result);
		}
		if(whatYouWantToAdd == 3){
			printf("\nYou Selected Multiplication\n\n");
			printf("Enter Two Numbers To Multiply: ");
			scanf("%d", &num1);
			printf("Enter Second Number: ");
			scanf("%d", &num2);
			result = num1 * num2;
			printf("The Answer is: %d", result);
		}
		if(whatYouWantToAdd == 4){
			printf("\nYou Selected Division\n\n");
			printf("Enter Two Numbers To Divide: ");
			scanf("%d", &num1);
			printf("Enter Second Number: ");
			scanf("%d", &num2);
			result = num1 / num2;
			printf("The Answer is: %d", result);
		}
		if(whatYouWantToAdd == 5){
			printf("You Pressed 5 To Exit, Bye");
			exit(0);
		}
}

int main(){
	calculator();
	return 0;
}
