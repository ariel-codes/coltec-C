#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "listas.h"

int main()
{
	int opt;
    printf("Escolha o exercício:\n");
    scanf("%d", &opt);
    switch(opt){
    }
    return 0;
}

void lst_imprime_rec(lista* l){
	printf("\t %d", l->info);
	if(l->prox!=NULL)
		lst_imprime_rec(l->prox);
}

lista* lst_retira_rec(lista* l, int v){
	if(l->prox==NULL)
		return NULL;
	if(l->prox->info==v){
		l->prox=l->prox->prox;
		free(l->prox);
		return NULL;
	}
	if(l->info==v){
		free(l);
		return NULL;
	}
	else lst_retira_rec(l->prox, v);
}
