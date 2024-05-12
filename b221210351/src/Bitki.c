#include "Bitki.h"

// Bitki olustur
Bitki newBitki(int can)
{
    Bitki this;
    this = (Bitki)malloc(sizeof(struct BITKI));
    this->super = newCanli(can, 4); // üst siniftan sekil olustur

    // fonks gostericisi atamalari
    this->deleteBitki = &deleteBitki;

    return this;
}

void deleteBitki(const Bitki this)
{
    if (this == NULL)
        return;
    this->super->deleteCanli(this->super); // önce sekili sil
    free(this);                            // sonra daireyi sil
}