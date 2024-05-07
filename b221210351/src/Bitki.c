#include "Bitki.h"

//Bitki olustur
Bitki new_Bitki(int can){
    Bitki this;
    this=(Bitki)malloc(sizeof(struct BITKI));

    this->super=new_Canli(can);//üst siniftan sekil olustur

    //fonks gostericisi atamalari
    this->delete_Bitki=&delete_Bitki;
    
    return this;
}

void delete_Bitki(const Bitki this){
    if(this==NULL) return;
    this->super->delete_Canli(this->super);//önce sekili sil
    free(this);// sonra daireyi sil
}