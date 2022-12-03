// Had.cpp: Definuje vstupní bod pro aplikaci.
//

#include "Had.h"
#include <stdio.h>

using namespace std;

#define A 40 // sirka pole
#define B 20 // vyska pole

int i;
int j;





void main()
{
	for ( i=0; i <= A+1; i++)
	{
		if (i == 0) {
			printf("%c", 201);
		}
		else if (i == A+1) {
			printf(" %C", 187);
		}
		else
		{
			printf("%c", 205);
		}
	}
	printf("\n");

	for (i = 0; i < B; i++)
	{
		printf("%c", 186);
		for (j = 0; j < A; j++) {
			if (j==A-1)
			{
					printf(" %c\n", 186);
			}
			else
			{
				printf(" ");
			}
		}
	}

	for (i = 0; i <= A + 1; i++)
	{
		if (i == 0) {
			printf("%c", 200);
		}
		else if (i == A + 1) {
			printf(" %C", 188);
		}
		else
		{
			printf("%c", 205);
		}
	}

}

