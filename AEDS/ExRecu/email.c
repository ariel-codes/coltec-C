#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListaPilha
{
    char symbol;
    struct ListaPilha* bottom;
} lista;

typedef struct lista
{
    int value;
    struct lista* prox;
} Lista;

typedef struct Pilha
{
    lista* top;
} pilha;

pilha insere(pilha pile, char symbol)
{
    lista* novo= (lista*) malloc(sizeof(lista));
    novo->symbol=symbol;
    novo->bottom= pile.top;
    pile.top=novo;
    return pile;
}

pilha pop(pilha pile)
{
    lista* old= pile.top;
    if(pile.top==NULL)
        return pile;
    pile.top=pile.top->bottom;
    free(old);
    return pile;
}

int pairer(pilha whole, char* frase)
{
    static int i=0;
    if(frase[i]==40 || frase[i]==91 || frase[i]==123)
    {
        whole=insere(whole, frase[i]);
        i++;
        return pairer(whole, frase);
    }
    else if(frase[i]==41 || frase[i]==93 || frase[i]==125)
    {
        if((frase[i]==41 && whole.top->symbol==40) || (frase[i]==93 && whole.top->symbol==91) || (frase[i]==125 && whole.top->symbol==40))
        {
            whole=pop(whole);
            i++;
            return pairer(whole, frase);
        }
        else return 0;
    }
    else if(frase[i]=='\0')
        return whole.top==NULL;
    i++;
    return pairer(whole, frase);
}

void the_closer()
{
    int tam;
    pilha pairs;
    pairs.top=(lista*) NULL;
    printf("Qual o tamanho da sua frase?");
    scanf("%d", &tam);
    getchar();
    char* frase= (char*) malloc(tam*sizeof(char));
    printf("Agr a frase:");
    fgets(frase, tam, stdin);
    if(pairer(pairs, frase))
        printf("String balaceada");
    else printf("String desbalanceada");
    while(pairs.top!=NULL)
        pairs=pop(pairs);
    free(frase);
}

Lista* separa (Lista* l, int n)
{
    while(l->value!=n)
    {
        l=l->prox;
        if(l->prox==NULL)
            return NULL;
    }
    Lista* swap=l->prox;
    l->prox=NULL;
    return swap;
}

void print_l(Lista* obj, char txt[])
{
    printf("\n\t%s ", txt);
    while(obj!=NULL)
    {
        printf("--> %d", obj->value);
        obj=obj->prox;
    }
}

Lista* l_insere(Lista* old)
{
    Lista* nova=(Lista*) malloc(sizeof(lista));
    printf("Novo valor: ");
    scanf("%d", &nova->value);
    nova->prox=old;
    return nova;
}

void free_l(Lista* l)
{
    Lista* swap;
    while(l!=NULL)
    {
        swap=l;
        l=swap->prox;
        free(swap);
    }
}

void um()
{
    short i, j;
    int sep;
    Lista* numbers=(Lista*) NULL;
    printf("\nInsira o tamanho da lista e o valor do separador: ");
    scanf("%hi %d", &i, &sep);
    for(j=0; j<i; j++)
        numbers=l_insere(numbers);
    Lista* div=separa(numbers, sep);
    print_l(numbers, "Lista Original:");
    if(div!=NULL)
    {
        print_l(div, "Lista Nova:");
        free_l(div);
    }
    free_l(numbers);
}

int main()
{
    short opt;
start:
    printf("\nEscolha o exercício:");
    scanf("%hi", &opt);
    switch(opt)
    {
    case 0:
        return 0;
    case 1:
        um();
        break;
    case 2:
        the_closer();
    }
    goto start;
    return 0;
}
