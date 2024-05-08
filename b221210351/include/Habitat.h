#ifndef HABITAT_H
#define HABITAT_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "Canli.h"
#include "Pire.h"
#include "Sinek.h"
#include "Bitki.h"

struct HABITAT{
    Canli **dizi; // CANLI* tipinde bir dizi oluşturuyoruz
    int satir_sayisi;
    int *sutun_sayilari;

    //fonk. göstericileri
    void (*startWar)(const Habitat);
    void (*printHabitat)(const Habitat);
    void (*deleteHabitat)(struct HABITAT*);
}; 
typedef struct HABITAT* Habitat;

Habitat newHabitat(Canli**, int, int*);
void startWar(const Habitat);
void printHabitat(const Habitat);
void deleteHabitat(const Habitat);

#endif