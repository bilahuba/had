
// had_03.cpp : Defines the entry point for the application.
//

#include "Had_03.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define widthField 40 // sirka pole
#define heightField 20 // vyska pole

int field[heightField][widthField];    // pole

// pozice hada, hlavy, ocasu
int x;
int y;
int Gy;
int head;
int tail;

int i;
int j;
int game;



// ovoce  // pozice ovoce
int fruit;
int a;
int b;


int var;         // klavesa
int direction;   // smer

// bodovani
int score;
int highScore;


// sipky
int doprava = 77;
int doleva = 75;
int dolu = 80;
int nahoru = 72;

using namespace std;

void setup()					// funkce vykreslení hada - setup hry - vychozi hodnoty
{
	for (i = 0; i < heightField; i++)
	{
		for (j = 0; j < widthField; j++)
		{
			field[i][j] = 0;
		}
	}

	y = widthField / 2 - 1;                           // vychozi pozice hada
	x = heightField / 2 - 1;
	head = 5;										  // vychozi hodnoty hry
	tail = 1;
	Gy = y;
	game = 0;
	fruit = 0;
	direction = 77;
	score = 0;


	for (i = 0; i < head; i++)                    // loop pro vykreslení ocasu
	{
		Gy++;
		field[x][Gy - head] = i + 1;

	}
}

void printField()				// funkce pro vykreslení ètverce pole a hada
{
	for (i = 0; i <= widthField + 1; i++)
	{
		if (i == 0)
		{
			printf("%c", 201);                 // %c - znaky asci tabulka  
		}
		else if (i == widthField + 1)
		{
			printf("%C", 187);
		}
		else
		{
			printf("%c", 205);
		}
	}

	printf("  Skore: %d  Nejvyssi skore: %d", score, highScore);
	printf("\n");


	for (i = 0; i < heightField; i++)
	{
		printf("%c", 186);

		for (j = 0; j < widthField; j++)
		{
			if (field[i][j] == 0)
			{
				printf(" ");
			}

			if (field[i][j] > 0 && field[i][j] != head)
			{
				printf("x");
			}

			if (field[i][j] == head)
			{
				printf("%c", 254);

			}
			if (field[i][j] == -1)
			{
				printf("0");
			}

			if (j == widthField - 1)
			{
				printf("%c\n", 186);
			}
		}
	}

	for (i = 0; i <= widthField + 1; i++)
	{
		if (i == 0)
		{
			printf("%c", 200);
		}
		else if (i == widthField + 1)
		{
			printf("%C", 188);
		}
		else
		{
			printf("%c", 205);
		}
	}
}

void resetScreenPosition()                             // funkce k zastaveni skakani obrazu pri obnovovani
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void randomFruit()                                       // funkce pro random spawn ovoce
{
	srand(time(0));
	a = 1 + rand() % 18;
	b = 1 + rand() % 38;

	if (fruit == 0 && field[a][b] == 0)
	{
		field[a][b] = -1;
		fruit = 1;
	}
}


int getKey()                     // _getch je 2x, protože pak je odezva kalvesnice skzr sipky rychlejsi 
{										// had rychleji zatoci
	if (_kbhit())
	{
		_getch();
		return _getch();
	}
	else
	{
		return -1;
	}
}

void gameOver()                        // konec hry
{
	printf("\a");
	Sleep(1500);
	system("cls");                     // smazat obrazovku


	// zapis hrace a skore



	// vypis tabulky nej hracu


	system("cls");
	printf("\n\n  !!! GAME OVER !!!");
	printf("    Skore: %d ", score);




	game = 1;
}

void movement()                                        // pohyb hada
{
	var = getKey();

	if ((var == doprava && direction != doleva) || (var == doleva && direction != doprava) || (var == dolu && direction != nahoru) || (var == nahoru && direction != dolu))
	{
		direction = var;                               // podminka pro zajisteni protismeru hada
	}

	if (direction == doprava) {                   // doprava
		y++;

		if (field[x][y] != 0 && field[x][y] != -1)
		{
			gameOver();
		}

		if (y == widthField)		// nepruchozi hrany
		{
			//y = 0;
			gameOver();
		}

		if (field[x][y] == -1)			// dotknuti jidla
		{
			fruit = 0;
			score += 5;
			tail -= 1;
		}

		head++;
		field[x][y] = head;
	}

	if (direction == doleva) {                   // doleva
		y--;

		if (field[x][y] != 0 && field[x][y] != -1)
		{
			gameOver();
		}

		if (y == 0 - 1)		// nepruchozi hrany
		{
			//y = 0;
			gameOver();
		}

		if (field[x][y] == -1)			// dotknuti jidla
		{
			fruit = 0;
			score += 5;
			tail -= 1;
		}

		head++;
		field[x][y] = head;
	}

	if (direction == nahoru) {                   // nahoru
		x--;

		if (field[x][y] != 0 && field[x][y] != -1)
		{
			gameOver();
		}

		if (x == -1)		// nepruchozi hrany
		{
			//y = 0;
			gameOver();
		}

		if (field[x][y] == -1)			// dotknuti jidla
		{
			fruit = 0;
			score += 5;
			tail -= 1;
		}

		head++;
		field[x][y] = head;
	}

	if (direction == dolu) {                   // dolu
		x++;

		if (field[x][y] != 0 && field[x][y] != -1)
		{
			gameOver();
		}

		if (x == heightField)		// nepruchozi hrany
		{
			//y = 0;
			gameOver();
		}

		if (field[x][y] == -1)			// dotknuti jidla
		{
			fruit = 0;
			score += 5;
			tail -= 1;
		}

		head++;
		field[x][y] = head;
	}
}

void tailRemove()                         // funkce mazani ocasu hada
{
	for (i = 0; i < heightField; i++)
	{
		for (j = 0; j < widthField; j++)
		{
			if (field[i][j] == tail)
			{
				field[i][j] = 0;
			}
		}
	}
	tail++;
}



int main()
{
	char name;
	FILE *f;
		
	f = fopen("D:\\score.txt", "w");


	printf("Zadej jmeno hrace:");
	scanf("%s", &name);

	fprintf(f, &name);
	fclose(f);
	

	system("pause");
	system("cls");

	setup();

	while (game == 0)
	{

		printField();
		resetScreenPosition();
		randomFruit();
		movement();
		tailRemove();
		Sleep(90);                     // rychlost hada

	}
	


	return 0;
}