#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define N 100

struct Fila{
	int n;
	int ini;
	float vet[N];
};

struct Lista{
	char info[20];
	struct lista *prox;
};

struct Filal{
	lista *ini;
	lista *fim;
};

static int incr(int i){
	return (i+1)%N;
}

fila *fila_cria_vet(){
	fila *f = (fila *) malloc(sizeof(fila));
	f->n = 0;
	f->ini = 0;
	return f;
}

void fila_insere_vet(fila *f, float v){
	int fim;
	if(f->n == N){
		printf("Capacidade da fila estourou\n");
		exit(1);
	}
	fim = (f->ini + f->n)%N;
	f->vet[fim] = v;
	f->n++;
}

float fila_retira_vet(fila *f){
	float v;
	if(fila_vazia_vet(f)){
		printf("fila vazia!\n");
		exit(1);
	}
	v=f->vet[f->ini];
	f->ini = (f->ini + 1) % N;
	f->n--;
	return v;
}

int fila_vazia_vet(fila *f){
	return (f->n == 0);
}

void fila_libera_vet(fila *f){
	free(f);
}


// lista encadeada
fila_l *fila_cria_l(){
	fila_l *f = (fila_l *) malloc(sizeof(fila_l));
	f->ini = f->fim = NULL;
	return f;
}

void fila_insere_l(fila_l *f,char *v){
	lista *n = (lista *) malloc(sizeof(lista));
	int i;
	for(i=0;i<20;i++) n->info[i]=v[i];
	n->prox = NULL;
	if(f->fim != NULL) f->fim->prox = n;
	else f->ini = n;
	f->fim = n;
}

char *fila_retira_l(fila_l *f){
	lista *t;
	char *v;
	if(fila_vazia_l(f)){
		printf("fila vazia!");
		exit(1);
	}
	t = f->ini;
	v = t->info;
	f->ini = t->prox;
	if(f->ini==NULL) f->fim = NULL;
	free(t);
	return v;
}

int fila_vazia_l(fila_l *f){
	return (f->ini == NULL);
}

void fila_libera_l(fila_l *f){
	lista *q = f->ini;
	while(q!=NULL){
		lista *t = q->prox;
		free(q);
		q = t;
	}
	free(f);
}

// Funções de impressão

void fila_imprime_vet(fila *f){
	int i;
	for(i=0;i<f->n; i++) printf("%f \n", f->vet[(f->ini+i)%N]);
}

void fila_imprime_l(fila_l *f){
	lista *q;
	for(q=f->ini; q!= NULL; q=q->prox) printf("%s",q->info);
}

char *fila_ultimo_l(fila_l *f){
	lista *t;
	char *v;
	if(fila_vazia_l(f)){
		printf("fila vazia!");
		exit(1);
	}
	t = f->ini;
	v = t->info;
	return v;
}
