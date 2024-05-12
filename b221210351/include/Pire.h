#ifndef PIRE_H
#define PIRE_H

#include "Bocek.h"

struct PIRE{

Bocek super;//üst sinifa erisim

//fonks gostericisi
void (*deletePire)(struct PIRE*);

};
typedef struct PIRE* Pire;

Pire newPire(int);
void deletePire(const Pire);

#endif