#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore_binaria{
	char* info;
	struct arvore_binaria* left;
	struct arvore_binaria* right;
} arv_bin;

typedef struct arvore_var{
	char* label;
	struct arvore_var* prim;
	struct arvore_var* prox;
} arv_var;

//ÁRVORES BINÁRIAS
arv_bin* bin_cria(char* label);

void bin_print(arv_bin* top);

arv_bin* bin_libera(arv_bin* node);

int bin_pertence(arv_bin* node, char* label);

///static int max2(int a, int b);

int bin_altura(arv_bin* node);

//ÁRVORES VARIAVEIS
arv_var* var_cria(char* label);

void var_insere(arv_var* root, arv_var* node);

void var_print(arv_var* tree);

int var_pertence(arv_var* a, char* c);

void var_libera(arv_var* a);
