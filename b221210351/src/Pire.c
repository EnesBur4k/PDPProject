#include "Pire.h"

//Bitki olustur
Pire new_Pire(int can){
    Pire this;
    this=(Pire)malloc(sizeof(struct PIRE));

    this->super=new_Canli(can);//üst siniftan sekil olustur

    //fonks gostericisi atamalari
    this->delete_Pire=&delete_Pire;
    
    return this;
}
void delete_Pire(const Pire this){
    if(this==NULL) return;
    this->super->delete_Canli(this->super);//önce sekili sil
    free(this);// sonra daireyi sil
}