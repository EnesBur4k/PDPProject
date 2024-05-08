#include "Sinek.h"

//Bitki olustur
Sinek newSinek(int can){
    Sinek this;
    this=(Sinek)malloc(sizeof(struct SINEK));

    char* str;
    strcpy(str,"Sinek");
    this->super=newCanli(can,str);//üst siniftan sekil olustur

    //fonks gostericisi atamalari
    this->deleteSinek=&deleteSinek;
    
    return this;
}
void deleteSinek(const Sinek this){
    if(this==NULL) return;
    this->super->deleteCanli(this->super);//önce sekili sil
    free(this);// sonra daireyi sil
}