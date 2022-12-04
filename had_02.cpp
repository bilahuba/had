// had_02.cpp : Defines the entry point for the application.
//

#include "had_02.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

using namespace std;

#define widthField 30 // sirka pole
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
int a;
int b;
int var;
int dir;
int score;
int highScore;

//FILE* f;

void snakeInitialization()					// funkce vykreslení hada
{
	/*f = fopen("highscore.txt", "r");
	fscanf(f, "%d", &highScore);
	fclose(f);*/

	for (i = 0; i < heightField; i++)
	{
		for (j = 0; j < widthField; j++)
		{
			field[i][j] = 0;
		}
	}

	y = widthField / 2 - 1;                           // vychozi pozice hada
	x = heightField / 2 - 1;
	head = 5;
	tail = 1;
	Gy = y;
	game = 0;
	fruit = 0;
	dir = 'd';
	score = 0;




	for (i = 0; i < head; i++)                    // loop kde se kontroluje delka hada, moc nechapu!!
	{
		Gy++;
		field[x][Gy - head] = i + 1;

	}




}

void printField()				// funkce pro vykreslení čtverce pole a hada
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
				printf("%c", 176);
			}

			if (field[i][j] == head)
			{
				printf("%c", 178);

			}
			if (field[i][j] == -1)
			{
				printf("%c", 126);
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


void resetScreenPosition()                                                    // zakotvení obrazu při obnovování
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void random()                                                                // funkce pro random spawnutí ovoce
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

int getch_noblock()                                                          // funkce zjišťování zda je stisknuta klávesa
{
	if (_kbhit())
		return _getch();
	else
		return -1;
}

void gameOver()
{
	printf("\a");
	Sleep(1500);
	system("cls");

	if (score > highScore)
	{
		printf("Novy rekord %d !!!", score);
		//system("pause");
		//f = fopen("highscore.txt", "w");
		//fprintf(f, "%d", score);
		//fclose(f);

	}

	system("cls");
	printf("\n\n  !!! GAME OVER !!!");
	printf("    Skore: %d ", score);

	game = 1;
}

void movement()                                                             // pohyby hada
{
	var = getch_noblock();
	var = tolower(var);

	if (((var == 'd' || var == 'a') || (var == 'w' || var == 's')) && (abs(dir - var) > 5))
	{
		dir = var;
	}

	if (dir == 'd')
	{
		y++;
		if (field[x][y] != 0 && field[x][y] != -1)
		{
			gameOver();
		}
		if (y == widthField )		//nepruchozi hrany
		{
			//y = 0;
			gameOver();
		}

		if (field[x][y] == -1)			//dotknuti jidla
		{
			fruit = 0;
			score += 5;
			tail -= 1;
		}

		head++;
		field[x][y] = head;
	}

	if (dir == 'a')
	{
		y--;

		if (field[x][y] != 0 && field[x][y] != -1)
		{
			gameOver();
		}

		if (y == 0 -1)						//nepruchozi hrany
		{
			//y = widthField - 1;
			gameOver();
		}

		if (field[x][y] == -1)			//dotknuti jidla
		{
			fruit = 0;
			score += 5;
			tail -= 1;
		}

		head++;
		field[x][y] = head;
	}

	if (dir == 'w')
	{
		x--;

		if (field[x][y] != 0 && field[x][y] != -1)
		{
			gameOver();
		}

		if (x == -1)					//nepruchozi hrany
		{
			//x = heightField - 1;
			gameOver();
		}

		if (field[x][y] == -1)			//dotknuti jidla
		{
			fruit = 0;
			score += 5;
			tail -= 1;
		}

		head++;
		field[x][y] = head;
	}

	if (dir == 's')
	{
		x++;

		if (field[x][y] != 0 && field[x][y] != -1)
		{
			gameOver();
		}

		if (x == heightField )			//nepruchozi hrany
		{
			//x = 0;
			gameOver();
		}

		if (field[x][y] == -1)				//dotknuti jidla
		{
			fruit = 0;
			score += 5;
			tail -= 1;
		}

		head++;
		field[x][y] = head;
	}
}

void tailRemove()                                                       // odmazávání ocasu hada
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
	snakeInitialization();


	while (game == 0)
	{
		printField();
		resetScreenPosition();
		random();
		movement();
		tailRemove();
		Sleep(200);

	}

	return 0;
}
