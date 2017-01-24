#include "listas.h"

/*Funcoes de lista encadeada*/

lista* lst_cria(lista* last, int i)  /*INSERE NO FIM*/
{
    lista* item= calloc(1, sizeof(lista));
    if(last!=NULL)
        last->prox=item;
    item->info= i;
    return item;
}

lista* lst_insere(lista *l, int i)  /*INSERE NO INÍCIO*/
{
    lista* item= calloc(1, sizeof(lista));
    item->prox= l;
    item->info= i;
    return item;
}

void lst_imprime(lista *l)
{
    int cont=1;
    lista* next=l;
    printf("Imprimindo a lista: \n");
    for(next=l; next!= NULL; next= next->prox)
    {
        printf("\t %d-->%d \n", cont, next->info);
        cont++;
    }
}

int lst_vazia(lista *l)
{
    if(l == NULL)
        return 1 ;
    else return 0 ;
}

lista* lst_busca(lista *l, int v)
{
    lista* next;
    for(next=l; next!= NULL; next= next->prox)
    {
        if(next->info==v)
            return next;
    }
    return NULL;
}

lista* lst_retira(lista *l, int v)
{
    lista* last=NULL;
    lista* next=l;
    while(next->prox!= NULL && v!=next->info)
    {
        last=next;
        next=next->prox;
    }
    if(next==NULL)
    {
        return l;
    }
    if(last==NULL)
    {
        next=next->prox;
        free(l);
        return next;
    }
    last->prox=next->prox;
    free(next);
    return l;
}

void lst_libera(lista *l)
{
}

lista *lst_insere_ordenado(lista *l, int v) {}

int lst_igual(lista *l1, lista *l2) {}

/*listas circulares*/
void lcirc_imprime(lista *l) {}

/*listas duplamente encadeadas*/
lista2 *lst2_insere(lista2 *l, int v) {}

lista2 *lst2_busca(lista2 *l, int v) {}

lista2 *lst2_retira(lista2 *l, int v) {}
