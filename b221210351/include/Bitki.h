#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"

struct BITKI{

Canli super;//üst sinifa erisim

//fonks gostericisi
void (*deleteBitki)(struct BITKI*);

};
typedef struct BITKI* Bitki;

Bitki newBitki(int);
void deleteBitki(const Bitki);

#endif