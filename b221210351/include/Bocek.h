#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"

struct BOCEK{

Canli super;//üst sinifa erisim

//fonks gostericisi
void (*delete_Bocek)(struct BOCEK*);

};
typedef struct BOCEK* Bocek;

Bocek new_Bocek(int);
void delete_Bocek(const Bocek);

#endif