#include "Bocek.h"

//Bitki olustur
Bocek new_Bocek(int can){
    Bocek this;
    this=(Bocek)malloc(sizeof(struct BOCEK));

    this->super=new_Canli(can);//üst siniftan sekil olustur

    //fonks gostericisi atamalari
    this->delete_Bocek=&delete_Bocek;
    
    return this;
}
void delete_Bocek(const Bocek this){
    if(this==NULL) return;
    this->super->delete_Canli(this->super);//önce sekili sil
    free(this);// sonra daireyi sil
}