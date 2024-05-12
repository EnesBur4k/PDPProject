#include "Habitat.h"
#include "Bitki.h"
#include "Pire.h"
#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    Node head = NULL;
    // Dosyayı aç
    FILE *dosya = fopen("Veri.txt", "r");
    if (dosya == NULL)
    {
        fprintf(stderr, "Dosya açılamadı.");
        return 1;
    }

    // İki boyutlu dinamik dizi için bellek ayır
    Canli **dizi = NULL;
    int satir_sayisi = 0;
    int *sutun_sayilari = NULL;

    // Dosyadan verileri oku ve diziye ata
    char satir[1000]; // Yeterince büyük bir tampon
    while (fgets(satir, sizeof(satir), dosya) != NULL)
    {
        // Bellek yeniden boyutlandırma
        dizi = (Canli **)realloc(dizi, (satir_sayisi + 1) * sizeof(Canli *));
        if (dizi == NULL)
        {
            fprintf(stderr, "Bellek hatası!");
            return 1;
        }

        // Bellek ayırma ve işleme başla
        char *token = strtok(satir, " \n");
        int sutun_sayisi = 0;
        dizi[satir_sayisi] = NULL;
        while (token != NULL)
        {
            // Bellek yeniden boyutlandırma
            dizi[satir_sayisi] = (Canli *)realloc(dizi[satir_sayisi], (sutun_sayisi + 1) * sizeof(Canli));
            if (dizi[satir_sayisi] == NULL)
            {
                fprintf(stderr, "Bellek hatası!");
                return 1;
            }

            // CANLI nesnesi oluştur ve diziye ata
            // Burada bitki nesneleri silinebilir *valgrind
            int eleman = atoi(token);
            if (eleman <= 0)
            {
                printf("Verilerde hata!");
                return 0;
            }
            else if (eleman < 10)
            {
                Bitki yeniBitki = newBitki(eleman);
                dizi[satir_sayisi][sutun_sayisi] = yeniBitki->super;
                insertAtBeginning(&head, yeniBitki, "Bitki");
            }
            else if (eleman < 21)
            {
                Bocek yeniBocek = newBocek(eleman, 2);
                dizi[satir_sayisi][sutun_sayisi] = yeniBocek->super;
                insertAtBeginning(&head, yeniBocek, "Bocek");
            }
            else if (eleman < 51)
            {
                Sinek yeniSinek = newSinek(eleman);
                dizi[satir_sayisi][sutun_sayisi] = yeniSinek->super->super;
                insertAtBeginning(&head, yeniSinek, "Sinek");
            }
            else if (eleman < 100)
            {
                Pire yeniPire = newPire(eleman);
                dizi[satir_sayisi][sutun_sayisi] = yeniPire->super->super;
                insertAtBeginning(&head, yeniPire, "Pire");
            }
            else
            {
                printf("Verilerde hata!");
                return 0;
            }
            sutun_sayisi++;

            // Bir sonraki elemana geç
            token = strtok(NULL, " \n");
        }

        // Sütun sayısını kaydet
        sutun_sayilari = (int *)realloc(sutun_sayilari, (satir_sayisi + 1) * sizeof(int));
        sutun_sayilari[satir_sayisi] = sutun_sayisi;

        // Satır sayısını artır
        satir_sayisi++;
    }

    // Dosyayı kapat
    fclose(dosya);

    // Habitat oluştur ve işleme başla
    Habitat habitat = newHabitat(dizi, satir_sayisi, sutun_sayilari);
    habitat->startWar(habitat);

    // Belleği serbest bırak
    for (int i = 0; i < satir_sayisi; i++)
    {
        free(dizi[i]);
    }

    // Bellekteki canli nesnelerini siler
    while (head != NULL)
    {
        if (strcmp(head->c, "Bitki") == 0)
        {
            ((Bitki)(head->data))->deleteBitki((Bitki)(head->data));
        }
        else if (strcmp(head->c, "Bocek") == 0)
        {
            ((Bocek)(head->data))->deleteBocek((Bocek)(head->data));
        }
        else if (strcmp(head->c, "Sinek") == 0)
        {
            ((Sinek)(head->data))->deleteSinek((Sinek)(head->data));
        }
        else if (strcmp(head->c, "Pire") == 0)
        {
            ((Pire)(head->data))->deletePire((Pire)(head->data));
        }
        head = head->next;
    }
    free(dizi);
    free(sutun_sayilari);

    return 0;
}