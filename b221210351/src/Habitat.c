#include "Habitat.h"

Habitat newHabitat(Canli **dizi, int satir_sayisi, int *sutun_sayilari)
{
    Habitat this;
    this = (Habitat)malloc(sizeof(struct HABITAT));
    printf("Habitat olustu \n");
    this->dizi = dizi;
    this->satir_sayisi = satir_sayisi;
    this->sutun_sayilari = sutun_sayilari;

    // fonksiyon gosterici ataması
    this->deleteHabitat = &deleteHabitat;
    this->startWar = &startWar;
    this->printHabitat = &printHabitat;

    return this;
}

// burada dizinin başından başlayıp sağına doğru gideceğim satır bitince alt satıra geçip bakacağım eğer birinci canlı ikinci canlıyı
// yeme kondisyonlarını yerine getiriyorsa yiyecek getirmiyorsa ikinci canlı yiyecek
void startWar(const Habitat this)
{
    Canli birinciCanli = NULL;
    for (int i = 0; i < this->satir_sayisi; i++)
    {
        for (int j = 0; j < this->sutun_sayilari[i]; j++)
        {
            if (birinciCanli == NULL)
            {
                birinciCanli = this->dizi[0][0];
                this->birinciCanliX = i;
                this->birinciCanliY = j;
                printHabitat(this);
                printf("\n");

                continue;
            }

            if ((birinciCanli->sinif == 2) && (this->dizi[i][j]->sinif == 4))
            {
                this->dizi[i][j]->sinif = 0;
            }
            else if ((birinciCanli->sinif == 4) && (this->dizi[i][j]->sinif == 2))
            {
                birinciCanli->sinif = 0;
                birinciCanli = this->dizi[i][j];
                this->birinciCanliX = i;
                this->birinciCanliY = j;
            }
            else if (birinciCanli->sinif > this->dizi[i][j]->sinif)
            {
                this->dizi[i][j]->sinif = 0;
            }
            else if (birinciCanli->sinif < this->dizi[i][j]->sinif)
            {
                birinciCanli->sinif = 0;
                birinciCanli = this->dizi[i][j];
                this->birinciCanliX = i;
                this->birinciCanliY = j;
            }
            else if (birinciCanli->sinif == this->dizi[i][j]->sinif)
            {
                if (birinciCanli->can > this->dizi[i][j]->can)
                {
                    this->dizi[i][j]->sinif = 0;
                }
                else if (birinciCanli->can < this->dizi[i][j]->can)
                {
                    birinciCanli->sinif = 0;
                    birinciCanli = this->dizi[i][j];
                    this->birinciCanliX = i;
                    this->birinciCanliY = j;
                }
                else
                {
                    if (this->birinciCanliX < i)
                    {
                        this->dizi[i][j]->sinif = 0;
                    }
                    else if (this->birinciCanliX == i)
                    {
                        this->dizi[i][j]->sinif = 0;
                    }
                }
            }
            printHabitat(this);
            printf("\n");
        }
    }
    printf("Kazanan: %s : (%d,%d)", birinciCanli->gorunum(birinciCanli), this->birinciCanliX, this->birinciCanliY);
}

void printHabitat(const Habitat this)
{
    for (int i = 0; i < this->satir_sayisi; i++)
    {
        for (int j = 0; j < this->sutun_sayilari[i]; j++)
        {
            printf("%s ", this->dizi[i][j]->gorunum(this->dizi[i][j]));
        }
        printf("\n");
    }
}

void deleteHabitat(const Habitat this)
{
    if (this == NULL)
        return;
    free(this);
    printf("Habitat silindi \n");
}