#include "Habitat.h"
#include "Bitki.h"
#include "Pire.h"

#include "stdio.h"
#include "stdlib.h"

//VERİ.TXT DOSYASINDAN VERİ OKURKEN SON SATIRDA Bİ BOŞLUK YOKSA ALTA GEÇMİYOR!!!!! DÜZELT

int main() {
    // Dosyayı aç
    FILE *dosya = fopen("veri.txt", "r");
    if (dosya == NULL) {
        fprintf(stderr, "Dosya açılamadı.");
        return 1;
    }

    // İki boyutlu dinamik dizi için bellek ayır
    Canli **dizi = NULL; // CANLI* tipinde bir dizi oluşturuyoruz
    int satir_sayisi = 0;
    int *sutun_sayilari = NULL;

    // Dosyadan verileri oku ve diziye ata
    int satir = 0;
    while (!feof(dosya)) {
        // Bellek yeniden boyutlandırma
        dizi = (Canli**)realloc(dizi, (satir_sayisi + 1) * sizeof(Canli*));
        if (dizi == NULL) {
            fprintf(stderr, "Bellek hatası!");
            return 1;
        }
        
        // Satırı oku
        int eleman;
        int sutun_sayisi = 0;
        dizi[satir_sayisi] = NULL;
        while (fscanf(dosya, "%d", &eleman) == 1) {
            // Bellek yeniden boyutlandırma
            dizi[satir_sayisi] = (Canli*)realloc(dizi[satir_sayisi], (sutun_sayisi + 1) * sizeof(Canli));
            if (dizi[satir_sayisi] == NULL) {
                fprintf(stderr, "Bellek hatası!");
                return 1;
            }
            
            // CANLI nesnesi oluştur ve diziye ata
            if(eleman <= 0){
                printf("Verilerde hata!");
                return 0;
            }
            else if(eleman < 10){
                dizi[satir_sayisi][sutun_sayisi] = newBitki(eleman)->super;
            }
            else if(eleman < 21){
                dizi[satir_sayisi][sutun_sayisi] = newBocek(eleman)->super;
            }
            else if(eleman < 51){
                dizi[satir_sayisi][sutun_sayisi] = newSinek(eleman)->super;
            }
            else if(eleman < 100){
                dizi[satir_sayisi][sutun_sayisi] = newPire(eleman)->super;
            }
            else{
                printf("Verilerde hata!");
                return 0;
            }
            sutun_sayisi++;
            
            // Satır sonuna geldiğimizde çık
            char karakter = fgetc(dosya);
            if (karakter == '\n' || karakter == EOF)
                break;
            else
                ungetc(karakter, dosya);
        }
        
        sutun_sayilari = (int *)realloc(sutun_sayilari, (satir_sayisi + 1) * sizeof(int));
        sutun_sayilari[satir_sayisi] = sutun_sayisi;
        
        satir_sayisi++;
    }

    // Dosyayı kapat
    fclose(dosya);

    Habitat habitat = newHabitat(dizi,satir_sayisi,sutun_sayilari);
    habitat->startWar(habitat);

    // Belleği serbest bırak
    for (int i = 0; i < satir_sayisi; i++) {
        free(dizi[i]);
    }
    free(dizi);
    free(sutun_sayilari);

    return 0;
}