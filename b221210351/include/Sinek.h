#ifndef SINEK_H
#define SINEK_H

#include "Bocek.h"

struct SINEK{

Canli super;//üst sinifa erisim

//fonks gostericisi
void (*deleteSinek)(struct SINEK*);

};
typedef struct SINEK* Sinek;

Sinek newSinek(int);
void deleteSinek(const Sinek);

#endif