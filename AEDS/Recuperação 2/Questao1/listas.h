#include <stdio.h>
#include <stdlib.h>

/*definindo lista encadeada*/
typedef struct lista_encadeada{
	int info;
	struct lista* prox;
}lista;


/*definindo lista duplamente encadeada*/
typedef struct Lista2{
	int info;
	struct lista2 *ant;
	struct lista2 *prox;
}lista2;

/*Funcoes de lista encadeada*/

lista* lst_cria(lista* last, int i);

lista* lst_insere(lista *l, int i);

void lst_imprime(lista *l);

int lst_vazia(lista *l);

lista* lst_busca(lista *l, int v);

lista *lst_retira(lista *l, int v);

void lst_libera(lista *l);

lista *lst_insere_ordenado(lista *l, int v);

int lst_igual(lista *l1, lista *l2);

/*listas circulares*/
void lcirc_imprime(lista *l);

/*listas duplamente encadeadas*/
lista2 *lst2_insere(lista2 *l, int v);

lista2 *lst2_busca(lista2 *l, int v);

lista2 *lst2_retira(lista2 *l, int v);
