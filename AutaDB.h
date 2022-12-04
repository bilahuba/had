#pragma once

#define ZNACKA_SIZE 21
#define ALBUM_SIZE 21

struct t_auto
{
    char  interpret[ZNACKA_SIZE];
    int   rok;
    char  album[ALBUM_SIZE];
    struct t_auto* dalsi;
};

/*char* vyhledavani;*/

void add(char* interpret, int rok, char* album, struct t_auto** uk_prvni);
void del(int rok, struct t_auto** uk_prvni);
