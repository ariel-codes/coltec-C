#include "listas.h"

int main(){
    lista* teste= lst_cria(NULL, 20);
    josephus(5);
	return 0;
}

lista* lst_circle(int items){
    int i;
    lista* l=lst_insere(NULL, items);
    lista* last=l;
    l->info=items;
    for(i=items-1; i>0; i--){
        l=lst_insere(l, i);
    }
    l->prox=last;
    return l;
}

int josephus(int pessoas){
    int cont;
    lista* rodinha= lst_circle(pessoas);
    //lst_imprime(rodinha);
    return cont;
}
