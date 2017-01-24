#include "listas.h"

/*Funcoes de lista encadeada*/

lista* lst_cria(lista* last, int i)  /*INSERE NO FIM*/
{
    lista* item=(lista*) malloc(sizeof(lista));
    if(last!=NULL)
        last->prox=item;
    item->info= i;
    return item;
}

lista* lst_insere(lista *l, int i)  /*INSERE NO INÍCIO*/
{
    lista* item= malloc(sizeof(lista));
    item->prox= l;
    item->info= i;
    return item;
}

void lst_imprime(lista *l)
{
    int cont=1;
    lista* next=l;
    printf("Imprimindo a lista: \n");
    for(; next!= NULL; next= next->prox)
    {
        if(next->info==0)
            break;
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
    lista* p=l;
    while(p!=NULL)
    {
        lista* t = p->prox;
        free(p);
        p=t;
    }
}

lista *lst_insere_ordenado(lista *l, int v) ///INSERE LOGO APÓS 'V'
{
    lista* novo;
    lista* ant=NULL;
    lista* p=l;
    while(p!=NULL && (p->info)> v)
    {
        ant=p;
        p=p->prox;
    }
    novo=(lista*) malloc(sizeof(lista));
    novo->info=v;
    if(ant==NULL)
    {
        novo->prox=l;
        l=novo;
    }
    else
    {
        novo->prox=ant->prox;
        ant->prox=novo;
    }
    return l;
}

int lst_igual(lista *l1, lista *l2)
{
    lista* temp1=l1;
    lista* temp2=l2;
    while(temp1->prox!=NULL && temp2->prox!=NULL)
    {
        if(temp1->info!=temp2->info)
            return 0;
        temp1=temp1->prox;
        temp2=temp2->prox;
    }
    if((temp1->prox==NULL && temp2->prox!=NULL) || (temp1->prox!=NULL && temp2->prox==NULL))
        return 0;
    else return 1;
}

/*listas circulares*/
void lcirc_imprime(lista *l)
{
    lista* temp=l;
    do
    {
        printf("\t %d", temp->info);
        temp=temp->prox;
    }
    while(temp!=l);
}

/*listas duplamente encadeadas*/
lista2* lst2_cria(lista2* l, int v) ///INSERE NO FIM
{
    lista2* novo=(lista2*) malloc(sizeof(lista2));
    l->prox=novo;
    novo->ant=l;
    novo->prox=NULL;
    novo->info=v;
    return novo;
}

lista2* lst2_insere(lista2 *l, int v) ///INSERE NO INICIO
{
    lista2* item= malloc(sizeof(lista2));
    item->prox= l;
    item->info= v;
    item->ant= NULL;
    if(l!=NULL)
        l->ant=item;
    return item;
}

lista2* lst2_busca(lista2 *l, int v) {
    lista2* next;
    for(next=l; next!= NULL; next= next->prox)
    {
        if(next->info==v)
            return next;
    }
    return NULL;
}

lista2* lst2_retira(lista2 *l, int v) {
    lista2* p=lst2_busca(l,v);
    lista2* ant=p->ant;
    lista2* prox=p->prox;
    if (p==NULL)
        return l;
    if(l==p)
        l=p->prox;
    else
        ant->prox= p->prox;
    if(p->prox!=NULL)
        prox->ant=p->ant;
    free(p);
    return l;
}
