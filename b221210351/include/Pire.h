#ifndef PIRE_H
#define PIRE_H

#include "Canli.h"

struct PIRE{

Canli super;//üst sinifa erisim

//fonks gostericisi
void (*delete_Pire)(struct PIRE*);

};
typedef struct PIRE* Pire;

Pire new_Pire(int);
void delete_Pire(const Pire);

#endif