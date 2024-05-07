#ifndef CANLI_H
#define CANLI_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct CANLI{ 
    int can;

    //fonk. göstericileri
    char* (*gorunum)();
    void (*delete_Canli)(struct CANLI*);
}; 

typedef struct CANLI* Canli;

char* gorunum(const Canli);
Canli new_Canli(int);
void delete_Canli(const Canli);

#endif