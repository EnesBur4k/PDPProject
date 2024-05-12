#include "Sinek.h"

// Bitki olustur
Sinek newSinek(int can)
{
    Sinek this;
    this = (Sinek)malloc(sizeof(struct SINEK));
    this->super = newBocek(can, 3); // üst siniftan sekil olustur

    // fonks gostericisi atamalari
    this->deleteSinek = &deleteSinek;

    return this;
}
void deleteSinek(const Sinek this)
{
    if (this == NULL)
        return;
    this->super->deleteBocek(this->super); // önce sekili sil
    free(this);                            // sonra daireyi sil
}