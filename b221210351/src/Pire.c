#include "Pire.h"

//Bitki olustur
Pire newPire(int can){
    Pire this;
    this=(Pire)malloc(sizeof(struct PIRE));

    char* str;
    strcpy(str,"Pire");
    this->super=newCanli(can,str);//üst siniftan sekil olustur

    //fonks gostericisi atamalari
    this->deletePire=&deletePire;
    
    return this;
}
void deletePire(const Pire this){
    if(this==NULL) return;
    this->super->deleteCanli(this->super);//önce sekili sil
    free(this);// sonra daireyi sil
}