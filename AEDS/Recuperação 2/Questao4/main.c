#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

lista* lst_intercala(lista* l1, lista* l2){
	int i;
    lista* l3=(lista*) malloc(sizeof(lista));
    for(i=1;l1!=NULL && l2!=NULL; i++){
		if(i%2==1){
            l3=lst_insere(l3, l1->info);
            l1=l1->prox;
		}
		else {
			l3=lst_insere(l3, l2->info);
			l2=l2->prox;
		}
    }
    if(l1!=NULL && l2==NULL){
        while(l1!=NULL){
			l3=lst_insere(l3, l1->info);
			l1=l1->prox;
		}
    }
    else if(l1==NULL && l2!=NULL){
		while(l2!=NULL){
			l3=lst_insere(l3, l2->info);
			l2=l2->prox;
		}
    }
    return l3;
}

int main()
{
	lista* l1=NULL;
	lista* l2=NULL;
	int i;
    for(i=0; i<5; i++){
		l1=lst_insere(l1, 10);
		l2=lst_insere(l2, 1);
    }
    lista* l3= NULL;
    l3=lst_intercala(l1, l2);
    printf("\t\nLista1:");
    lst_imprime(l1);
    printf("\t\nLista2:");
    lst_imprime(l2);
    printf("\t\nLista3:");
    lst_imprime(l3);
    lst_libera(l3);
    lst_libera(l2);
    lst_libera(l1);
    return 0;
}
