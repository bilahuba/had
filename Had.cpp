// Had.cpp: Definuje vstupní bod pro aplikaci.
//

#include "Had.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

#define widthField 30 // sirka pole
#define heightField 20 // vyska pole

int i;
int j;
int field[widthField][heightField];
int x;
int y;
int Gx;
int head;
int tail;



void snakeInitialization() {                       // funkce vykreslení hada
	for (i = 0; i < heightField; i++)
	{
		for (j = 0; j < widthField; j++)
		{
			field[i][j] = 0;
		}
	}

	y = heightField / 2;                           // vychozi pozice hada
	x = widthField / 2;
	Gx = x;
	head = 5;
	tail = 1;


	for (i = 0; i < head; i++)                    // loop kde se kontroluje delka hada, moc nechapu!!
	{
		Gx++;
		field[y][Gx - head] = i + 1;
	}
}


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
			if (field[i][j]==0)
			{
				printf(" ");
			}
			
			if (field[i][j] > 0 && field[i][j] != head)               // vložení prvního hada
			{
				printf("x");
			}
			if (field[i][j] == head)
			{
				printf("%c", 254);
			}
			if (field[i][j] == -1)
			{
				printf("%c", 15);
			}
			
			if (j == widthField - 1)
			{
				printf("%c\n", 186);
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






void ResetScreenPosition()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}


void main()
{
	snakeInitialization();
	printField();

/*
	while (Game == 0)
	{
		printf();
		ResetScreenPosition();

	}
	*/
}