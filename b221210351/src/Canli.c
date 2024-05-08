#include "Canli.h"

Canli newCanli(int can, char* sinif){
    Canli this;
    this=(Canli)malloc(sizeof(struct CANLI));

    this->sinif = sinif;
    this->can = can;

    //fonksiyon gosterici ataması
    this->gorunum=&gorunum;
    this->deleteCanli=&deleteCanli;

    return this;
}

void deleteCanli(const Canli this){
    if(this==NULL) return;
    free(this->gorunum);
    free(this);
    printf("canli silindi \n");
}
char* gorunum(const Canli this){
    char* str = (char*)malloc(sizeof(char)*20);
    if(this->can == 0){
        sprintf(str,"%s ","X");
    }
    else if(this->can < 10){
        sprintf(str,"%s ","B");
    }
    else if(this->can < 21){
        sprintf(str,"%s ","C");
    }
    else if(this->can < 51){
        sprintf(str,"%s ","S");
    }
    else if(this->can < 100){
        sprintf(str,"%s ","P");
    }
    return str;
}