#include "Canli.h"

Canli newCanli(int can, int sinif)
{
    Canli this;
    this = (Canli)malloc(sizeof(struct CANLI));

    // sinif değişkeni değerleri:
    // 0: Ölü
    // 1: Pire
    // 2: Böcek
    // 3: Sinek
    // 4: Bitki

    this->sinif = sinif;
    this->can = can;

    // fonksiyon gosterici ataması
    this->gorunum = &gorunum;
    this->deleteCanli = &deleteCanli;

    return this;
}

void deleteCanli(const Canli this)
{
    if (this == NULL)
        return;
    free(this->gorunum);
    free(this);
}
char *gorunum(const Canli this)
{
    char *str = (char *)malloc(sizeof(char));
    if (this->sinif == 0)
    {
        sprintf(str, "%s ", "X");
    }
    else if (this->sinif == 1)
    {
        sprintf(str, "%s ", "P");
    }
    else if (this->sinif == 2)
    {
        sprintf(str, "%s ", "C");
    }
    else if (this->sinif == 3)
    {
        sprintf(str, "%s ", "S");
    }
    else if (this->sinif == 4)
    {
        sprintf(str, "%s ", "B");
    }
    return str;
}