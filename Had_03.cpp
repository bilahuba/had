
#include "Had_03.h"
#include "Had_Funkce.h"

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

using namespace std;


int main()
{

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