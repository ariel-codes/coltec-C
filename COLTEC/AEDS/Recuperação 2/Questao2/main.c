#include <stdio.h>
#include <stdlib.h>
//#include "pilha.h"
#include <string.h>

typedef struct ListaPilha
{
    char symbol;
    struct ListaPilha* bottom;
} lista;

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
    static int c=0;
    if((frase[i]=='A' || frase[i]=='B')&&(!c)){
		whole=insere(whole, frase[i]);
        i++;
        return pairer(whole, frase);
    }
    else if ((frase[i]=='A' || frase[i]=='B')&&(c)){
		if((frase[i]=='A' && whole.top->symbol=='B') || (frase[i]=='B' && whole.top->symbol=='A')){
			whole=pop(whole);
            i++;
            return pairer(whole, frase);
		}
		else return 0;
    }
    else if(frase[i]=='C')
        c=1;
    else if(frase[i]=='\0')
        return whole.top==NULL;
    i++;
    return pairer(whole, frase);
}

int main()
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
    if(pairer(pairs,frase))
		printf("String formatada");
	else printf("String não formatada");
	while(pairs.top!=NULL)
        pairs=pop(pairs);
    free(frase);
    return 0;
}
