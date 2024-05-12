#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"

struct BOCEK
{

    Canli super; // üst sinifa erisim

    // fonks gostericisi
    void (*deleteBocek)(struct BOCEK *);
};
typedef struct BOCEK *Bocek;

Bocek newBocek(int, int);
void deleteBocek(const Bocek);

#endif