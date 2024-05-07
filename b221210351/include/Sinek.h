#ifndef SINEK_H
#define SINEK_H

#include "Canli.h"

struct SINEK{

Canli super;//üst sinifa erisim

//fonks gostericisi
void (*delete_Sinek)(struct SINEK*);

};
typedef struct SINEK* Sinek;

Sinek new_Sinek(int);
void delete_Sinek(const Sinek);

#endif