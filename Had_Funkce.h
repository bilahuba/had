#pragma once

#define widthField 40 // sirka pole
#define heightField 20 // vyska pole


int field[heightField][widthField];    // pole

// pozice hada, hlavy, ocasu
int x;
int y;
int Gy;
int head;
int tail;


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


