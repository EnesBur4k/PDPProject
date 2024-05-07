#include "Canli.h"

Canli new_Canli(int can){
    Canli this;
    this=(Canli)malloc(sizeof(struct CANLI));
    printf("canli olustu \n");

    this->can = can;

    //fonksiyon gosterici ataması
    this->gorunum=&gorunum;
    this->delete_Canli=&delete_Canli;

    return this;
}
void delete_Canli(const Canli this){
    if(this==NULL) return;
    free(this->gorunum);
    free(this);
    printf("canli silindi \n");
}
char* gorunum(const Canli this){
    char* str = (char*)malloc(sizeof(char)*20); 
    sprintf(str,"can: %d \n",this->can);
    return str;
}