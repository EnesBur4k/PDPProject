#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"

struct BITKI{

Canli super;//üst sinifa erisim

//fonks gostericisi
void (*delete_Bitki)(struct BITKI*);

};
typedef struct BITKI* Bitki;

Bitki new_Bitki(int);
void delete_Bitki(const Bitki);

#endif