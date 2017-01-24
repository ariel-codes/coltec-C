#include <math.h>
#define N 50

typedef struct pilha
{
    int n;
    int vet[N];
} Pilha;

typedef struct pilha_encadeada
{
    float info;
    struct pilha_encadeada* prev;
}lista_p;

typedef struct pilha_lista
{
    lista_p* top;
}Pilha_enc;


Pilha *pilha_cria();

void pilha_push(Pilha *p, int v);

int pilha_pop(Pilha *p);

int pilha_vazia(Pilha *p);

void pilha_libera(Pilha *p);

void pilha_imprime(Pilha *p);

int pilha_enc_vazia(Pilha_enc* pile);

Pilha_enc* pilha_enc_cria();

void pilha_enc_push(Pilha_enc* pile, float v);

float pilha_enc_pop(Pilha_enc* pile);

void pilha_enc_libera(Pilha_enc* pile);

void pilha_enc_imprime(Pilha_enc* pile);
