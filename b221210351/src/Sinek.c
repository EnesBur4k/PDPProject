#include "Sinek.h"

//Bitki olustur
Sinek new_Sinek(int can){
    Sinek this;
    this=(Sinek)malloc(sizeof(struct SINEK));

    this->super=new_Canli(can);//üst siniftan sekil olustur

    //fonks gostericisi atamalari
    this->delete_Sinek=&delete_Sinek;
    
    return this;
}
void delete_Sinek(const Sinek this){
    if(this==NULL) return;
    this->super->delete_Canli(this->super);//önce sekili sil
    free(this);// sonra daireyi sil
}