// Had.cpp: Definuje vstupní bod pro aplikaci.
//

#include "Had.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

using namespace std;

#define widthField 40 // sirka pole
#define heightField 20 // vyska pole

int i;
int j;
int field[widthField][heightField];
int x;
int y;
int Gy;
int head;
int tail;
int game;
int fruit;
int A;
int B;
int var;
int direction;



void snakeInitialization() {                       // funkce vykreslení hada
	for (i = 0; i < heightField; i++)
	{
		for (j = 0; j < widthField; j++)
		{
			field[i][j] = 0;
		}
	}

	x = (heightField / 2) - 1;                           // vychozi pozice hada
	y = (widthField / 2) - 1;
	Gy = y;
	head = 5;
	tail = 1;
	game = 0;
	fruit = 0;
	direction = 77;


	for (i = 0; i < head; i++)                    // loop kde se kontroluje delka hada, moc nechapu!!
	{
		Gy++;
		field[x][Gy-head] = i + 1;
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

		for (j = 0; j < widthField; j++)
		{
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
				printf("O");
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

void randomFruit() {                                   // nahodna pozice ovoce
	srand(time(0));                      
	A = 1 + rand() % 18;
	B = 1 + rand() % 38;

	

	if (fruit == 0 && field[A][B] == 0)
	{
		field[A][B] = -1;
		fruit = 1;
	}
	

}


void ResetScreenPosition()                            // zakotvení obrazu při obnovování
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

int getStart()
{
	if (_kbhit())
	
		return _getch();
	
	else
	
		return -1;
	
}

void movement() {                            // pohyb
	var = getStart();
	/*
	if ((var == 77 || var == 75 || var == 72 || var == 80) && abs(direction - var)>2)
	{
		direction = var;
	} */
	
	if ((var == 77 || var == 75) && abs(direction - var) > 2)
	{
		direction = var;
	}
	
	 if ((var == 72 || var == 80) && abs(direction - var) > 8)
	{
		direction == var;
	}
	



	if (direction == 77) {                   // doprava
		y++;
		head++;
		field[x][y] = head;
	}

	if (direction == 75) {                   // doleva
		y--;
		head++;
		field[x][y] = head;
	}

	if (direction == 72) {                   // nahoru
		x--;
		head++;
		field[x][y] = head;
	}

	if (direction == 80) {                   // dolu
		x++;
		head++;
		field[x][y] = head;
	}
}


void tailRemove()                   // odebrani konce hada
{
	for ( i = 0; i < heightField; i++)
	{
		for ( j = 0; j < widthField; j++)
		{
			if (field[i][j] == tail)
			{
				field[i][j] == 0;
			}
		}
	}
	tail++;
}



int main()
{
	snakeInitialization();

	while (game == 0)
	{
		printField();
		ResetScreenPosition();
		randomFruit();
		movement();
		Sleep(99);
		tailRemove;
	}
	
}