// Had.cpp: Definuje vstupní bod pro aplikaci.
//

#include "Had.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

#define widthField 40 // sirka pole
#define heightField 20 // vyska pole

int i;
int j;
int pole[widthField][heightField];

void printField() {                            // funkce pro vykreslení čtverce pole
	for (i = 0; i <= widthField + 1; i++)
	{
		if (i == 0) {
			printf("%c", 201);                 // %c - znaky asci tabulka  
		}
		else if (i == widthField + 1) {
			printf("%C", 187);
		}
		else
		{
			printf("%c", 205);
		}
	}
	printf("\n");

	for (i = 0; i < heightField; i++)
	{
		printf("%c", 186);
		for (j = 0; j < widthField; j++) {
			if (j == widthField - 1)
			{
				printf(" %c\n", 186);
			}
			else
			{
				printf(" ");
			}
		}
	}

	for (i = 0; i <= widthField + 1; i++)
	{
		if (i == 0) {
			printf("%c", 200);
		}
		else if (i == widthField + 1) {
			printf("%C", 188);
		}
		else
		{
			printf("%c", 205);
		}
	}
}



void snakeInitialization() {                       // funkce vykreslení hada



}


void ResetScreenPosition()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}


void main(){
	printField();
	snakeInitialization();
	
	while (Game == 0)
	{
		printf();
		ResetScreenPosition();

	}

}

