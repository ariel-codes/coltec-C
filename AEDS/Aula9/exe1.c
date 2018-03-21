#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct carro_fila
{
    char placa[7];
    int idade;
    struct carro_fila* prox;
} carro;

typedef struct fila_garagem
{
    carro* prim;
    carro* ult;
} f_garagem;

f_garagem* garagem=NULL;

void estacionar()
{
  char placa[7];
  int idade;
  carro* novo= (carro*) malloc(sizeof(carro));
  printf("Insira a placa e a idade: ");
  clear();
  getchar();
  fgets(novo->placa, 7, stdin);
  clear();
  scanf("%d", &novo->idade);
  if(garagem->prim== NULL && garagem->ult== NULL)
    garagem->prim=garagem->ult=novo;
  else if(novo->idade<65 || garagem->ult->idade > novo->idade)
  {
    printf("Normal\n");
    garagem->ult->prox=novo;
    garagem->ult=novo;
    novo->prox=NULL;
  }
  else{
    printf("Fila Prioritária!\n");
    carro* temp=garagem->prim;
    carro* prev;
    while(novo->idade < temp->idade)
    {
      prev=temp;
      temp=temp->prox;
    }
    if(garagem->prim->idade < novo->idade)
    {
      printf("Primeirão da fila\n");
      novo->prox=temp;
      garagem->prim=novo;
    }
    else
    {
      printf("Prioritário comum\n");
      novo->prox=temp;
      prev->prox=novo;
    }
  }
}

int existe(char id[7])
{
    carro* swap=garagem->prim;
    while(swap!=NULL)
    {
        if(!strcmp(swap->placa, id))
            return 1;
        swap=swap->prox;
    }
    return 0;
}

void retirar()
{
    char saindo[7];
    carro* out;
    printf("Insira a placa a ser retirada:");
    clear();
    getchar();
    fgets(saindo, 7, stdin);
    if(existe(saindo))
    {
        while(strcmp(garagem->prim->placa, saindo))
        {
            garagem->ult->prox=garagem->prim;
            garagem->prim=garagem->prim->prox;
        }
        out=garagem->prim;
        garagem->prim=garagem->prim->prox;
        free(out);
    }
}

void imprime()
{
    carro* print=garagem->prim;
    FILE* arquivo= fopen("garagem", "w");
    while(print!=NULL)
    {
        fprintf(arquivo,"-->CARRO (%d):%s", print->idade, print->placa);
        fflush(arquivo);
        print=print->prox;
    }
    fclose(arquivo);
}

void clear (void)
{
    fflush(stdout);
    fflush(stdin);
}

int main()
{
    garagem=(f_garagem*) malloc(sizeof(f_garagem));
    garagem->prim=garagem->ult=NULL;
    int op=4;
    while(op)
    {
        printf("O quê você quer fazer? (+placa do carro de 6 dígitos) \n\t 1 -> estacionar \n\t 2 -> retirar \n\t 3 -> listar \n\t 0 -> sair \n");
        clear();
        scanf("%d", &op);
        clear();
        switch(op)
        {
        case 0:
            break;
        case 1:
            estacionar();
            break;
        case 2:
            retirar();
            break;
        case 3:
            imprime();
        }
    }
    carro* swap;
    while(garagem->prim!=NULL)
    {
        swap=garagem->prim;
        garagem->prim=garagem->prim->prox;
        free(swap);
    }
    free(garagem);
    return 0;
}
