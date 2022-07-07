#include <stdio.h>
#include <stdlib.h>

int main()
{
    int age;
    int year = 2022;
    printf("This program will tell you your birth of year, you just have to enter in your age below.\n");
    printf("Whats your age? Enter here:");
    scanf("%d",&age);
    int BirthYear = year - age;
    printf("You was born in %d year", BirthYear);


     return 0;
}
