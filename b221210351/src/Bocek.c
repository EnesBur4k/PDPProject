#include "Bocek.h"

//Bitki olustur
Bocek newBocek(int can){
    Bocek this;
    this=(Bocek)malloc(sizeof(struct BOCEK));
    this->super=newCanli(can,2);//üst siniftan sekil olustur

    //fonks gostericisi atamalari
    this->deleteBocek=&deleteBocek;
    
    return this;
}
void deleteBocek(const Bocek this){
    if(this==NULL) return;
    this->super->deleteCanli(this->super);//önce sekili sil
    free(this);// sonra daireyi sil
}