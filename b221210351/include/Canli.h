#ifndef CANLI_H
#define CANLI_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct CANLI{ 
    int can;
    int sinif;

    //fonk. göstericileri
    char* (*gorunum)(const Canli);
    void (*deleteCanli)(struct CANLI*);
}; 

typedef struct CANLI* Canli;

char* gorunum(const Canli);
Canli newCanli(int, int);
void deleteCanli(const Canli);

#endif