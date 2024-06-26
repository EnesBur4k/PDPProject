#include "Pire.h"

// Bitki olustur
Pire newPire(int can)
{
    Pire this;
    this = (Pire)malloc(sizeof(struct PIRE));
    this->super = newBocek(can, 1); // üst siniftan sekil olustur

    // fonks gostericisi atamalari
    this->deletePire = &deletePire;

    return this;
}
void deletePire(const Pire this)
{
    if (this == NULL)
        return;
    this->super->deleteBocek(this->super); // önce sekili sil
    free(this);                            // sonra daireyi sil
}